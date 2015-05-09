//
//  Button.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/8/15.
//
//

#include "UIButton.h"

UIButton::UIButton(int buttonType){
    this->buttonType = buttonType;
}

void UIButton::drawPlus(){
    ofSetColor(defaultColor);
    ofLine(xPos, yPos, xPos + width, yPos);
    ofLine(xPos + width/2, yPos - width/2, xPos + width/2, yPos+ width/2);
}

void UIButton::drawMinus(){
    ofSetColor(defaultColor);
    ofLine(xPos, yPos, xPos + width, yPos);
}

void UIButton::drawPlay(){
    ofSetColor(defaultColor);
    ofSetCircleResolution(3);
    ofCircle(xPos, yPos, width);
}

void UIButton::drawStop(){
    ofSetColor(defaultColor);
    ofSetCircleResolution(4);
    ofCircle(xPos, yPos, width);
}

void UIButton::mouseReleased(int x, int y, int button){
    if (x > xPos && x < xPos + width && y > yPos && y < yPos + height){
        if (buttonType == 1){
            numberToAlter +=1;
            cout<<"something"<<endl;
        } else if (buttonType == 2){
            numberToAlter -=1;
        } else if( buttonType == 3){
            playThings = true;
        } else if (buttonType == 4){
            destroyThings = true;
        }
        defaultColor = ofColor(255,0,0);
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