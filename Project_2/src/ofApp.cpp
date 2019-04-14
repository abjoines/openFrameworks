#include "ofApp.h"
#include "ofxJSON.h"
#include "ofxGUI.h"

ofxJSONElement json;
float level, ozone, pmLevel, viz, visibility, step1, step2, step3;
//--------------------------------------------------------------
void ofApp::setup(){
    
//JSON loading
    std::string url = "https://api.darksky.net/forecast/0eceeaedc32752217290d3eae0269f87/40.7128,-74.0059";
    bool parsingSuccessful = json.open(url);
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    step1 = 0.05;
    step2 = 0.05;
    step3 = 0.05;
    pmLevel = 4;
    
    ozone = json["currently"]["ozone"].asInt();
    level = ofMap(ozone, 250, 400, 2, 20);
    
    visibility = json["currently"]["visibility"].asInt();
    viz = ofMap(visibility,0,10,100,0);
    
    gui.setup("panel");
    gui.add(o3density.set( "03 Level", level, 2, 20));
    gui.add(pmDensity.set( "PM 2.5 Level", pmLevel, 2, 20));
    gui.add(Vis.set( "Visibility", viz, 0, 100));
    gui.add(animate.setup("Animate", false));
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (animate == true) {
        o3density += step1;
        Vis += step2;
        pmDensity += step3;
        if (o3density <= 2 || o3density >= 20){
            step1 *= -1;
        }
        if (Vis <= 0 || Vis >=100){
            step2 *= -1;
        }
        if (pmDensity <= 2 || pmDensity >= 20){
            step3 *= -1;
        }
        
        ozone = ofMap(o3density, 2, 20, 250, 400);
        pmLevel = ofMap(pmDensity, 2, 20, 0, 0.5);
        visibility = ofMap(Vis, 100, 0, 0, 10);
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(120, 202, 210);
    ofSetColor(255);
    
//time
    int time = json["currently"]["time"].asInt();
        int seconds = time % 60;
        int minutes = (time/60) % 60;
        int hours = ((time/3600) % 24) -4;
    
        string hrText = ofToString(hours);
        string minText = ofToString(minutes);
        string secText = ofToString(seconds);
    
        string readableTime = "Current time: " + hrText + ":" + minText;
    
    ofSetColor(0);
    ofDrawBitmapString(readableTime, 15, 125);
    
//visibility text
    string visible = ofToString(visibility);
    string curVis = "Current Visibility: " + visible + " miles";
    ofDrawBitmapString(curVis, 15, 145);
    
//o3 text
    float oppm = (ozone * 1.25)/1000;
    string o3ppm = ofToString(oppm);
    string o3 = "Current Ozone: " + o3ppm + " ppm";
    ofDrawBitmapString(o3, 675, 650);
    
//PM text
    float pmPPM = (pmLevel * 1.25)/1000;
    string curPM = ofToString(pmPPM);
    string pm = "Current PM 2.5: " + curPM + " ppm";
    ofDrawBitmapString(pm, 150, 650);

//visualization
    for ( int x = 200; x <= 480; x+=20){
        for( int y = 250; y <= 530; y+=20){
            for ( int z = -100; z <= 200; z+=20){
            ofSetColor(49, 123, 34, Vis * 1.5);
            ofFill();
            ofDrawBox(ofPoint(x, y, z), pmDensity);
            }
        }
    }

    for ( int x = ofGetWidth() - 480; x <= ofGetWidth() - 200; x+=20){
        for( int y = 250; y <= 530; y+=20){
            for ( int z = -100; z <= 200; z+=20){
                ofSetColor(4, 42, 43, Vis * 1.5);
                ofFill();
                ofDrawBox(ofPoint(x, y, z), o3density);
            }
        }
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
