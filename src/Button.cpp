//
//  Button.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/8/15.
//
//

#include "Button.h"

Button::Button(int buttonType){
    this->buttonType = buttonType;
}

void Button::drawPlus(){
    ofLine(xPos, yPos, xPos + width, yPos);
    ofLine(xPos + width/2, yPos - width/2, xPos + width/2, yPos+ width/2);
}

void Button::drawMinus(){
    ofLine(xPos, yPos, xPos + width, yPos);
}

void Button::drawPlay(){
    ofSetCircleResolution(3);
    ofCircle(xPos, yPos, width);
}

void Button::drawStop(){
    ofRect(xPos, yPos, width, height);
}

void Button::mouseReleased(int button){
    if (buttonType == 1){
        numberToAlter +=1;
    } else if (buttonType == 2){
        numberToAlter -=1;
    } else if( buttonType == 3){
        playThings = true;
    } else if (buttonType == 4){
        destroyThings = true;
    }
}

//int width;
//int height;
//int xPos;
//int yPos;
//ofColor whiteColor;
//ofColor blackColor;
//ofColor mouseOverColor;
//bool mouseOver;