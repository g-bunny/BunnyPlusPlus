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
    
    Bubble(int xPos, int yPos, int width, int height, ofColor color, bool mouseOver);
    
    void draw();
    int xPos;
    int yPos;
    int width;
    int height;
    bool mouseOver;
    //    float rotateAngle;
    ofColor color;
    ofColor mouseOverColor = ofColor(200,100,100,180);
};