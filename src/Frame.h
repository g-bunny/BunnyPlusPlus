//
//  Frame.h
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/2/15.
//
//

#pragma once
#include <stdio.h>
#include "ofMain.h"

class Frame{
public:
    Frame(int xPos, int yPos, int width, int height, ofColor frameColor, bool startClick, bool endClick);
    void setup();
    void draw();
    //    void mouseDragged(int x, int y, int button);
    //    void resize();
    int xPos, yPos, width, height;
    ofColor frameColor;
    ofVec3f top, topLeft, topRight;
    ofVec3f bot, botLeft, botRight;
    ofVec3f left;
    ofVec3f right;
    bool isClickStarted;
    
    bool startClick;
    bool endClick;
    
};