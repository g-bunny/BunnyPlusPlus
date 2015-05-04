//
//  Frame.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/2/15.
//
//

#include "Frame.h"

Frame::Frame(int xPos, int yPos, int width, int height, ofColor frameColor){
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;
    this->color = frameColor;
    this->setup();
}

void Frame::setup(){
    ofSetColor(color);
    
    
    //joints
    topLeft.set(xPos,yPos,0);
    botLeft.set(xPos, yPos+height, 0);
    top.set(xPos + width/2, yPos, 0);
    topRight.set(xPos + width, yPos, 0);
    bot.set(xPos + width/2, yPos + height, 0);
    botRight.set(xPos + width, yPos + height, 0);
    left.set(xPos, yPos + height/2,0);
    right.set(xPos + width, yPos + height/2, 0);
    
}

void Frame::draw(){
    
    ofRect(xPos,yPos,width,height);
    
    //testing joint positions
//    ofSetColor(0,0,0,50);
//    ofRect(topLeft, 4, 4);
//    ofRect(topRight,4,4);
//    ofRect(top,4,4);
//    ofRect(botLeft, 4, 4);
//    ofRect(botRight,4,4);
//    ofRect(bot,4,4);
//    ofRect(left, 4, 4);
//    ofRect(right,4,4);
    
}