//
//  Bubble.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/10/15.
//
//

#include "Bubble.h"
//--------------------------------------------------------------
Bubble::Bubble(int xPos, int yPos, int width, int height, ofColor color, bool mouseOver){
    
    this->width = width;
    this->height = height;
    this->xPos = xPos;
    this->yPos = yPos;
    this->color = color;
    this->mouseOver = mouseOver;
}

void Bubble::draw(){
    ofSetColor(color);
    if (mouseOver == true) { ofSetColor(mouseOverColor);}
    ofBeginShape();
    ofEllipse(xPos, yPos, width, height);
    ofEndShape();
//    ofPopMatrix();
    
    //    cout << xPos << "," << yPos << "..." << xPosLeft << "," << yPosLeft << "..." << xPosRight << "," << yPosLeft << endl;
    
}