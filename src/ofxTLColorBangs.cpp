#include "ofxTimeline.h"
#include "ofxTLColorBangs.h"


ofxTLColorBangs::ofxTLColorBangs(){
    lastTimelinePoint = 0;
  lastBangTime = 0;
	color = ofColor(100, 0, 100);
}

ofxTLColorBangs::~ofxTLColorBangs(){
	disable();
}


void ofxTLColorBangs::setColor(ofColor col)
{
  color = col;
}

void ofxTLColorBangs::draw(){
        
    if(bounds.height < 2){
        return;
    }
    
    ofPushStyle();
    ofFill();
	
	//float currentPercent = powf(MIN(ofGetElapsedTimef() - lastBangTime, .5), 2);
	float currentPercent = powf(ofMap(ofGetElapsedTimef() - lastBangTime, 0, .5, 1.0, 0,true), 2);
	if(currentPercent > 0){
		ofSetColor(timeline->getColors().disabledColor, 100*(currentPercent));
		ofFill();
		ofRect(bounds.x, bounds.y, bounds.width, bounds.height);
	}
	
    for(int i = keyframes.size()-1; i >= 0; i--){
		if(!isKeyframeIsInBounds(keyframes[i])){
			continue;
		}
        //int screenX = normalizedXtoScreenX(keyframes[i]->position.x);
        int screenX = millisToScreenX(keyframes[i]->time);
        if(isKeyframeSelected(keyframes[i])){
            ofSetLineWidth(2);
            ofSetColor(timeline->getColors().textColor);
        }
        else if(keyframes[i] == hoverKeyframe){
            ofSetLineWidth(4);
            ofSetColor(timeline->getColors().highlightColor);
        }
        else{
            ofSetLineWidth(2);
            ofSetColor(color);
        }
        
        ofLine(screenX, bounds.y, screenX, bounds.y+bounds.height);
    }
    ofPopStyle();

}

string ofxTLColorBangs::getTrackType(){
    return "Bangs";
}
