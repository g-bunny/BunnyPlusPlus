//
//  Body.h
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/3/15.
//
//

#include "ofMain.h"

class Body{
public:
    
    Body(float scaleX, float scaleY, float scaleZ, int transX, int transY, int transZ, int xPos, int yPos, int xPosLeft, int yPosLeft, int xPosRight, int yPosRight, ofColor color, bool mouseOver);
    
    void draw();
    int xPos;
    int yPos;
    int xPosLeft;
    int yPosLeft;
    int xPosRight;
    int yPosRight;
    int transX, transY, transZ;
    float scaleX, scaleY, scaleZ;
    bool mouseOver;
    ofColor color;
    ofColor mouseOverColor = ofColor(255,255,255,100);
};