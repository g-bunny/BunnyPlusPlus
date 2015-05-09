//
//  Button.h
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/8/15.
//
//

#include "ofMain.h"

class UIButton{
public:
    UIButton(int buttonType);
    
    void drawPlus();
    void drawMinus();
    void drawPlay();
    void drawStop();
    
    void mouseReleased(int x, int y, int button);
    
    int width;
    int height;
    int xPos;
    int yPos;
    
    int buttonType;
    int numberToAlter;
    bool playThings, destroyThings;
    ofColor defaultColor;
    ofColor mouseOverColor;
    bool mouseOver;
    
};