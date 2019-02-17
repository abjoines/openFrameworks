#include "ofApp.h"
int num, oval, dir, sec;
float angle;
ofVec2f tri, mid, cur, cur2, step, direction;
//--------------------------------------------------------------
void ofApp::setup(){
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
bool drawFirst = true;
bool drawSecond = true;
bool drawThird = true;
bool drawFourth = true;

//--------------------------------------------------------------
const int maxDistance = 25;
void ofApp::update(){
    sec = (ofGetFrameNum() / 60) % 60;
    drawFirst = sec < 2;
    drawSecond = sec >2 && sec < 4;
    drawThird = sec > 4 && sec < 6;
    drawFourth = sec > 6 && sec < 8;
    
    bool easing = false;
    int dist;
    dist = cur.distance(mid);  // distance always positive
    
    //happy
    if (drawFirst){
    int stepY = ofMap(dist, 0, 200, 10, 1);
    step = ofVec2f(1, stepY);
    
    if ((cur + (step * direction)).distance(mid) > maxDistance) { // change direction if we will go over
        direction *= -1;
    }

    cur += step * direction;
    cur2 += step * direction;
        
    oval -= 1;
    }
    
    //surprise
    if (drawSecond){
        dir = 1;
        if (oval > 120) { // change direction if we will go over
            dir *= -1;
        }
        oval += 3;
    }
    
    //sad
    if (drawThird){
        oval = 30;
        cur2.y +=1;
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
//annoyed
    if (drawFourth) {
        oval = 60;
        cur2.y-=1;
        ofDrawCircle(cur2, 120);
        ofDrawCircle(cur2.x*2, cur2.y, 120);
        ofSetColor(255);
        ofDrawEllipse(cur2, 130, 10);
        ofDrawEllipse(cur2.x*2, cur2.y, 130, 10);
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
