#include "ofApp.h"
#include <iostream>
#include <stdio.h>

ofFbo fbo;
int degStep, scene, radar;
long sec;

//--------------------------------------------------------------
void ofApp::setup(){
    myFont.load("Syncopate-Bold.ttf", 30);
    myFontSmall.load("Syncopate-Bold.ttf", 18);
    myFontXSmall.load("Syncopate-Bold.ttf", 10);
    
    ofSetCircleResolution(60);
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F); // higher precision alpha (no artifacts)
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    degStep = 0;
    radar = 0;
}
bool startState = true;
bool gameState = false;
bool endState = false;
//--------------------------------------------------------------
void ofApp::update(){
    sec = ofGetFrameNum()/60;
    
    degStep+=1.5;
    radar += 3;
    
    if (radar>=ofGetWidth()){
        radar=0;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (startState) {
        
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
        myFontXSmall.drawString("click to", ofGetWidth()/2-40, ofGetHeight()/2);
        
    }
    
    if (gameState) {
        ofSetLineWidth(5);
        ofSetColor(66, 235, 244);
        
        ofPushMatrix();
        ofTranslate(radar,0);
        ofDrawGridPlane(50, 40);
        ofPopMatrix();
        
        fbo.begin();
        ofSetColor(0,0,0, 20); // background color with alpha
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        
        ofNoFill();
        ofSetLineWidth(3);
        ofSetColor(216, 71, 151);
    
    //TRIANGLES
        if (sec < 3){
        ofPushMatrix();
        ofTranslate(150, 150);
        ofRotateDeg(-degStep);
        ofDrawTriangle(20, 20, 30, 40, 10, 40);
        ofPopMatrix();
        }
        if (sec > 2 && sec < 6){
        ofPushMatrix();
        ofTranslate(200, 500);
        ofRotateDeg(degStep);
        ofDrawTriangle(20, 20, 30, 40, 10, 40);
        ofPopMatrix();
        }
        if (sec > 4 && sec < 8){
        ofPushMatrix();
        ofTranslate(600, 400);
        ofRotateDeg(-degStep);
        ofDrawTriangle(20, 20, 30, 40, 10, 40);
        ofPopMatrix();
        }
        if (sec > 6 && sec < 10){
        ofPushMatrix();
        ofTranslate(800, 200);
        ofRotateDeg(degStep);
        ofDrawTriangle(20, 20, 30, 40, 10, 40);
        ofPopMatrix();
        }
        
    //PLAYER CIRCLE
        ofFill();
        ofSetColor(66, 235, 244, 75);
        ofDrawCircle(mouseX, mouseY, 75);
        ofNoFill();
        ofSetLineWidth(5);
        ofSetColor(66, 235, 244);
        ofDrawCircle(mouseX, mouseY, 75);
        
        
        ofFill();
        fbo.end();
        ofSetColor(255, 255, 255);
        fbo.draw(0,0);
    }
    
    if (endState) {
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
        myFontXSmall.drawString("click to", ofGetWidth()/2-40, ofGetHeight()/2);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        gameState == true;
    }
    
    if (key == OF_KEY_RETURN){
        gameState == true;
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
