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
#include "Typed.h"
#include "Parser.h"
#include "UIButton.h"

class Frame{
public:
    Frame(int xPos, int yPos, int width, int height, ofColor frameColor, bool startClick, bool endClick, int xPosText, int yPosText);
    void setup();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void frameIsCurrent();
    //    void resize();
    int xPos, yPos, width, height;
    int xPosText, yPosText;
    bool isAFrame;
    ofColor frameColor;
    ofVec3f top, topLeft, topRight;
    ofVec3f bot, botLeft, botRight;
    ofVec3f left;
    ofVec3f right;
    bool currentFrame;
    bool startClick, startClicked;
    bool endClick, endClicked;
    bool pressedKey;
    bool releasedKey;
    Typed * typed;
    Parser * parser;
    ofTrueTypeFont verdana;
    
    UIButton * playButton;
    UIButton * stopButton;
    
    bool playThisFrame;
    
};