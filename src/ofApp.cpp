#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    frameHeight = 200;
    frameWidth = 200;
    halfH = frameHeight/2;
    halfW = frameWidth/2;
    buffer = 30;

    color.r = 176;
    color.g = 183;
    color.b = 255;
    
    numOfFrames = 4;
    numOfColumns = 2;

    
    this->ear1 = new WaterDrop(0.8, 1, 1, 605, 300, 100, 180, ofColor(255, 0, 0));
    this->ear2 = new WaterDrop(0.8, 1, 1, 695, 300, 100, 180, ofColor(205,0,255));
    this->leg1 = new WaterDrop(1,1,1,505,300,100,10,ofColor(5,255,0));
    this->leg2 = new WaterDrop(1,1,1,695,300,100,30,ofColor(5,255,255));
    this->arm1 = new WaterDrop(0.5,0.5,0.5, 300, 300, 50, 90, ofColor(255,100,100));
    this->arm2 = new WaterDrop(0.5,0.5,0.5, 300, 300, 50, 270, ofColor(100,100,255));
    this->body1 = new Body(1.3, 1.8, 1, 520, 85, 0, 90, 100, 0, 300, 190, 300, ofColor(200,100,100));
    this->head = new Head(1,1,1,640,310,200,200, ofColor(100,100,200));
    this->leftEye = new Head(1,1,1, 605, 328, 10, 10, ofColor(0,0,0));
    this->rightEye = new Head(1,1,1, 680, 328, 10, 10, ofColor(0,0,0));
//    ear1.setup();
//    ear2.setup();
//    ear3.setup();
//    leg2.setup();

    
//    for (int i = 0; i < numOfFrames; i++){
//        startFrame[i] = 0;
//    }
//    startFrame[0] = false;
//    startFrame[1] = false;
//    startFrame[2] = false;
//    startFrame[3] = false;
    transparent.afterMainSetup(ofxTransparentWindow::NORMAL);

}

//--------------------------------------------------------------
void ofApp::update(){
    transparent.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    transparent.update();
    for (int i = 0; i < numOfFrames; i++){
        frames.resize(numOfFrames);
        frames[i].xPos = (i%numOfColumns+1)*buffer + (i%numOfColumns)*frameWidth;
        frames[i].yPos = (1+floor(i/float(numOfColumns)))*buffer + (floor(i/float(numOfColumns)))*frameHeight;
        frames[i].width = frameWidth;
        frames[i].height = frameHeight;
        frames[i].color = color;
        frames[i].draw();
    }
    ofSetCircleResolution(30);
    
    ear1->draw();
    
//    ear2.scaleX = 0.8;
//    ear2.scaleY = 1;
//    ear2.scaleZ = 1;
//    ear2.transX = 695;
//    ear2.transY = 300;
//    ear2.transZ = 100;
//    ear2.rotateAngle = 180;
//    ear2.bunnyPartColor = ofColor(205,0,255);
//    ear2.draw();
    

    
    body1.transX = 520;
    body1.transY = 85;
    body1.transZ = 0;
    body1.xPos = 90;
    body1.yPos = 100;
    body1.xPosLeft = 0;
    body1.yPosLeft = 300;
    body1.xPosRight = 190;
    body1.yPosRight = 300;
    body1.scaleX =1.3;
    body1.scaleY =1.8;
    body1.scaleZ =1;
    body1.color = ofColor(100,100,100);
    body1.draw();
    
    head.xPos = 640;
    head.yPos = 310;
    head.width = 200;
    head.height = 200;
    head.color = ofColor(0,0,255);
    head.scaleZ = 1;
    head.scaleX = 1;
    head.scaleY = 1;
    head.draw();
    
    leftEye.xPos = 605;
    rightEye.xPos = 680;
    leftEye.yPos = 328;
    rightEye.yPos = 328;
    leftEye.width = 10;
    rightEye.width = 10;
    leftEye.height = 10;
    rightEye.height = 10;
    leftEye.scaleY = 1;
    leftEye.scaleX = 1;
    leftEye.scaleZ = 1;
    rightEye.scaleZ = 1;
    rightEye.scaleY = 1;
    rightEye.scaleX = 1;
    leftEye.color = ofColor(0,0,0);
    rightEye.color = ofColor(0,0,0);
    rightEye.draw();
    leftEye.draw();
//    
//    ear3.scaleX = 1;
//    ear3.scaleY = 1;
//    ear3.scaleZ = 1;
//    ear3.transX = 695;
//    ear3.transY = 300;
//    ear3.transZ = 100;
//    ear3.rotateAngle = 10;
//    ear3.bunnyPartColor = ofColor(0,255,5);
//    ear3.draw();
//
//    leg2.scaleX = 1;
//    leg2.scaleY = 1;
//    leg2.scaleZ = 1;
//    leg2.transX = 695;
//    leg2.transY = 300;
//    leg2.transZ = 100;
//    leg2.rotateAngle = 10;
//    leg2.bunnyPartColor = ofColor(5,255,0);
//    leg2.draw();
    }

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
//    for (int i = 0; i < numOfFrames; i++){
//        if (x > frames[i].xPos && x < frames[i].xPos + frameWidth && y > frames[i].yPos && y < frames[i].yPos + frameHeight){
//            startFrame[i] = 1;
//        }
//    }
//    cout << x << endl;
//        cout << startFrame[0] <<endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//    for (int i = 0; i < numOfFrames; i++){
//        if (x > frames[i].xPos && x < frames[i].xPos + frameWidth && y > frames[i].yPos && y < frames[i].yPos + frameHeight){
//            endFrame[i] = true;
//        }
//    }
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
