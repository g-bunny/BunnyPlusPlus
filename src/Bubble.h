//
//  Bubble.h
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/10/15.
//
//

#include "ofMain.h"

class Bubble{
public:
    
    Bubble(float scaleX, float scaleY, float scaleZ, int transX, int transY, int transZ, int xPos, int yPos, int xPosLeft, int yPosLeft, int xPosRight, int yPosRight, ofColor color, bool mouseOver);
    
    void draw();
    int xPos;
    int yPos;
    int xPosLeft;
    int yPosLeft;
    int xPosRight;
    int yPosRight;
    //    int width;
    //    int height;
    int transX, transY, transZ;
    float scaleX, scaleY, scaleZ;
    bool mouseOver;
    //    float rotateAngle;
    ofColor color;
    ofColor mouseOverColor = ofColor(200,100,100,180);
};