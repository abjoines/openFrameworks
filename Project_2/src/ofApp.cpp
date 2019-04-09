#include "ofApp.h"
#include "ofxJSON.h"
#include "ofxGUI.h"

ofxJSONElement json;
float level, ozone, pmLevel;
//--------------------------------------------------------------
void ofApp::setup(){
    std::string url = "https://api.darksky.net/forecast/0eceeaedc32752217290d3eae0269f87/40.7128,-74.0059";
    
    bool parsingSuccessful = json.open(url);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    ozone = json["currently"]["ozone"].asInt();
    level = ofMap(ozone, 300, 400, 2, 20);
    pmLevel = 4;
    
    gui.setup("panel");
    gui.add(o3density.set( "03 Level", level, 2, 20));
    gui.add(pmDensity.set( "PM 2.5 Level", pmLevel, 2, 20));
}

//--------------------------------------------------------------
void ofApp::update(){


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(120, 202, 210);
    ofSetColor(255);
    
//time
    int time = json["currently"]["time"].asInt();
    int seconds = time % 60;
    int minutes = (time/60) % 60;
    int hours = ((time/3600) % 12) -4;
    
    string hrText = ofToString(hours);
    string minText = ofToString(minutes);
    string secText = ofToString(seconds);
    string readableTime = "Current time: " + hrText + ":" + minText + ":" + secText;
    
    ofDrawBitmapString(readableTime, 15, 70);
    
//ozone
    cout << level << endl;
    
    float hourO = json["hourly"]["data"][0]["ozone"].asInt();
    float visibility = json["currently"]["visibility"].asInt();
    float viz = ofMap(visibility,0,10,100,0);
    
    //ppb
    float ppm = (ozone * 1.25)/1000;
    string o3ppm = ofToString(ppm);
    string o3 = "Current Ozone: " + o3ppm + " ppm";
    ofDrawBitmapString(o3, 15, 100);
    
    for ( int x = 200; x <= 480; x+=20){
        for( int y = 250; y <= 530; y+=20){
            for ( int z = -100; z <= 200; z+=20){
            ofSetColor(49, 123, 34, viz * 1.5);
            ofFill();
            ofDrawBox(ofPoint(x, y, z), pmDensity);
            }
        }
    }
    
    for ( int x = ofGetWidth() - 480; x <= ofGetWidth() - 200; x+=20){
        for( int y = 250; y <= 530; y+=20){
            for ( int z = -100; z <= 200; z+=20){
                ofSetColor(4, 42, 43, viz * 1.5);
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
