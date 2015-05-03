//
//  Head.h
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/3/15.
//
//

#include "ofMain.h"

class Head{
    public:
    
    Head(float scaleX, float scaleY, float scaleZ, int xPos, int yPos, int width, int height, ofColor color);
    
    void draw();
    int width;
    int height;
    int xPos;
    int yPos;
    float scaleX, scaleY, scaleZ;
    ofColor color;
    
};