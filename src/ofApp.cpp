#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofTrueTypeFont::setGlobalDpi(72);
    verdana.loadFont("verdana.ttf", 14,true, true);
    verdana.setLineHeight(18.0f);
    verdana.setLetterSpacing(1.037);
    
//    secondWindow.setup("second window", 10, 10, 300, 300, false);
    
    frameHeight = 200;
    frameWidth = 200;
    halfH = frameHeight/2;
    halfW = frameWidth/2;
    buffer = 30;
    numOfFrames = 4;
    numOfColumns = 2;
    const float identityScale = 1.0f;
    const ofColor black = ofColor(0, 0, 0);
    const ofColor red = ofColor(255, 0, 0);
    const ofColor purple = ofColor(205, 0, 255);
    
    const float earScaleX = 0.8f;
    const float earScaleY = identityScale;
    const float earScaleZ = identityScale;
    this->ear1 = new WaterDrop(earScaleX, earScaleY, earScaleZ, 605, 295, 100, 180, red, false);
    this->ear2 = new WaterDrop(earScaleX, earScaleY, earScaleZ, 695, 295, 100, 180, purple, false);
    
    const float legScaleX = 0.8;
    const float legScaleY = 1.0f;
    const float legScaleZ = 1.0f;
    this->leg1 = new WaterDrop(legScaleX, legScaleY, legScaleZ, 585, 495, 100, 10,ofColor(5,255,0), false);
    this->leg2 = new WaterDrop(legScaleX, legScaleY, legScaleZ, 625, 502, 100, -10,ofColor(5,255,255), false);
    
    const float armScaleX = 0.8f;
    const float armScaleY = 0.8f;
    const float armScaleZ = 0.8f;
    this->arm1 = new WaterDrop(armScaleX, armScaleY, armScaleZ, 620, 380, 50, 90, ofColor(255,100,100), false);
    this->arm2 = new WaterDrop(armScaleX, armScaleY, armScaleZ, 640, 430, 50, 270, ofColor(100,100,255), false);

    const float bodyScaleX = 1.0f;
    const float bodyScaleY = 1.0f;
    const float bodyScaleZ = identityScale;
    this->body1 = new Body(bodyScaleX, bodyScaleY, bodyScaleZ, 0, 0, 0,620, 250, 500, 600, 750, 600, ofColor(200,100,100), false);

    const float headScaleX = identityScale;
    const float headScaleY = identityScale;
    const float headScaleZ = identityScale;
    this->head = new Head(headScaleX, headScaleY, headScaleZ, 620,305,200,200, ofColor(100,100,200), false);
    
    const float leftEyeScaleX = identityScale;
    const float leftEyeScaleY = identityScale;
    const float leftEyeScaleZ = identityScale;
    this->leftEye = new Head(leftEyeScaleX, leftEyeScaleY, leftEyeScaleZ, 586, 328, 12, 12, black, false);
    
    const float rightEyeScaleX = identityScale;
    const float rightEyeScaleY = identityScale;
    const float rightEyeScaleZ = identityScale;
    this->rightEye = new Head(rightEyeScaleX, rightEyeScaleY, rightEyeScaleZ, 661, 328, 10, 10, black, false);
    
    const ofColor lavender = ofColor(176,183,255);
    for (int i = 0; i < numOfFrames; i++){
        frames.resize(numOfFrames);
        this->frames[i] = new Frame((i%numOfColumns+1)*buffer + (i%numOfColumns)*frameWidth,
                             (1+floor(i/float(numOfColumns)))*buffer + (floor(i/float(numOfColumns)))*frameHeight,
                             frameWidth, frameHeight, lavender,false, false);
    }
    
    this->editor = new CodeEditor(800,50,505,700);
//    xPos, yPos, width, height
    
    this->parser = new Parser("");
    
    transparent.afterMainSetup(ofxTransparentWindow::NORMAL);
}

