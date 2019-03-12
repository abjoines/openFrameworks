#include "ofApp.h"
ofVec2f tri, mid, cur, cur2;
int num;
float angle;
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
    ofSetCircleResolution(60);
    ofSetFrameRate(60);
    num = 24;
    
    mid = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
    tri = ofVec2f(ofGetWidth()/3, ofGetHeight() / 2);
    cur = mid;
    cur2 = tri;


	gui.setup("panel");
    gui.add(mad.setup("mad"));
	gui.add(radius.set( "surprise", 60, 60, 200 ));
    gui.add(jump.set( "excited", 0, 0, 100));
	
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::white, ofColor::gray);

    ofSetColor(0);
    if( mad ){
        ofSetColor(255,0,0);
        ofBackgroundGradient(ofColor::black, ofColor::red);
    }else{
        ofSetColor(0);
        ofBackgroundGradient(ofColor::white, ofColor::gray);
    }
    //body
    ofDrawRectRounded(cur.x-50,cur.y - jump, 100, 330, 10);
    //feet
    ofDrawRectRounded(cur.x+10,cur.y+320 - jump, 100, 25, 10);
    ofDrawRectRounded(cur.x-110,cur.y+320 - jump, 100, 25, 10);
    //head
    ofDrawEllipse(cur.x, cur.y - jump, 475, 350);
    //eyes
    ofDrawCircle(cur2.x, cur2.y - jump, 130);
    ofDrawCircle(cur2.x*2, cur2.y - jump, 130);
    for (int i = 0; i < num; i++){
        if (i%2==0){
            ofSetColor(255);
        } else {
            ofSetColor(0);
        }
        
        angle = i * TWO_PI / num;
        float x = (cur2.x) + 50 * cos(angle);
        float x2 = (cur2.x*2) + 50 * cos(angle);
        float y = (cur2.y) + 50 * sin(angle);
        ofDrawCircle(x , y - jump, radius);
        ofDrawCircle(x2 , y - jump, radius);
    }
    if ( mad){
        ofDrawCircle(cur2, 120);
        ofDrawCircle(cur2.x*2, cur2.y, 120);
        ofSetColor(255,0,0);
        ofDrawEllipse(cur2, 100, 10);
        ofDrawEllipse(cur2.x*2, cur2.y, 100, 10);
    }
	
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	
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
