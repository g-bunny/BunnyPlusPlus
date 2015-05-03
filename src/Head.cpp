//
//  Head.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/3/15.
//
//

#include "Head.h"

Head::Head(float scaleX, float scaleY, float scaleZ, int xPos, int yPos, int width, int height, ofColor color){
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    this->scaleZ = scaleZ;
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;
    this->color = color;
}

void Head::draw(){
    ofPushMatrix();
    ofSetColor(color);
    ofScale(scaleX,scaleY,scaleZ);
    ofEllipse(xPos,yPos,width,height);
    ofPopMatrix();
}