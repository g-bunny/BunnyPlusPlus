#pragma once

#include "ofMain.h"
#include "ofxTransparentWindow.h"
#include "multipleWindows.h"
#include "Frame.h"
#include "WaterDrop.h"
#include "Head.h"
#include "Body.h"
#include "CodeEditor.h"
//#include "Parser.h"

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
    
    CodeEditor *editor;
    
    Parser * parser;
    vector <string> currentString;
    float areaOfTriangle;
    float areaOfSubtriangle1;
    float areaOfSubtriangle2;
    float areaOfSubtriangle3;
    int bodyCenterPointX;
    int bodyCenterPointY;
    int bodyDifferenceX;
    int bodyDifferenceY;
    
    int leftArmCenterX, leftArmCenterY, rightArmCenterX, rightArmCenterY, leftLegCenterX, leftLegCenterY, rightLegCenterX, rightLegCenterY, leftEarCenterX, leftEarCenterY, rightEarCenterX, rightEarCenterY;
    
    int initialArm1X, initialArm1Y, initialArm2X, initialArm2Y, initialLeg1X, initialLeg1Y, initialLeg2X, initialLeg2Y, initialEar1X, initialEar1Y, initialEar2X, initialEar2Y;
    
    ofTrueTypeFont verdana;
    
    bool headBeingDragged, rightEyeBeingDragged, leftEyeBeingDragged, body1BeingDragged, arm1BeingDragged, arm2BeingDragged, leftEarBeingDragged, rightEarBeingDragged, leftLegBeingDragged, rightLegBeingDragged;
    bool secondWindowRendered;
    
    MultipleWindows *secondWindow;
    
    int currentFrameState;
    int tempVariable;
    
    //state: frames = 1; body parts = 2; editor = 3; general environment = 4
    int whatObjectIsClicked;
    
    UIButton * plusButton;
    UIButton * minusButton;
    bool dontChangeState;
    ofImage logo;
    
private:
    ofxTransparentWindow transparent;

};
