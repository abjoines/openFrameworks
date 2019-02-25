#include "ofApp.h"
int num, oval, dir, sec;
float angle, x;
ofVec2f tri, mid, cur, cur2, step, direction;
ofSoundPlayer drop;
//--------------------------------------------------------------
void ofApp::setup(){
    drop.load("waterDrop.mov");
    
    ofSetFrameRate(60);
    num = 24;
    
    mid = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
    tri = ofVec2f(ofGetWidth()/3, ofGetHeight() / 2);
    oval = 60;
    step = ofVec2f(0,3);  // run once with x = 0 then change it
    direction = ofVec2f(0.5,0.5);
    cur = mid;
    cur2 = tri;
    
}

//--------------------------------------------------------------
const int maxDistance = 25;
void ofApp::update(){
    sec = (ofGetFrameNum() / 60) % 60;
    
    if (sec % 2 == 0){
        x+=1.5;
        drop.play();
    }
    if (sec % 2 == 1){
        x-=1.5;
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    //body
    ofDrawRectRounded(cur.x-50,cur.y, 100, 330, 10);
    //feet
    ofDrawRectRounded(cur.x+10,cur.y+320, 100, 25, 10);
    ofDrawRectRounded(cur.x-110,cur.y+320, 100, 25, 10);
    //head
    ofDrawEllipse(cur, 475, 350);
    //eyes
    ofDrawCircle(cur2, 130);
    ofDrawCircle(cur2.x*2, cur2.y, 130);
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
        ofDrawCircle(x , y, oval);
        ofDrawCircle(x2 , y, oval);
    }
    
    ofPolyline fourPoint;
    fourPoint.addVertex((ofGetWidth()/2)-50+x,475);
    fourPoint.addVertex(ofGetWidth()/2,450);
    fourPoint.addVertex((ofGetWidth()/2)+50,475);
    fourPoint.addVertex(ofGetWidth()/2,500);
    
    fourPoint.close();  // Connect first and last vertices
    
    ofSetLineWidth(2.0);  // Line widths apply to polylines
    ofSetColor(255,255,255);
    fourPoint.draw();
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
