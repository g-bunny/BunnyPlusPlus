//
//  WaterDrop.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/3/15.
//
//

#include "WaterDrop.h"
//--------------------------------------------------------------
void WaterDrop::setup(){
    nCurveVertices = 8;
    curveVertices[0].x = 29;
    curveVertices[0].y = 0;
    curveVertices[1].x = 7;
    curveVertices[1].y = 89;
    curveVertices[2].x = 0;
    curveVertices[2].y = 136;
    curveVertices[3].x = 7;
    curveVertices[3].y = 167;
    curveVertices[4].x = 31;
    curveVertices[4].y = 180;
    curveVertices[5].x = 55;
    curveVertices[5].y = 167;
    curveVertices[6].x = 61;
    curveVertices[6].y = 136;
    curveVertices[7].x = 54;
    curveVertices[7].y = 88;
    
    for (int i = 0; i < nCurveVertices; i++){
        curveVertices[i].bOver 			= false;
        curveVertices[i].bBeingDragged 	= false;
        curveVertices[i].radius = 4;
    }}


//--------------------------------------------------------------
void WaterDrop::draw(){
    ofPushMatrix();
    ofTranslate(transX,transY,transZ);
    ofRotateZ(rotateAngle);
    ofScale(scaleX,scaleY,scaleZ);
    ofSetColor(bunnyPartColor);
    ofBeginShape();
    
    for (int i = 0; i < nCurveVertices; i++){
        
        if (i == 0){
            ofCurveVertex(curveVertices[0].x, curveVertices[0].y); // we need to duplicate 0 for the curve to start at point 0
            ofCurveVertex(curveVertices[0].x, curveVertices[0].y); // we need to duplicate 0 for the curve to start at point 0
        } else if (i == nCurveVertices-1){
            ofCurveVertex(curveVertices[i].x, curveVertices[i].y);
            ofCurveVertex(curveVertices[0].x, curveVertices[0].y);	// to draw a curve from pt 6 to pt 0
            ofCurveVertex(curveVertices[0].x, curveVertices[0].y);	// we duplicate the first point twice
        } else {
            ofCurveVertex(curveVertices[i].x, curveVertices[i].y);
        }
    }
    
    ofEndShape();
    
//    ofEnableAlphaBlending();
//    ofNoFill();
//    ofSetColor(0,0,0,40);
//    ofBeginShape();
//    for (int i = 0; i < nCurveVertices; i++){
//    				ofVertex(curveVertices[i].x, curveVertices[i].y);
//    }
//    ofEndShape(true);
//    
//    
//    ofSetColor(0,0,0,80);
//    for (int i = 0; i < nCurveVertices; i++){
//        if (curveVertices[i].bOver == true) ofFill();
//        else ofNoFill();
//        ofCircle(curveVertices[i].x, curveVertices[i].y,4);
//    }
//    ofDisableAlphaBlending();
    
    cout << "1:" << curveVertices[0].x << "," << curveVertices[0].y << endl;
    cout << "2:" << curveVertices[1].x << "," << curveVertices[1].y << endl;
    cout << "3:" << curveVertices[2].x << "," << curveVertices[2].y << endl;
    cout << "4:" << curveVertices[3].x << "," << curveVertices[3].y << endl;
    cout << "5:" << curveVertices[4].x << "," << curveVertices[4].y << endl;
    cout << "6:" << curveVertices[5].x << "," << curveVertices[5].y << endl;
    cout << "7:" << curveVertices[6].x << "," << curveVertices[6].y << endl;
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void WaterDrop::keyPressed(int key){
    
}

//--------------------------------------------------------------
void WaterDrop::keyReleased(int key){
    
}

//--------------------------------------------------------------
void WaterDrop::mouseMoved(int x, int y ){
    for (int i = 0; i < nCurveVertices; i++){
        float diffx = x - curveVertices[i].x;
        float diffy = y - curveVertices[i].y;
        float dist = sqrt(diffx*diffx + diffy*diffy);
        if (dist < curveVertices[i].radius){
            curveVertices[i].bOver = true;
        } else {
            curveVertices[i].bOver = false;
        }
    }
}

//--------------------------------------------------------------
void WaterDrop::mouseDragged(int x, int y, int button){
    for (int i = 0; i < nCurveVertices; i++){
        if (curveVertices[i].bBeingDragged == true){
            curveVertices[i].x = x;
            curveVertices[i].y = y;
        }
    }
}

//--------------------------------------------------------------
void WaterDrop::mousePressed(int x, int y, int button){
    for (int i = 0; i < nCurveVertices; i++){
        float diffx = x - curveVertices[i].x;
        float diffy = y - curveVertices[i].y;
        float dist = sqrt(diffx*diffx + diffy*diffy);
        if (dist < curveVertices[i].radius){
            curveVertices[i].bBeingDragged = true;
        } else {
            curveVertices[i].bBeingDragged = false;
        }
    }
}

//--------------------------------------------------------------
void WaterDrop::mouseReleased(int x, int y, int button){
    for (int i = 0; i < nCurveVertices; i++){
        curveVertices[i].bBeingDragged = false;
    }
}

//--------------------------------------------------------------
void WaterDrop::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void WaterDrop::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void WaterDrop::dragEvent(ofDragInfo dragInfo){
    
}
