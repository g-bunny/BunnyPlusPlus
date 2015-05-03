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
    ear2->draw();
    leg1->draw();
    leg2->draw();
    arm1->draw();
    arm2->draw();
    body1->draw();
    head->draw();
    leftEye->draw();
    rightEye->draw();
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
