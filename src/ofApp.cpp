#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofTrueTypeFont::setGlobalDpi(72);
    verdana.loadFont("verdana.ttf", 14,true, true);
    verdana.setLineHeight(18.0f);
    verdana.setLetterSpacing(1.037);
    
    frameHeight = 90;
    frameWidth = 90;
    halfH = frameHeight/2;
    halfW = frameWidth/2;
    buffer = 20;
    numOfFrames = 9;
    numOfColumns = 3;
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
    this->leftEye = new Head(leftEyeScaleX, leftEyeScaleY, leftEyeScaleZ, 586, 328, 10, 10, black, false);
    
    const float rightEyeScaleX = identityScale;
    const float rightEyeScaleY = identityScale;
    const float rightEyeScaleZ = identityScale;
    this->rightEye = new Head(rightEyeScaleX, rightEyeScaleY, rightEyeScaleZ, 661, 328, 10, 10, black, false);
    this->editor = new CodeEditor(800,50,505,700);
    
    const ofColor lavender = ofColor(176,183,255);
    for (int i = 0; i < numOfFrames; i++){
        frames.resize(numOfFrames);
        this->frames[i] = new Frame((i%numOfColumns+1)*buffer + (i%numOfColumns)*frameWidth,
                             (1+floor(i/float(numOfColumns)))*buffer + (floor(i/float(numOfColumns)))*frameHeight,
                             frameWidth, frameHeight, lavender,false, false, editor->textStartX, editor->textStartY);
    }
    

//    xPos, yPos, width, height
//    for (int i = 0; i < numOfFrames; i++){
//        parser.resize(numOfFrames);
//        this->parser[i] = new Parser("");
//    }
//    this->parser = new Parser(currentFrameState);
//    for (int i = 0; i < numOfFrames; i++){
//        parser->typed.resize(numOfFrames);
//    }
    
    transparent.afterMainSetup(ofxTransparentWindow::NORMAL);
}