//--------------------------------------------------------------
void ofApp::update(){
    transparent.update();
    parser->update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    if(parser->renderWindowHideWindow == true) {
        parser->renderWindowWithCode = false;
        secondWindow->hide();

    }
    
    if(parser->renderWindowWithCode == true) {
        secondWindow->begin();
        ofSetColor(255);
        ofEllipse(20, 20, 20, 20);
        secondWindow->end();
        cout << parser->renderWindowWithCode << endl;
    }
    
    if(parser->renderWindow == true && secondWindowRendered == false){
        this->secondWindow = new MultipleWindows(300, 300);
        secondWindow->setup("second window", 10, 10, 300, 300, false);
        secondWindowRendered = true;
    }
    
    
//    if(parser->renderWindow == true){
//
//        secondWindow.begin();
////        ofBackground(255, 255, 255, 30);
////        ofSetColor(255);
////        ofEllipse(20, 20, 20, 20);
//        transparent.update();
//        secondWindow.end();
//    }
    
    ofColor lavender = ofColor(176,183,255);
    transparent.update();
    ofSetCircleResolution(30);
    
    //to be used to calculate area of body
    areaOfTriangle = (ABS(body1->xPosRight*(body1->yPos - body1->yPosLeft) + body1->xPos *(body1->yPosLeft - body1->yPosRight) + body1->xPosLeft*(body1->xPosRight - body1->yPos))/2);
    
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
    editor->draw();
    
    for (int i = 0;  i < numOfFrames; i++){
        frames[i]->frameColor = lavender;
        frames[i]->draw();
    }
    
//      cout << frames[0]->startClick <<endl;
//    ofSetColor(0, 0, 0);
//    ofBeginShape();
//        ofVertex(90, 100);
//        ofVertex(0, 300);
//        ofVertex(180, 300);
//    ofEndShape();

    verdana.drawString(parser->typed, editor->textStartX, editor->textStartY);
//    if (float stringWidth(parser->typed)){
//        
//    }
    
    cout << parser->stringWidth(parser->typed) <<endl;
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    parser->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    parser->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    //checking if in circle / left eye
    if(ofDist(leftEye->xPos, leftEye->yPos, x, y) <= leftEye->width/2){
        leftEye->mouseOver = true;
    }else{
        leftEye->mouseOver = false;
    }
    //checking if in circle / right eye
    if(ofDist(rightEye->xPos, rightEye->yPos, x, y) <= rightEye->width/2){
        rightEye->mouseOver = true;
    }else{
        rightEye->mouseOver = false;
    }
    //checking if in circle / head
    if(ofDist(head->xPos, head->yPos, x, y) <= head->width/2 && leftEye->mouseOver != true && rightEye->mouseOver != true){
        head->mouseOver = true;
    }else{
        head->mouseOver = false;
    }
    
    //checking if in triangle / body
    
    areaOfSubtriangle1 = ABS(x*(body1->yPos - body1->yPosLeft) + body1->xPos *(body1->yPosLeft - y) + body1->xPosLeft*(y - body1->yPos))/2;
    areaOfSubtriangle2 = ABS(x*(body1->yPos - body1->yPosRight) + body1->xPos *(body1->yPosRight - y) + body1->xPosRight*(y - body1->yPos))/2;
    areaOfSubtriangle3 = ABS(x*(body1->yPosRight - body1->yPosLeft) + body1->xPosRight *(body1->yPosLeft - y) + body1->xPosLeft*(y - body1->yPosRight))/2;
    
    if (areaOfSubtriangle1 + areaOfSubtriangle2 + areaOfSubtriangle3 == areaOfTriangle + 75* body1->xPosLeft && head->mouseOver != true){
        body1->mouseOver = true;
    }
    else {
        body1->mouseOver = false;
    }

//    cout<<areaOfTriangle<<endl;
//    cout<<areaOfSubtriangle1 << "+" << areaOfSubtriangle2 << "+" << areaOfSubtriangle3 << endl;
//    cout<<areaOfSubtriangle3 + areaOfSubtriangle2 + areaOfSubtriangle1 << endl;
    
//    cout<<body1->mouseOver<<endl;
//    cout<<head->mouseOver<<endl;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    if(head->mouseOver == true){
        head->xPos = x;
        head->yPos = y;
        headBeingDragged = true;
    }
    if(leftEye->mouseOver == true){
        leftEye->xPos = x;
        leftEye->yPos = y;
        leftEyeBeingDragged = true;
    }
    if(rightEye->mouseOver == true){
        rightEye->xPos = x;
        rightEye->yPos = y;
        rightEyeBeingDragged = true;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    headBeingDragged = false;
    leftEyeBeingDragged = false;
    rightEyeBeingDragged = false;
    for (int i = 0; i < numOfFrames; i++){
        if (x > frames[i]->xPos && x < frames[i]->xPos + frameWidth && y > frames[i]->yPos && y < frames[i]->yPos + frameHeight){
//            frames[i]->height = 10;
            frames[i]->startClick = true;
        }
    }
    cout << x << "," << y <<endl;
    
    
    if(head->mouseOver == true){
        head->xPos = x;
        head->yPos = y;
    }
    if(leftEye->mouseOver == true){
        leftEye->xPos = x;
        leftEye->yPos = y;
    }
    if(rightEye->mouseOver == true){
        rightEye->xPos = x;
        rightEye->yPos = y;
    }
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    for (int i = 0; i < numOfFrames; i++){
        if (x > frames[i]->xPos && x < frames[i]->xPos + frameWidth && y > frames[i]->yPos && y < frames[i]->yPos + frameHeight){
            frames[i]->endClick = true;
        }
    }
    head->xPos = 620;
    head->yPos = 305;
    leftEye->xPos = 586;
    leftEye->yPos = 328;
    rightEye->xPos = 661;
    rightEye->yPos = 328;
    
    if (headBeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        parser->typed = parser->typed + " head ";
    }
    if (leftEyeBeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        parser->typed = parser->typed + " eye ";
    }
    if (rightEyeBeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        parser->typed = parser->typed + " eye ";
    }
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
