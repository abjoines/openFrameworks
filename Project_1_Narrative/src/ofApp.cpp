#include "ofApp.h"

int triX, midX, midY, num, sec, dir, rPos, lPos, ovalH, ovalW, deg1, xVec, yVec, zVec;
ofFbo fbo;  // framebuffer object
float r, xPos, yPos, enter, rad,x, y, yspeed, bg1, bg2, opac;
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetCircleResolution(40);
    myFont.load("Montserrat-Light.ttf",30);
    
//variables
    midX = ofGetWidth()/2;
    triX = ofGetWidth()/3;
    midY = ofGetHeight()/2;
    num = 24;
    enter = midX*2;
    rad = 60;
    rPos = 250;
    lPos = -(midX+200);
    x = ofRandom(ofGetWidth());
    y = ofRandom(-200,-100);
    yspeed = ofRandom(5, 10);
    bg1 = 300;
    bg2 = 900;
    dir = ofGetWidth()*2+400;
    ovalW = ofGetWidth()-400;
    ovalH = 100;
    deg1 = 0;
    xVec = 0;
    yVec = 0;
    zVec = 0;
    opac = 0;

//fbo
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F); // higher precision alpha (no artifacts)
    fbo.begin();
    ofClear(255,255,255, 0);
    fbo.end();
    
//background
    ofSetBackgroundColor(2, 35, 68);
}

//scene states
bool scene1 = true;
bool scene2 = true;
bool scene3 = true;
bool scene4 = true;
bool scene5 = true;
bool scene6 = true;
bool scene7 = true;
bool scene8 = true;
bool scene9 = true;

