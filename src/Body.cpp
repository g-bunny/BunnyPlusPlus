//
//  Body.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/3/15.
//
//

#include "Body.h"

Body::Body(float scaleX, float scaleY, float scaleZ, int transX, int transY, int transZ, int xPos, int yPos, int xPosLeft, int yPosLeft, int xPosRight, int yPosRight, ofColor color){
    
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
}

void Body::draw(){
    ofPushMatrix();
    ofTranslate(transX, transY,transZ);
    ofSetColor(color);
    ofScale(scaleX,scaleY,scaleZ);
    ofSetPolyMode(OF_POLY_WINDING_ODD);
    ofBeginShape();
        ofVertex(xPos, yPos);
        ofVertex(xPosLeft, yPosLeft);
        ofVertex(xPosRight, yPosRight);
    ofEndShape();
    ofPopMatrix();
}