#include "ofApp.h"

int triX, midX, midY, num;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(152, 175, 206);
    ofSetFrameRate(60);
    midX = ofGetWidth()/2;
    triX = ofGetWidth()/3;
    midY = ofGetHeight()/2;
    num = 24;
}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
//background
    ofSetColor(230);
    ofDrawRectangle(0, ofGetHeight()-200, ofGetWidth(), 200);

//puddle
    if (ofGetFrameNum()<120){
    ofSetColor(66, 143, 244);
    ofDrawEllipse(midX, ofGetHeight()-50, ofGetWidth()-400, 100);
    ofSetColor(44, 95, 163);
    ofDrawEllipse(midX-60,midY+340,150,45);
    ofDrawEllipse(midX+60,midY+340,150,45);
    }
//rain??
    
//character 1
    if (ofGetFrameNum()>120 && ofGetFrameNum()<240){
    ofSetColor(0);
    //body
    ofDrawRectRounded(midX-50,midY, 100, 330, 10);
    //feet
    ofDrawRectRounded(midX+10,midY+320, 100, 25, 10);
    ofDrawRectRounded(midX-110,midY+320, 100, 25, 10);
    //head
    ofDrawEllipse(midX,midY, 475, 350);
    //eyes
    ofDrawCircle(triX, midY, 130);
    ofDrawCircle(triX*2, midY, 130);
    for (int i = 0; i < num; i++){
        if (i%2==0){
            ofSetColor(255);
        } else {
            ofSetColor(0);
        }
        
        float angle = i * TWO_PI / num;
        float x = triX + 50 * cos(angle);
        float x2 = (triX*2) + 50 * cos(angle);
        float y = midY + 50 * sin(angle);
        ofDrawCircle(x , y, 60);
        ofDrawCircle(x2 , y, 60);
    }
    }
//character 2
    if (ofGetFrameNum()>240 && ofGetFrameNum()<360){
    ofSetColor(46, 186, 100);
    //body
    ofDrawRectRounded(midX-50,midY, 100, 330, 10);
    //feet
    ofDrawRectRounded(midX+10,midY+320, 100, 25, 10);
    ofDrawRectRounded(midX-110,midY+320, 100, 25, 10);
    //head
    ofDrawEllipse(midX,midY, 475, 350);
    //eyes
    ofDrawCircle(triX, midY, 130);
    ofDrawCircle(triX*2, midY, 130);
    for (int i = 0; i < num; i++){
        if (i%2==0){
            ofSetColor(255);
        } else {
            ofSetColor(0);
        }

        float angle = i * TWO_PI / num;
        float x = triX + 50 * -cos(angle);
        float x2 = (triX*2) + 50 * -cos(angle);
        float y = midY + 50 * sin(angle);
        ofDrawCircle(x , y, 60);
        ofDrawCircle(x2 , y, 60);
    }
    }
//umbrella
    if(ofGetFrameNum()>360 && ofGetFrameNum()<480){
    ofSetColor(0);
    ofDrawRectRounded(midX-5, 200, 10, 400, 10);
    ofDrawTriangle(midX, 100, midX+400, 250, midX-400, 250);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
