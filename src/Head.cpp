//
//  Head.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/3/15.
//
//

#include "Head.h"

void Head::draw(){
    ofPushMatrix();
    ofSetColor(color);
    ofScale(scaleX,scaleY,scaleZ);
    ofEllipse(xPos,yPos,width,height);
    ofPopMatrix();
}