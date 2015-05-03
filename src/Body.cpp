//
//  Body.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/3/15.
//
//

#include "Body.h"

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