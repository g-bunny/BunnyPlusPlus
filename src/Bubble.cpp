//
//  Bubble.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/10/15.
//
//

#include "Bubble.h"
//--------------------------------------------------------------
Bubble::Bubble(float scaleX, float scaleY, float scaleZ, int transX, int transY, int transZ, int xPos, int yPos, int xPosLeft, int yPosLeft, int xPosRight, int yPosRight, ofColor color, bool mouseOver){
    
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    this->scaleZ = scaleZ;
    this->transX = transX;
    this->transY = transY;
    this->transZ = transZ;
    this->xPos = xPos;
    this->yPos = yPos;
    this->xPosLeft = xPosLeft;
    this->xPosRight = xPosRight;
    this->yPosLeft = yPosLeft;
    this->yPosRight = yPosRight;
    this->color = color;
    this->mouseOver = mouseOver;
}

void Bubble::draw(){
//    ofPushMatrix();
    ofTranslate(transX, transY,transZ);
    ofSetColor(color);
    if (mouseOver == true) { ofSetColor(mouseOverColor);}
    ofEllipse(815, 261, 160, 122);
    ofScale(scaleX,scaleY,scaleZ);
    ofSetPolyMode(OF_POLY_WINDING_ODD);
    ofBeginShape();
    
    ofVertex(xPos, yPos);
    ofVertex(xPosLeft, yPosLeft);
    ofVertex(xPosRight, yPosRight);
    ofEndShape();
//    ofPopMatrix();
    
    //    cout << xPos << "," << yPos << "..." << xPosLeft << "," << yPosLeft << "..." << xPosRight << "," << yPosLeft << endl;
    
}