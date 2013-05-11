#pragma once

#include "ofMain.h"
#include "ofxTLBangs.h"

class ofxTLColorBangs : public ofxTLBangs {
public:
  ofxTLColorBangs();
	virtual ~ofxTLColorBangs();

	ofColor color;
	virtual void setColor(ofColor col);

	virtual void draw();
	virtual string getTrackType();

};
