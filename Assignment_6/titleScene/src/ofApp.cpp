#include "ofApp.h"
// Track mouse with fade

ofFbo fbo;  // framebuffer object
float r, xPos, yPos, inc;
float midX, midY;
ofPoint myMouse;
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F); // higher precision alpha (no artifacts)
    
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
    ofSetBackgroundColor(2, 35, 68);
    
    midX = ofGetWidth()/2;
    midY = ofGetHeight()/2;
}
bool splash = false;
bool fade = false;
//--------------------------------------------------------------
void ofApp::update(){

    xPos = ofRandom(ofGetWidth());
    yPos = ofRandom(ofGetHeight());
    
    inc += 1;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
//fbo start
    fbo.begin();
    ofSetColor(4, 48, 94, 5);
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    
    if (fade == true){
        ofSetColor(255,255,255);
        ofDrawBitmapString("Raindrops", 100, 100);
    }
    
    ofSetColor(94, 159, 224);
    ofNoFill();
    r = ofRandom(40);
    ofDrawCircle(xPos,yPos,r);
    ofDrawCircle(myMouse, 50);
    
    ofFill();
    fbo.end();
    ofSetColor(255,255,255);
    fbo.draw(0,0);
//fbo end
    if (fade == false){
    ofDrawBitmapString("Raindrops", 100, 100);
    }
    if (splash == true){
        ofSetColor(94, 159, 224);
        ofDrawCircle(midX-250, ofGetHeight() - 145, 25 + inc);
        ofDrawCircle(midX+250, ofGetHeight() - 145, 25 + inc);
    }
    ofSetColor(0,0,0);
    ofDrawRectRounded(midX-400, ofGetHeight() - 190, 300, 250, 30);
    ofDrawRectRounded(midX+100, ofGetHeight() - 190, 300, 250, 30);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f') {
        fade = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    myMouse.x = x;
    myMouse.y = y;
    splash = false;
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    splash = true;
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
