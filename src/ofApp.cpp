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
    const float identityScale = 1.0f;
    const ofColor black = ofColor(0, 0, 0);
    const ofColor red = ofColor(255, 0, 0);
    const ofColor purple = ofColor(205, 0, 255);
    
    const float earScaleX = 0.8f;
    const float earScaleY = identityScale;
    const float earScaleZ = identityScale;
    this->ear1 = new WaterDrop(earScaleX, earScaleY, earScaleZ, 605, 300, 100, 180, red);
    this->ear2 = new WaterDrop(earScaleX, earScaleY, earScaleZ, 695, 300, 100, 180, purple);
    
    const float legScaleX = 1.0f;
    const float legScaleY = 1.0f;
    const float legScaleZ = 1.0f;
    this->leg1 = new WaterDrop(legScaleX, legScaleY, legScaleZ, 505, 300, 100, 10,ofColor(5,255,0));
    this->leg2 = new WaterDrop(legScaleX, legScaleY, legScaleZ, 695, 300, 100, 30,ofColor(5,255,255));
    
    const float armScaleX = 0.5f;
    const float armScaleY = 0.5f;
    const float armScaleZ = 0.5f;
    this->arm1 = new WaterDrop(armScaleX, armScaleY, armScaleZ, 300, 300, 50, 90, ofColor(255,100,100));
    this->arm2 = new WaterDrop(armScaleX, armScaleY, armScaleZ, 300, 300, 50, 270, ofColor(100,100,255));

    const float bodyScaleX = 1.3f;
    const float bodyScaleY = 1.8f;
    const float bodyScaleZ = identityScale;
    this->body1 = new Body(bodyScaleX, bodyScaleY, bodyScaleZ, 520, 85, 0, 90, 100, 0, 300, 190, 300, ofColor(200,100,100));
    
    const float headScaleX = identityScale;
    const float headScaleY = identityScale;
    const float headScaleZ = identityScale;
    this->head = new Head(headScaleX, headScaleY, headScaleZ, 640,310,200,200, ofColor(100,100,200));
    
    const float leftEyeScaleX = identityScale;
    const float leftEyeScaleY = identityScale;
    const float leftEyeScaleZ = identityScale;
    this->leftEye = new Head(leftEyeScaleX, leftEyeScaleY, leftEyeScaleZ, 605, 328, 10, 10, black);
    
    const float rightEyeScaleX = identityScale;
    const float rightEyeScaleY = identityScale;
    const float rightEyeScaleZ = identityScale;
    this->rightEye = new Head(rightEyeScaleX, rightEyeScaleY, rightEyeScaleZ, 680, 328, 10, 10, black);
    
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