//--------------------------------------------------------------
void ofApp::update(){
    transparent.update();
//    parser->update();
//    for (int i = 0; i < numOfFrames; i ++){
//        if (frames[i]->currentFrame == true){
//            currentFrameState = i;
//        }
//    }
//    for (int i = numOfFrames - 1; i > -1; i --){
//        if (frames[i]->currentFrame == true){
//            currentFrameState = i;
//        }
//    }
    if(frames[0]->currentFrame == true){
        frames[1]->currentFrame = false;
        frames[2]->currentFrame = false;
        frames[3]->currentFrame = false;
        currentFrameState = 0;
        
    }
    if(frames[1]->currentFrame == true){
        frames[0]->currentFrame = false;
        frames[2]->currentFrame = false;
        frames[3]->currentFrame = false;
        currentFrameState = 1;
    }
    if(frames[2]->currentFrame == true){
        frames[1]->currentFrame = false;
        frames[0]->currentFrame = false;
        frames[3]->currentFrame = false;
        currentFrameState = 2;
    }
    if(frames[3]->currentFrame == true){
        currentFrameState = 3;
        frames[1]->currentFrame = false;
        frames[2]->currentFrame = false;
        frames[0]->currentFrame = false;
    }
    
    if(currentFrameState == 0){
        tempVariable = 0;
        frames[0]->endClick = false;
    } else if (currentFrameState == 1){
        tempVariable = 1;
        frames[1]->endClick = false;
    } else if (currentFrameState == 2){
        tempVariable = 2;
        frames[2]->endClick = false;
    } else if (currentFrameState == 3){
        tempVariable = 3;
        frames[3]->endClick = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

//    if(parser->renderWindowHideWindow == true) {
//        parser->renderWindowWithCode = false;
//        secondWindow->hide();
//
//    }
//    
//    if(parser->renderWindowWithCode == true) {
//        secondWindow->begin();
//        ofSetColor(255);
//        ofEllipse(20, 20, 20, 20);
//        secondWindow->end();
//        cout << parser[0]->renderWindowWithCode << endl;
//    }
//    
//    if(parser->renderWindow == true && secondWindowRendered == false){
//        this->secondWindow = new MultipleWindows(300, 300);
//        secondWindow->setup("second window", 10, 10, 300, 300, false);
//        secondWindowRendered = true;
//    }
    
    
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
    
    for (int i = 0; i < numOfFrames; i++){
        if (frames[i]->startClick == true){
            verdana.drawString(frames[i]->typed->typedInput, editor->textStartX, editor->textStartY);

//            i = currentFrameState;
        }
    }
//    verdana.drawString(frames[currentFrameState]->typed->typedInput, editor->textStartX, editor->textStartY);


//    for (int i = 0; i < numOfFrames; i++){
//        if (frames[i]->currentFrame == true){
//            verdana.drawString(frames[i]->typed->typedInput, editor->textStartX, editor->textStartY);
//        }
//    }
//    if (float stringWidth(parser->typed)){
//        
//    }
//    cout<<"currentFrameState is " <<tempVariable<<endl;
//    
    for (int i = 0; i < numOfFrames; i++){
        if (frames[i]->startClick == true ){
            frames[i]->frameIsCurrent();
            cout<<i<<endl;
            
        }
    }
//        if (frames[i]->endClick == true){
//            frames[i]->endClicked = true;
//        }
//    }
//    cout << "is frame 0 current?" << frames[0]->currentFrame << endl;
//    cout << "is frame 1 current?" << frames[1]->currentFrame << endl;
//    cout << "is frame 2 current?" << frames[2]->currentFrame << endl;
//    cout << "is frame 3 current?" << frames[3]->currentFrame << endl;
//    cout << "is frame 4 current?" << frames[4]->currentFrame << endl;
//    cout << "is frame 5 current?" << frames[5]->currentFrame << endl;
//    cout << "is frame 6 current?" << frames[6]->currentFrame << endl;
//    cout << "is frame 7 current?" << frames[7]->currentFrame << endl;
//    cout << "is frame 8 current?" << frames[8]->currentFrame << endl;
    
    cout<< "frame 0 string: " << frames[0]->typed->typedInput << endl;
    cout<< "frame 1 string: " << frames[1]->typed->typedInput << endl;
    cout<< "frame 2 string: " << frames[2]->typed->typedInput << endl;
    cout<< "frame 3 string: " << frames[3]->typed->typedInput << endl;
    cout<< "frame 4 string: " << frames[4]->typed->typedInput << endl;
    cout<< "frame 5 string: " << frames[5]->typed->typedInput << endl;
    cout<< "frame 6 string: " << frames[6]->typed->typedInput << endl;
    cout<< "frame 7 string: " << frames[7]->typed->typedInput << endl;
    cout<< "frame 8 string: " << frames[8]->typed->typedInput << endl;

    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for (int i = 0; i < numOfFrames; i++){
        frames[i]->keyPressed(key);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    for (int i = 0; i < numOfFrames; i++){
        frames[i]->keyReleased(key);
    }
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
        numOfFrames = 9;
        numOfColumns = 3;
    }
    else {
        body1->mouseOver = false;
    }

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
        if (x< frames[i]->xPos || x > frames[i]->xPos + frameWidth || y < frames[i]->yPos || y > frames[i]->yPos + frameHeight){
            //            frames[i]->height = 10;
            frames[i]->startClick = false;
            
        }
        cout<<i<<endl;
    }
//    for (int i = 0; i < numOfFrames; i++){
//        frames[i]->mousePressed(x, y, button);
//    }
    
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
    
//    cout <<"frame0: " <<frames[0] -> endClick << endl;
//    cout <<"frame1: " <<frames[1] -> endClick << endl;
//    cout <<"frame2: " <<frames[2] -> endClick << endl;
//    cout <<"frame3: " <<frames[3] -> endClick << endl;
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    for (int i = 0; i < numOfFrames; i++){
        if (x > frames[i]->xPos && x < frames[i]->xPos + frameWidth && y > frames[i]->yPos && y < frames[i]->yPos + frameHeight){
            frames[i]->endClick = true;
        }
        if (x< frames[i]->xPos || x > frames[i]->xPos + frameWidth || y < frames[i]->yPos || y > frames[i]->yPos + frameHeight){
            //            frames[i]->height = 10;
            frames[i]->endClick = false;
            
        }
    }
    
//    for (int i = 0; i < numOfFrames; i++){
//        frames[i]->mouseReleased(x, y, button);
//    }

    head->xPos = 620;
    head->yPos = 305;
    leftEye->xPos = 586;
    leftEye->yPos = 328;
    rightEye->xPos = 661;
    rightEye->yPos = 328;
    
    if (headBeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        frames[0]->typed->typedInput = frames[0]->typed->typedInput + " head ";
    }
    if (leftEyeBeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        frames[0]->typed->typedInput = frames[0]->typed->typedInput + " eye ";
    }
    if (rightEyeBeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        frames[0]->typed->typedInput = frames[0]->typed->typedInput + " eye ";
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
