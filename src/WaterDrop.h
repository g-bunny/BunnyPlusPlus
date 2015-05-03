//
//  WaterDrop.h
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/3/15.
//
//

#pragma once

#include "ofMain.h"

typedef struct {
    
    float 	x;
    float 	y;
    bool 	bBeingDragged;
    bool 	bOver;
    float 	radius;
    
}draggableVertex;


class WaterDrop {

public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    int nCurveVertices;
    int transX, transY, transZ;
    float rotateAngle;
    float scaleX, scaleY, scaleZ;
    ofColor bunnyPartColor;
    draggableVertex curveVertices[7];
    draggableVertex bezierVertices[4];
};


