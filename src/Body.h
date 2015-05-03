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
    void draw();
//    int width;
//    int height;
    int xPos;
    int yPos;
    int xPosLeft;
    int yPosLeft;
    int xPosRight;
    int yPosRight;
    int transX, transY, transZ;
    float scaleX, scaleY, scaleZ;
    ofColor color;
};