//--------------------------------------------------------------
void ofApp::update(){
    
//scene changes
    sec = ofGetFrameNum()/60;
    scene1 = sec < 10;
    scene2 = sec > 10 && sec < 13;
    scene3 = sec >= 13 && sec < 16;
    scene4 = sec >= 16 && sec < 19;
    scene5 = sec >= 19 && sec < 32;
    scene6 = sec >= 32 && sec < 57;
    scene7 = sec >= 57 && sec < 60;
    scene8 = sec >= 60 && sec < 90;
    scene9 = sec >= 90 && sec < 120;
    
    xPos = ofRandom(ofGetWidth());
    yPos = ofRandom(ofGetHeight());

//rain and background
    if (scene2 || scene3 || scene4 || scene5 || scene6){
        y += yspeed;
        ofSetBackgroundColor(100);
        
        if (y > ofGetHeight()){
            y = ofRandom(-300, -100);
        }
    }
    
//surprise eyes
    if (scene4){
        if ( rad < 100){
            rad += 3;
        } else {
            rad = 100;
        }
    }
    
//movement scene 5
    if (scene5){
            lPos += 2;
        if (sec > 24){
            rPos += 2;
        }
    }
    
//scene 6
    if (scene6){
        rPos = 100;
        lPos = -100;
        bg1 -= 2;
        bg2 -= 2;
        if (bg1 <= 0){
            bg1 == bg1 + ofGetWidth();
        }
        if (bg2 <= 0){
            bg2 == bg2 + ofGetWidth();
        }
        if (sec > 39){
            dir -=2;
        }
    }
    
//scene 7
    if (scene7) {
        if (rad > 20){
            rad -= 2;
        }
        
        if (sec > 55){
            ovalH += 20;
            ovalW += 20;
        }
    }

//scene 8
    if (scene8){
        opac += 0.25;
        if (sec < 70){
        deg1 += ofRandom(3,10);
        zVec += ofRandom(0,3);
        yVec -= ofRandom(0,3);
        }
        if (sec >= 70 && sec < 80){
        deg1 -= ofRandom(3,10);
        zVec -= ofRandom(0,3);
        xVec += ofRandom(0,3);
            
        }

    }
    
    if (scene9){
        
        if(sec > 90){
            opac -= 2;
        }
        
        if (sec > 91 && rad<60){
            rad += 0.1;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

// puddle
if (scene1==true){
        ripples();
    }

// char 1
if (scene2==true){
        //background
        ofSetColor(0);
        ofDrawRectangle(100, 0, 20, ofGetHeight());
        ofDrawRectangle(700, 0, 20, ofGetHeight());
        ofSetColor(230);
        ofDrawRectangle(0, ofGetHeight()-200, ofGetWidth(), 200);
        
        //umbrella
        ofSetColor(0);
        ofDrawRectRounded(midX + 295, 200, 10, 400, 10);
        ofDrawTriangle(midX + 300, 70, midX+700, 210, midX-100, 210);
        
        rain();
        
        //character 1
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
        for (int i = 0; i < (num-4); i++){
            if (i%2==0){
                ofSetColor(255);
            } else {
                ofSetColor(0);
            }

            float angle = i * TWO_PI / (num-4);
            float x = triX + 50 * cos(angle);
            float x2 = (triX*2) + 50 * cos(angle);
            float y = midY + 50 * sin(angle);
            ofDrawCircle(x , y, 60);
            ofDrawCircle(x2 , y, 60);
        }
    }

// char 2
if (scene3==true){
        //background
        ofSetColor(0);
        ofDrawRectangle(300, 0, 20, ofGetHeight());
        ofDrawRectangle(900, 0, 20, ofGetHeight());
        ofSetColor(230);
        ofDrawRectangle(0, ofGetHeight()-200, ofGetWidth(), 200);
        
        //puddle
        ofSetColor(66, 143, 244);
        ofDrawEllipse(midX, ofGetHeight()-50, ofGetWidth()-400, 100);
        ofSetColor(44, 95, 163);
        ofDrawEllipse(midX-60,midY+340,150,45);
        ofDrawEllipse(midX+60,midY+340,150,45);
        
        //character 2
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
        rain();
    }

// back to char 1
if(scene4==true){
        //background
        ofSetColor(0);
        ofDrawRectangle(100, 0, 20, ofGetHeight());
        ofDrawRectangle(700, 0, 20, ofGetHeight());
        ofSetColor(230);
        ofDrawRectangle(0, ofGetHeight()-200, ofGetWidth(), 200);
        
        //umbrella
        ofSetColor(0);
        ofDrawRectRounded(midX + 295, 200, 10, 400, 10);
        ofDrawTriangle(midX + 300, 70, midX+700, 210, midX-100, 210);
        
        rain();
        
        //character 1
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
        for (int i = 0; i < (num-4); i++){
            if (i%2==0){
                ofSetColor(255);
            } else {
                ofSetColor(0);
            }
            
            float angle = i * TWO_PI / (num-4);
            float x = triX + 50 * cos(angle);
            float x2 = (triX*2) + 50 * cos(angle);
            float y = midY + 50 * sin(angle);
            ofDrawCircle(x , y, rad);
            ofDrawCircle(x2 , y, rad);
        }
    }
    
// char 1 goes to char 2
if ( scene5 == true){
        //background
        ofSetColor(0);
        ofDrawRectangle(300, 0, 20, ofGetHeight());
        ofDrawRectangle(900, 0, 20, ofGetHeight());
        ofSetColor(230);
        ofDrawRectangle(0, ofGetHeight()-200, ofGetWidth(), 200);
        
        //puddle
        ofSetColor(66, 143, 244);
        ofDrawEllipse(midX + 250, ofGetHeight()-50, ofGetWidth()-400, 100);
        ofSetColor(44, 95, 163);
        ofDrawEllipse(midX+190,midY+340,150,45);
        ofDrawEllipse(midX+310,midY+340,150,45);
        
        //character 2
        ofSetColor(46, 186, 100);
        //body
        ofDrawRectRounded(midX-50 + rPos,midY, 100, 330, 10);
        //feet
        ofDrawRectRounded(midX+10 + rPos,midY+320, 100, 25, 10);
        ofDrawRectRounded(midX-110 + rPos,midY+320, 100, 25, 10);
        //head
        ofDrawEllipse(midX + rPos,midY, 475, 350);
        //eyes
        ofDrawCircle((triX + rPos), midY, 130);
        ofDrawCircle((triX*2) + rPos, midY, 130);
        for (int i = 0; i < num; i++){
            if (i%2==0){
                ofSetColor(255);
            } else {
                ofSetColor(0);
            }
            
            float angle = i * TWO_PI / num;
            float x = (triX + rPos) + 50 * cos(angle);
            float x2 = ((triX*2) + rPos) + 50 * cos(angle);
            float y = midY + 50 * sin(angle);
            ofDrawCircle(x , y, 60);
            ofDrawCircle(x2 , y, 60);
        }
        
        //umbrella
        ofSetColor(0);
        ofDrawRectRounded(midX + lPos + 295, 200, 10, 400, 10);
        ofDrawTriangle(midX + lPos + 300, 70, midX+700 + lPos, 210, midX-100 + lPos, 210);
        
        rain();
        
        //character 1
        ofSetColor(0);
        //body
        ofDrawRectRounded(midX-50 + lPos,midY, 100, 330, 10);
        //feet
        ofDrawRectRounded(midX+10 + lPos,midY+320, 100, 25, 10);
        ofDrawRectRounded(midX-110 + lPos,midY+320, 100, 25, 10);
        //head
        ofDrawEllipse(midX + lPos,midY, 475, 350);
        //eyes
        ofDrawCircle(triX + lPos, midY, 130);
        ofDrawCircle(triX*2 +lPos, midY, 130);
        for (int i = 0; i < (num); i++){
            if (i%2==0){
                ofSetColor(255);
            } else {
                ofSetColor(0);
            }
            
            float angle = i * TWO_PI / (num);
            float x = triX + lPos + 50 * cos(angle);
            float x2 = (triX*2) + lPos + 50 * cos(angle);
            float y = midY + 50 * sin(angle);
            ofDrawCircle(x , y, 60);
            ofDrawCircle(x2 , y, 60);
        }
    }
    
// scene 6 -- walking/talking
    if (scene6 == true){
        //background
        ofSetColor(0);
        ofDrawRectangle(bg1, 0, 20, ofGetHeight());
        ofDrawRectangle(bg2, 0, 20, ofGetHeight());
        ofDrawRectangle(bg1 + ofGetWidth(), 0, 20, ofGetHeight());
        ofDrawRectangle(bg2 + ofGetWidth(), 0, 20, ofGetHeight());
        ofDrawRectangle(bg1 + (ofGetWidth() * 2), 0, 20, ofGetHeight());
        ofDrawRectangle(bg2 + (ofGetWidth() * 2), 0, 20, ofGetHeight());
        ofDrawRectangle(bg1 + (ofGetWidth() * 3), 0, 20, ofGetHeight());
        ofDrawRectangle(bg2 + (ofGetWidth() * 3), 0, 20, ofGetHeight());
        ofDrawRectangle(bg1 + (ofGetWidth() * 4), 0, 20, ofGetHeight());
        ofSetColor(230);
        ofDrawRectangle(0, ofGetHeight()-200, ofGetWidth(), 200);
        
        ofSetColor(66, 143, 244);
        ofDrawEllipse(dir, ofGetHeight()-50, ofGetWidth()-400, 100);
        
        rain();
        
        //character 2
        ofSetColor(46, 186, 100);
        //body
        ofDrawRectRounded(midX-50 + rPos,midY, 100, 330, 10);
        //feet
        ofDrawRectRounded(midX+10 + rPos,midY+320, 100, 25, 10);
        ofDrawRectRounded(midX-110 + rPos,midY+320, 100, 25, 10);
        //head
        ofDrawEllipse(midX + rPos,midY, 475, 350);
        //eyes
        ofDrawCircle((triX + rPos), midY, 130);
        ofDrawCircle((triX*2) + rPos, midY, 130);
        for (int i = 0; i < num; i++){
            if (i%2==0){
                ofSetColor(255);
            } else {
                ofSetColor(0);
            }
            
            float angle = i * TWO_PI / num;
            float x = (triX + rPos) + 50 * cos(angle);
            float x2 = ((triX*2) + rPos) + 50 * cos(angle);
            float y = midY + 50 * sin(angle);
            ofDrawCircle(x , y, 60);
            ofDrawCircle(x2 , y, 60);
        }
        
        //umbrella
        ofSetColor(0);
        ofDrawRectRounded(midX + lPos + 295, 200, 10, 400, 10);
        ofDrawTriangle(midX + lPos + 300, 70, midX+700 + lPos, 210, midX-100 + lPos, 210);
        
        //character 1
        ofSetColor(0);
        //body
        ofDrawRectRounded(midX-50 + lPos,midY, 100, 330, 10);
        //feet
        ofDrawRectRounded(midX+10 + lPos,midY+320, 100, 25, 10);
        ofDrawRectRounded(midX-110 + lPos,midY+320, 100, 25, 10);
        //head
        ofDrawEllipse(midX + lPos,midY, 475, 350);
        //eyes
        ofDrawCircle(triX + lPos, midY, 130);
        ofDrawCircle(triX*2 +lPos, midY, 130);
        for (int i = 0; i < (num); i++){
            if (i%2==0){
                ofSetColor(255);
            } else {
                ofSetColor(0);
            }
            
            float angle = i * TWO_PI / (num);
            float x = triX + lPos + 50 * cos(angle);
            float x2 = (triX*2) + lPos + 50 * cos(angle);
            float y = midY + 50 * sin(angle);
            ofDrawCircle(x , y, 60);
            ofDrawCircle(x2 , y, 60);
        }
    }

// scene 7 -- fall thru puddle
    if (scene7 == true){
        ofBackgroundGradient(0, 100);
        //background
        ofSetColor(0);
        ofDrawRectangle(bg1, 0, 20, ofGetHeight());
        ofDrawRectangle(bg2, 0, 20, ofGetHeight());
        ofSetColor(230);
        ofDrawRectangle(0, ofGetHeight()-200, ofGetWidth(), 200);
        
        ofSetColor(66, 143, 244);
        ofDrawEllipse(midX, ofGetHeight()-50, ovalW, ovalH);
        
        rain();
        
        //character 2
        ofSetColor(46, 186, 100);
        //body
        ofDrawRectRounded(midX-50 + rPos,midY, 100, 330, 10);
        //feet
        ofDrawRectRounded(midX+10 + rPos,midY+320, 100, 25, 10);
        ofDrawRectRounded(midX-110 + rPos,midY+320, 100, 25, 10);
        //head
        ofDrawEllipse(midX + rPos,midY, 475, 350);
        //eyes
        ofDrawCircle((triX + rPos), midY, 130);
        ofDrawCircle((triX*2) + rPos, midY, 130);
        for (int i = 0; i < num; i++){
            if (i%2==0){
                ofSetColor(255);
            } else {
                ofSetColor(0);
            }
            
            float angle = i * TWO_PI / num;
            float x = (triX + rPos) + 50 * cos(angle);
            float x2 = ((triX*2) + rPos) + 50 * cos(angle);
            float y = midY + 50 * sin(angle);
            ofDrawCircle(x , y, rad);
            ofDrawCircle(x2 , y, rad);
        }
        
        //umbrella
        ofSetColor(0);
        ofDrawRectRounded(midX + lPos + 295, 200, 10, 400, 10);
        ofDrawTriangle(midX + lPos + 300, 70, midX+700 + lPos, 210, midX-100 + lPos, 210);
        
        //character 1
        ofSetColor(0);
        //body
        ofDrawRectRounded(midX-50 + lPos,midY, 100, 330, 10);
        //feet
        ofDrawRectRounded(midX+10 + lPos,midY+320, 100, 25, 10);
        ofDrawRectRounded(midX-110 + lPos,midY+320, 100, 25, 10);
        //head
        ofDrawEllipse(midX + lPos,midY, 475, 350);
        //eyes
        ofDrawCircle(triX + lPos, midY, 130);
        ofDrawCircle(triX*2 +lPos, midY, 130);
        for (int i = 0; i < (num); i++){
            if (i%2==0){
                ofSetColor(255);
            } else {
                ofSetColor(0);
            }
            
            float angle = i * TWO_PI / (num);
            float x = triX + lPos + 50 * cos(angle);
            float x2 = (triX*2) + lPos + 50 * cos(angle);
            float y = midY + 50 * sin(angle);
            ofDrawCircle(x , y, rad);
            ofDrawCircle(x2 , y, rad);
        }
        
    }
    
// scene 8 -- down through puddle
    if (scene8 == true){
        ofSetBackgroundColor(66, 143, 244);
        
        ofSetColor(53, 4, 4, opac);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        
        glPushMatrix();
        ofRotateDeg(deg1 * 2, xVec, -yVec, zVec);
        //character 2
        ofSetColor(46, 186, 100);
        //body
        ofDrawRectRounded(midX-50 + rPos,midY, 100, 330, 10);
        //feet
        ofDrawRectRounded(midX+10 + rPos,midY+320, 100, 25, 10);
        ofDrawRectRounded(midX-110 + rPos,midY+320, 100, 25, 10);
        //head
        ofDrawEllipse(midX + rPos,midY, 475, 350);
        //eyes
        ofDrawCircle((triX + rPos), midY, 130);
        ofDrawCircle((triX*2) + rPos, midY, 130);
        for (int i = 0; i < num; i++){
            if (i%2==0){
                ofSetColor(255);
            } else {
                ofSetColor(0);
            }
            
            float angle = i * TWO_PI / num;
            float x = (triX + rPos) + 50 * cos(angle);
            float x2 = ((triX*2) + rPos) + 50 * cos(angle);
            float y = midY + 50 * sin(angle);
            ofDrawCircle(x , y, rad);
            ofDrawCircle(x2 , y, rad);
        }
        glPopMatrix();
        
        glPushMatrix();
        ofRotateDeg(deg1 , -xVec, -yVec, zVec);
        //umbrella
        ofSetColor(0);
        ofDrawRectRounded(midX + lPos + 295, 200, 10, 400, 10);
        ofDrawTriangle(midX + lPos + 300, 70, midX+700 + lPos, 210, midX-100 + lPos, 210);
        glPopMatrix();
        
        //character 1
        ofSetColor(0);
        glPushMatrix();
        ofRotateDeg(deg1*2, -xVec, yVec, zVec);
        //body
        ofDrawRectRounded(midX-50 + lPos,midY, 100, 330, 10);
        //feet
        ofDrawRectRounded(midX+10 + lPos,midY+320, 100, 25, 10);
        ofDrawRectRounded(midX-110 + lPos,midY+320, 100, 25, 10);
        //head
        ofDrawEllipse(midX + lPos,midY, 475, 350);
        //eyes
        ofDrawCircle(triX + lPos, midY, 130);
        ofDrawCircle(triX*2 +lPos, midY, 130);
        for (int i = 0; i < (num); i++){
            if (i%2==0){
                ofSetColor(255);
            } else {
                ofSetColor(0);
            }
            
            float angle = i * TWO_PI / (num);
            float x = triX + lPos + 50 * cos(angle);
            float x2 = (triX*2) + lPos + 50 * cos(angle);
            float y = midY + 50 * sin(angle);
            ofDrawCircle(x , y, rad);
            ofDrawCircle(x2 , y, rad);
        }
        glPopMatrix();
        
        if(sec>85){
        ofSetColor(0, 0, 0);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        }
    }

// scene 9 -- wake up
    if (scene9 == true){
        ofSetBackgroundColor(11, 7, 81);
        
        ofSetColor(0, 0, 0);

        //body
        ofDrawRectRounded(midX-50 + lPos,midY, 100, 330, 10);
        //head
        ofDrawEllipse(midX + lPos,midY, 475, 350);
        //eyes
        ofDrawCircle(triX + lPos, midY, 130);
        ofDrawCircle(triX*2 +lPos, midY, 130);
        for (int i = 0; i < (num); i++){
            if (i%2==0){
                ofSetColor(255, 255, 255);
            } else {
                ofSetColor(0, 0, 0);
            }
            
            float angle = i * TWO_PI / (num);
            float x = triX + lPos + 50 * cos(angle);
            float x2 = (triX*2) + lPos + 50 * cos(angle);
            float y = midY + 50 * sin(angle);
            ofDrawCircle(x , y, rad);
            ofDrawCircle(x2 , y, rad);
        }
        if (sec>100){
            ofSetColor(255);
            myFont.drawString("What a weird dream...",ofGetWidth()/2, 200);
        }
        
        ofSetColor(100);
        ofDrawRectRounded(100,575,625,150, 10);
        
        ofSetColor(0, 0, 0, opac);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    }
    
}

//--------------------------------------------------------------
void ofApp::rain(){
    fbo.begin();
    ofSetColor(0, 10); // background color with alpha
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    for (int x=-100; x < ofGetWidth(); x+= ofRandom(100,300)){
        for(int y=-200; y < ofGetHeight(); y+= ofRandom(100,500)){
            drop(x,y);
        }
    }
    ofFill();
    fbo.end();
    
    ofSetColor(255,255,255);  // always set the color before drawing the fbo
    fbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::drop(int x, int y){
    ofSetColor(255);
    ofDrawLine(x, y, x-3, y + 10);
}

//--------------------------------------------------------------
void ofApp::ripples(){
fbo.begin();
ofSetColor(4, 48, 94, 5); // background color with alpha
ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

ofSetColor(94, 159, 224);
ofNoFill();

r = ofRandom(40);
ofDrawCircle(xPos,yPos,r);

ofFill();
fbo.end();
ofSetColor(255,255,255);  // always set the color before drawing the fbo
fbo.draw(0,0);
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
