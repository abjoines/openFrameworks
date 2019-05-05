#include "ofApp.h"
#include <iostream>
#include <stdio.h>

ofFbo fbo;
int degStep, scene, radar, state, deaths;
long sec;
float mouseX, mouseY;

const int numParticles = 1;
particle myParticle[numParticles];

int particle::getX() {
    return (pos.x);
}
int particle::getY(){
    return (pos.y);
}

float particle::getMouseX(){
    return (mouseX);
}
float particle::getMouseY(){
    return (mouseY);
}

particle::particle(){
    
}

void particle::update(){
    if(!alive)
        return;
    
    time = ofGetFrameNum()/60;
    lifetime = time % 10;
    
    //wall collisions
    if (pos.x > ofGetWidth()){
        pos.x = ofGetWidth();
        vel.x *= -1;
    }
    
    if (pos.x < 0){
        pos.x = 0;
        vel.x *= -1;
    }
    
    if (pos.y > ofGetHeight()){
        pos.y = ofGetHeight();
        vel.y*=-1;
    }
    
    if (pos.y < 0){
        pos.y=0;
        vel.y *= -1;
    }
    
    if ((pos.x > (ofGetMouseX()-60) && pos.x < (ofGetMouseX()+60)) && (pos.y > (ofGetMouseY()-60) && pos.y < (ofGetMouseY()+60))){
        alive = false; //kill self if moused over
        deaths +=1;
    }
    
}

void particle::draw(){
    if (alive){
        ofSetLineWidth(3);
        ofSetColor(216, 71, 151);
        ofNoFill();
        ofPushMatrix();
        ofTranslate(pos.x, pos.y);
        ofRotateDeg(degStep);
        ofDrawTriangle(20, 20, 30, 40, 10, 40);
        ofPopMatrix();
    }
    
}

//--------------------------------------------------------------
void ofApp::setup(){
    myFont.load("Syncopate-Bold.ttf", 30);
    myFontSmall.load("Syncopate-Bold.ttf", 18);
    myFontXSmall.load("Syncopate-Bold.ttf", 10);
    myFontBig.load("Syncopate-Bold.ttf", 60);
    
    ofSetCircleResolution(60);
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F); // higher precision alpha (no artifacts)
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    deaths = 0;
    degStep = 0;
    radar = 0;
    state = 0;
}
//--------------------------------------------------------------
void ofApp::update(){
    sec = ofGetFrameNum()/60;
    
    degStep+=1.5;
    
    if (state == 1){
    radar += 3;
    degStep+=3;
        
        for(int i=0; i < numParticles; i++){
            if(myParticle[i].alive == false){
                myParticle[i].alive = true;
                myParticle[i].pos = ofPoint(ofRandom(50,ofGetWidth()-50),ofRandom(100,ofGetHeight()-100));
                return;
            }
        }
        
        for (int i = 0; i < numParticles; i++){
            myParticle[i].update();
        }
        
        if (radar>=ofGetWidth()){
            radar=0;
        }
        
        if (sec>30){
            state += 1;
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//TITLE STATE
    if (state==0) {
        
        //background
        ofSetLineWidth(5);
        ofSetColor(66, 235, 244);
        
        ofDrawGridPlane(50, 40);
        
        ofPushMatrix();
        ofTranslate(ofGetWidth(),0);
        ofDrawGridPlane(50, 40);
        ofPopMatrix();
        
        //triangles
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, 400);
        ofRotateDeg(-degStep);
        ofNoFill();
        ofSetColor(216, 71, 151);
        ofDrawTriangle(100, 100, 150, 200, 50, 200);
        ofFill();
        ofSetColor(216, 71, 151, 75);
        ofDrawTriangle(100, 100, 150, 200, 50, 200);
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, 400);
        ofRotateDeg(degStep);
        ofNoFill();
        ofSetColor(216, 71, 151);
        ofDrawTriangle(100, 100, 150, 200, 50, 200);
        ofFill();
        ofSetColor(216, 71, 151, 75);
        ofDrawTriangle(100, 100, 150, 200, 50, 200);
        ofPopMatrix();
        
        //text
        ofSetColor(255);
        string enter = "BEGIN";
        string instructions = "Collect triangles.";
        myFont.drawString(enter, ofGetWidth()/2-80, ofGetHeight()/2+40);
        myFontSmall.drawString(instructions, ofGetWidth()/2-175, 50);
        myFontXSmall.drawString("SPACEBAR to", ofGetWidth()/2-60, ofGetHeight()/2);
        
    }
    
//GAME STATE
    if (state==1) {
        ofSetLineWidth(5);
        
        ofPushMatrix();
        ofSetColor(66, 235, 244, 95);
        ofTranslate(radar,0);
        ofDrawGridPlane(50, 40);
        ofPopMatrix();
        
        ofSetColor(66, 235, 244);
        
        fbo.begin();
        ofSetColor(0,0,0, 20); // background color with alpha
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        
        ofNoFill();
        ofSetLineWidth(3);
        ofSetColor(216, 71, 151);
        
        for (int i=0; i <numParticles; i++){
            myParticle[i].draw();
        }
        
    //PLAYER CIRCLE
        ofFill();
        ofSetColor(66, 235, 244, 75);
        ofDrawCircle(mouseX, mouseY, 60);
        ofNoFill();
        ofSetLineWidth(5);
        ofSetColor(66, 235, 244);
        ofDrawCircle(mouseX, mouseY, 60);
        
        string seconds = ofToString(30 - sec);
        myFontSmall.drawString("TIME REMAINING: " + seconds, ofGetWidth()/2-175, 50);
        
        string score = ofToString(deaths);
        myFontSmall.drawString("CURRENT SCORE: " + score, ofGetWidth()/2-170, ofGetHeight()-30);
        
        ofFill();
        fbo.end();
        ofSetColor(255, 255, 255);
        fbo.draw(0,0);
        
        
    }
    
//END STATE
    if (state==2) {
        //background
        ofSetLineWidth(5);
        ofSetColor(66, 235, 244);
        
        ofDrawGridPlane(50, 40);
        
        ofPushMatrix();
        ofTranslate(ofGetWidth(),0);
        ofDrawGridPlane(50, 40);
        ofPopMatrix();
        
        //triangles
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, 400);
        ofRotateDeg(-degStep);
        ofNoFill();
        ofSetColor(216, 71, 151);
        ofDrawTriangle(100, 100, 150, 200, 50, 200);
        ofFill();
        ofSetColor(216, 71, 151, 75);
        ofDrawTriangle(100, 100, 150, 200, 50, 200);
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2, 400);
        ofRotateDeg(degStep);
        ofNoFill();
        ofSetColor(216, 71, 151);
        ofDrawTriangle(100, 100, 150, 200, 50, 200);
        ofFill();
        ofSetColor(216, 71, 151, 75);
        ofDrawTriangle(100, 100, 150, 200, 50, 200);
        ofPopMatrix();
        
        ofSetColor(255);
        string enter = "PLAY AGAIN";
        string instructions = "game over";
        myFont.drawString(enter, ofGetWidth()/2-165, ofGetHeight()/2+40);
        myFontSmall.drawString(instructions, ofGetWidth()/2-100, 50);
        myFontXSmall.drawString("SPACEBAR to", ofGetWidth()/2-60, ofGetHeight()/2);
        
        string score = ofToString(deaths);
        myFont.drawString("FINAL SCORE: ", ofGetWidth()/2-175, 100);
        myFontBig.drawString(score, ofGetWidth()/2-70, 200);
    
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ' && state < 1){
        state += 1;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    mouseX = x;
    mouseY = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
