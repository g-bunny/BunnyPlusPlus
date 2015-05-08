//
//  Button.h
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/8/15.
//
//

#include "ofMain.h"

class Button{
public:
    
    Button(int buttonType);
    
    void drawPlus();
    void drawMinus();
    void drawPlay();
    void drawStop();
    
    void mouseReleased(int button);
    
    int width;
    int height;
    int xPos;
    int yPos;
    
    int buttonType;
    int numberToAlter;
    bool playThings, destroyThings;
    ofColor whiteColor;
    ofColor blackColor;
    ofColor mouseOverColor;
    bool mouseOver;
    
};