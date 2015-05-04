#pragma once

#include "ofMain.h"
#include "ofxTransparentWindow.h"
#include "multipleWindows.h"
#include "Frame.h"
//#include "text.h"
//#include "bunnyParts.h"
#include "WaterDrop.h"
#include "Head.h"
#include "Body.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
//    vector<int> startFrame;
//    vector<int> endFrame;
    vector <Frame*> frames;
    
    Frame *testFrame;
    int numOfFrames;
    int frameWidth;
    int halfW;
    int frameHeight;
    int halfH;
    int buffer;
    int numOfColumns;
    int numOfRows;
    
//    ofColor color;
    WaterDrop *ear1;
    WaterDrop *ear2;
    WaterDrop *leg1;
    WaterDrop *leg2;
    WaterDrop *arm1;
    WaterDrop *arm2;
    Body *body1;
    Head *head;
    Head *leftEye;
    Head *rightEye;
    
private:
    ofxTransparentWindow transparent;

};
