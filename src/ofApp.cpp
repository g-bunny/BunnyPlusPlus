#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    logo.loadImage("bunnyPlusPlusLogo.png");
    flyingBunny.loadImage("flyingBunny.png");
    ofTrueTypeFont::setGlobalDpi(72);
    verdana.loadFont("verdana.ttf", 20,true, true);
    verdana.setLineHeight(18.0f);
    verdana.setLetterSpacing(1.037);
    
    frameHeight = 125;
    frameWidth = 125;
    halfH = frameHeight/2;
    halfW = frameWidth/2;
    buffer = 20;
    numOfFrames = 200;
    numOfColumns = 3;
    
    this->editor = new CodeEditor(1000,50,505,700);
    
    const float identityScale = 1.0f;
    const ofColor black = ofColor(0, 0, 0);
    const ofColor red = ofColor(255, 0, 0);
    const ofColor purple = ofColor(205, 0, 255);
    
    const float earScaleX = 0.8f;
    const float earScaleY = identityScale;
    const float earScaleZ = identityScale;
    initialEar1X = 625;
    initialEar1Y = 295;
    initialEar2X = 715;
    initialEar2Y = 295;
    this->ear1 = new WaterDrop(earScaleX, earScaleY, earScaleZ, initialEar1X, initialEar1Y, 100, 180, lighterTeal, false);
    this->ear2 = new WaterDrop(earScaleX, earScaleY, earScaleZ, initialEar2X, initialEar2Y, 100, 180, lighterTeal, false);
    
    const float legScaleX = 0.8;
    const float legScaleY = 1.0f;
    const float legScaleZ = 1.0f;
    initialLeg1X = 605;
    initialLeg1Y = 495;
    initialLeg2X = 645;
    initialLeg2Y = 502;
    this->leg1 = new WaterDrop(legScaleX, legScaleY, legScaleZ, initialLeg1X, initialLeg1Y, 100, 10,darkestTeal, false);
    this->leg2 = new WaterDrop(legScaleX, legScaleY, legScaleZ, initialLeg2X, initialLeg2Y, 100, -10,darkestTeal, false);
    leg1->mouseOverColor = ofColor(104,200,0,180);
    leg2->mouseOverColor = ofColor(104,200,0,180);
    
    const float armScaleX = 0.8f;
    const float armScaleY = 0.8f;
    const float armScaleZ = identityScale;
    this->arm1 = new WaterDrop(armScaleX, armScaleY, armScaleZ, 628, 380, 50, 90, darkestTeal, false);
    arm1->mouseOverColor = ofColor(255,100,100);
    this->arm2 = new WaterDrop(armScaleX, armScaleY, armScaleZ, 642, 425, 50, 270, darkestTeal, false);
    arm2->mouseOverColor = ofColor(255,100,100);
    const float bodyScaleX = 1.0f;
    const float bodyScaleY = 1.0f;
    const float bodyScaleZ = identityScale;
    this->body1 = new Body(bodyScaleX, bodyScaleY, bodyScaleZ, 0, 0, 0,620, 250, 500, 600, 750, 600, darkerTeal, false);

    const float headScaleX = identityScale;
    const float headScaleY = identityScale;
    const float headScaleZ = identityScale;
    this->head = new Head(headScaleX, headScaleY, headScaleZ, 620,305,200,200, teal , false);
    
    const float leftEyeScaleX = identityScale;
    const float leftEyeScaleY = identityScale;
    const float leftEyeScaleZ = identityScale;
    this->leftEye = new Head(leftEyeScaleX, leftEyeScaleY, leftEyeScaleZ, 586, 328, 10, 10, black, false);
    
    const float rightEyeScaleX = identityScale;
    const float rightEyeScaleY = identityScale;
    const float rightEyeScaleZ = identityScale;
    this->rightEye = new Head(rightEyeScaleX, rightEyeScaleY, rightEyeScaleZ, 661, 328, 10, 10, black, false);
    
    this->bubble = new Bubble(815,261,160,122,lightRed, false);
    
        ofEllipse(815, 261, 160, 122);

    const ofColor lavender = ofColor(176,183,255);
    for (int i = 0; i < numOfFrames; i++){
        frames.resize(numOfFrames);
        this->frames[i] = new Frame((i%numOfColumns+1)*buffer + (i%numOfColumns)*frameWidth,
                             (1+floor(i/float(numOfColumns)))*buffer + (floor(i/float(numOfColumns)))*frameHeight,
                             frameWidth, frameHeight, lavender,false, false, editor->textStartX, editor->textStartY);
    }
    
    this->plusButton = new UIButton(1);
    this->minusButton = new UIButton(2);
    
    plusButton->xPos = 600;
    plusButton->yPos = 10;
    plusButton->width = 12;
    plusButton->height = 12;
    plusButton->defaultColor = ofColor(0,255,255);
    plusButton->numberToAlter = numOfFrames;
    minusButton->xPos = 620;
    minusButton->yPos = 10;
    minusButton->width = 12;
    minusButton->height = 12;
    minusButton->defaultColor = ofColor(0,255,255);
    minusButton->numberToAlter = numOfFrames;
//    xPos, yPos, width, height
//    for (int i = 0; i < numOfFrames; i++){
//        parser.resize(numOfFrames);
//        this->parser[i] = new Parser("");
//    }
//    this->parser = new Parser(currentFrameState);
//    for (int i = 0; i < numOfFrames; i++){
//        parser->typed.resize(numOfFrames);
//    }
    
    //defaulting frames[0] as current
    frames[0]->frameIsCurrent();
    

    
    transparent.afterMainSetup(ofxTransparentWindow::NORMAL);
}

//--------------------------------------------------------------
void ofApp::update(){
    if (startingFrameCount == true){
        numOfFrames = 1;
    }
    if (startingColumnCount == true){
        numOfColumns = 3;
    }
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
////        cout << parser[0]->renderWindowWithCode << endl;
//    }
//    for (int i; i < numOfFrames; i++){
//        if(frames[i]->parser->playWindow == true && secondWindowRendered == false){
//            this->secondWindow = new MultipleWindows(300, 300);
//            secondWindow->setup("second window", 10, 10, 300, 300, false);
//            secondWindowRendered = true;
//        }
//    }
//    for (int i; i < numOfFrames; i++){
//        if(frames[i]->parser->eye == true && secondWindowRendered == true){
//            secondWindow->begin();
//            ofEllipse(10,10,10,10);
//            secondWindow->end();
//            
//        }
//    }
    xPosMovingRight = (ofGetElapsedTimeMillis() % 10000) / 10;

    if(frames[0]->parser->playWindow == true && secondWindowRendered == false){
        this->secondWindow = new MultipleWindows(300, 300);
        secondWindow->setup("second window", 800, 10, 1000, 500, false);
        secondWindowRendered = true;
    }
    if(frames[0]->parser->body == true && secondWindowRendered == true){
        secondWindow->begin();
        flyingBunny.draw(0,300,200,90);
        secondWindow->end();
        
    }
    if (frames[0]->parser->ear == true && secondWindowRendered == true){
        secondWindow->begin();
        ofEllipse(100,100,100,100);
        secondWindow->end();
    }
    if(frames[0]->parser->bubble == true && secondWindowRendered == true){
        secondWindow->begin();
        ofSetColor(255,255,255);
        verdana.drawString("Hello World", 300, 100);
        secondWindow->end();

    }
    if(frames[0]->parser->stop == true && secondWindowRendered == true){
        secondWindow->hide();
        
    }
    if (frames[0]->parser->leg == true && secondWindowRendered == true){
        secondWindow->begin();
        float bunnyXPos;
        float bunnyYPos;
        float startingXPos = 0;
        float startingYPos = 300;
        float xPosMoving;
            bunnyXPos = startingXPos;
        
        bunnyXPos = 0;
        bunnyYPos = 400;
        //        logo.draw(editor->xPos, editor->yPos + editor->height - 60, 50, 60);
        flyingBunny.draw(bunnyXPos + xPosMovingRight, startingYPos, 200,90);
        //ofEllipse(bunnyXPos + xPosMoving, bunnyYPos, 90, 90);
        //cout << ofGetElapsedTimeMillis() << endl;


        secondWindow->end();
    }
//    if(frames[1]->parser->playWindow == true && secondWindowRendered == false){
//        this->secondWindow = new MultipleWindows(300, 300);
//        secondWindow->setup("second window", 10, 10, 300, 300, false);
//        secondWindowRendered = true;
//    }
//    if(frames[1]->parser->eye == true && secondWindowRendered == true){
//        secondWindow->begin();
//        ofEllipse(10,10,10,10);
//        secondWindow->end();
//        
//    }
//    if (frames[1]->parser->ear == true && secondWindowRendered == true){
//        secondWindow->begin();
//        ofEllipse(100,100,100,100);
//        secondWindow->end();
//    }
    
//    if(parser->renderWindow == true){
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
    // drawing lines between frames
    
    for (int i = 0; i < numOfFrames; i++){
        if (frames[i]->startClick ==true){
            ofPoint start = ofPoint (frames[i]->xPos + frames[i]->width/2, frames[i]->yPos + frames[i]->height/2);
            for (int i = 0; i < numOfFrames; i++){
                if (frames[i]->endClick == true){
                    ofPoint end = ofPoint (frames[i]->xPos + frames[i]->width/2, frames[i]->yPos + frames[i]->height/2);
                    ofSetColor(lightRed);
                    ofLine(start,end);
                }
            }
        }
    }
    //to be used to calculate area of body
    areaOfTriangle = (ABS(body1->xPosRight*(body1->yPos - body1->yPosLeft) + body1->xPos *(body1->yPosLeft - body1->yPosRight) + body1->xPosLeft*(body1->xPosRight - body1->yPos))/2);
    editor->draw();
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
    bubble->draw();


    plusButton->drawPlus();
    minusButton->drawMinus();
    
    for (int i = 0;  i < numOfFrames; i++){
        frames[i]->frameColor = lavender;
        frames[i]->draw();
    }
        logo.draw(editor->xPos, editor->yPos + editor->height - 60, 50, 60);
//      cout << frames[0]->startClick <<endl;
//    ofSetColor(0, 0, 0);
//    ofBeginShape();
//        ofVertex(90, 100);
//        ofVertex(0, 300);
//        ofVertex(180, 300);
//    ofEndShape();
    
    for (int i = 0; i < numOfFrames; i++){
        if (frames[i]->endClick == true){
            verdana.drawString(frames[i]->typed->typedInput, editor->textStartX, editor->textStartY);
            stringWidth = stringInitialWidth + verdana.stringWidth(frames[i]->typed->typedInput);
            float stringHeight = verdana.stringHeight(frames[i]->typed->typedInput);
            cout <<"string width is " << stringWidth <<endl;
            if (stringWidth >= maxStringWidth){
                stringMaxReached = true;
            }
            if (stringMaxReached == true){
                frames[i]->typed->typedInput = frames[i]->typed->typedInput + '\n';
                stringMaxReached = false;
                stringInitialWidth = -1 * maxStringWidth;
            }
            
            
//            cout << float ofTrueTypeFont::stringWidth(frames[i]->typed->typedInput) <<endl;
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
        if (frames[i]->endClick == true){
            frames[i]->frameIsCurrent();
            cout<<i<<endl;
        }
    }
//    ofBackground(100,100,100);
    ofSetColor(100, 100, 100, 200);
    ofRect(0, 0, 460, 10);
    ofRect(0,0,10,800);

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
    
    //checking if in bubble
    //    ofEllipse(815, 261, 160, 122);
    if(ofDist(815,261,x,y) <= 150){
        bubble->mouseOver = true;
    }else{
        bubble->mouseOver = false;
    }
    leftArmCenterX = 500;
    leftArmCenterY = 402;
    rightArmCenterX = 750;
    rightArmCenterY = 402;
    
    leftLegCenterX = 570;
    leftLegCenterY = 660;
    rightLegCenterX = 680;
    rightLegCenterY = 660;
    
    leftEarCenterX = 565;
    leftEarCenterY = 100;
    rightEarCenterX = 675;
    rightEarCenterY = 100;
    
    //checking if in left arm
    if(ofDist(leftArmCenterX,leftArmCenterY,x,y) <= 30){
        arm1->mouseOver = true;
    }else{
        arm1->mouseOver = false;
    }
    //checking if in right arm
    if(ofDist(rightArmCenterX,rightArmCenterY,x,y) <= 30){
        arm2->mouseOver = true;
    }else{
        arm2->mouseOver = false;
    }
    
    //checking legs
    if(ofDist(leftLegCenterX, leftLegCenterY, x, y) <= 35){
        leg1->mouseOver = true;
    }else{
        leg1->mouseOver = false;
    }
    if(ofDist(rightLegCenterX, rightLegCenterY, x, y) <= 35){
        leg2->mouseOver = true;
    }else{
        leg2->mouseOver = false;
    }
    
    //checking ears
    if(ofDist(leftEarCenterX, leftEarCenterY, x, y) < 30){
        ear1->mouseOver = true;
    } else {
        ear1->mouseOver = false;
    }
    if(ofDist(rightEarCenterX, rightEarCenterY, x, y) < 30){
        ear2->mouseOver = true;
    } else {
        ear2->mouseOver = false;
    }
    //checking if in triangle / body
    
    areaOfSubtriangle1 = ABS(x*(body1->yPos - body1->yPosLeft) + body1->xPos *(body1->yPosLeft - y) + body1->xPosLeft*(y - body1->yPos))/2;
    areaOfSubtriangle2 = ABS(x*(body1->yPos - body1->yPosRight) + body1->xPos *(body1->yPosRight - y) + body1->xPosRight*(y - body1->yPos))/2;
    areaOfSubtriangle3 = ABS(x*(body1->yPosRight - body1->yPosLeft) + body1->xPosRight *(body1->yPosLeft - y) + body1->xPosLeft*(y - body1->yPosRight))/2;
    
    if (areaOfSubtriangle1 + areaOfSubtriangle2 + areaOfSubtriangle3 == areaOfTriangle + 75* body1->xPosLeft && head->mouseOver != true){
        body1->mouseOver = true;
//        numOfFrames = 9;
//        numOfColumns = 3;
    }
    else {
        body1->mouseOver = false;
    }

    if (x >= plusButton->xPos && x <= plusButton->xPos + plusButton->width && x>= plusButton->yPos && x <= plusButton->yPos + plusButton->height){
        plusButton->defaultColor = lightRed;
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    if (y >=0 && y <= 10){
        for (int i = 0; i < numOfFrames; i++){
            if (frames[i]->endClick == true){
                frames[i]->width = frames[i]->width + int(x/20);
                buffer = buffer + int(x/20);
            }
        }
//        startingColumnCount = false;
//        numOfColumns = int(x/30);
        
    }
    if (x>=0 && x<=10){
        startingFrameCount = false;
        numOfFrames = int(y/10);
    }
    
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
    
    if(bubble->mouseOver == true){
        bubble->xPos = x;
        bubble->yPos = y;
        bubbleBeingDragged = true;
    }
    
    
    //arms
    
    leftArmCenterX = 500;
    leftArmCenterY = 402;
    rightArmCenterX = 750;
    rightArmCenterY = 402;
    
    if(arm1->mouseOver == true){
        arm1->transX = 628 + (x - leftArmCenterX);
        arm1->transY = 380 + (y - leftArmCenterY);
        arm1BeingDragged = true;
    }
    if(arm2->mouseOver == true){
        arm2->transX = 642 + (x - rightArmCenterX);
        arm2->transY = 425 + (y - rightArmCenterY);
        arm2BeingDragged = true;
    }
    leftLegCenterX = 570;
    leftLegCenterY = 660;
    rightLegCenterX = 680;
    rightLegCenterY = 660;
    
    //legs
    
    if(leg1->mouseOver == true){
        leg1->transX = initialLeg1X + (x-leftLegCenterX);
        leg1->transY = initialLeg1Y + (y-leftLegCenterY);
        leftLegBeingDragged = true;
    }
    if(leg2->mouseOver == true){
        leg2->transX = initialLeg2X + (x-rightLegCenterX);
        leg2->transY = initialLeg2Y + (y-rightLegCenterY);
        rightLegBeingDragged = true;
    }
       
       
    leftEarCenterX = 565;
    leftEarCenterY = 50;
    rightEarCenterX = 675;
    rightEarCenterY = 50;
    
    //ears
    if(ear1->mouseOver == true){
        ear1->transX = initialEar1X + (x-leftEarCenterX);
        ear1->transY = initialEar1Y + (y-60-leftEarCenterY);
        leftEarBeingDragged = true;
    }
    if(ear2->mouseOver==true){
        ear2->transX = initialEar2X + (x-rightEarCenterX);
        ear2->transY = initialEar2Y + (y-60-rightEarCenterY);
        rightEarBeingDragged = true;
    }
       
    //body
    
    bodyCenterPointX = 600;
    bodyCenterPointY = 425;
    bodyDifferenceX = x - bodyCenterPointX;
    bodyDifferenceY = y - bodyCenterPointY;
    
    if(body1->mouseOver ==true){
        bodyCenterPointX = 600;
        bodyCenterPointY = 425;
        bodyDifferenceX = x - bodyCenterPointX;
        bodyDifferenceY = y - bodyCenterPointY;
        body1->xPos = 620 + bodyDifferenceX;
        body1->yPos = 250 + bodyDifferenceY;
        body1->xPosLeft = 500 + bodyDifferenceX;
        body1->yPosLeft = 600 + bodyDifferenceY;
        body1->xPosRight = 750 + bodyDifferenceX;
        body1->yPosRight = 600 + bodyDifferenceY;
        body1BeingDragged = true;
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    headBeingDragged = false;
    leftEyeBeingDragged = false;
    rightEyeBeingDragged = false;
    arm1BeingDragged = false;
    arm2BeingDragged = false;
    leftLegBeingDragged = false;
    rightLegBeingDragged = false;
    leftEarBeingDragged = false;
    rightEarBeingDragged =  false;
    body1BeingDragged = false;
    bubbleBeingDragged = false;
    
    for (int i = 0; i < numOfFrames; i++){
        if (x > frames[i]->xPos && x < frames[i]->xPos + frameWidth && y > frames[i]->yPos && y < frames[i]->yPos + frameHeight){
            frames[i]->startClick = true;
//            frames[i]->height = 10;
//            frames[i]->startClick = true;
            for (int i = 0; i < numOfFrames; i++){
                frames[i]->endClick = false;
            }
            whatObjectIsClicked = 1;
        }
//        if (x< frames[i]->xPos || x > frames[i]->xPos + frameWidth || y < frames[i]->yPos || y > frames[i]->yPos + frameHeight){
//            //            frames[i]->height = 10;
//            frames[i]->startClick = false;
//            
//        }
        cout<<i<<endl;
    }
    
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
//    for (int i =0; i < numOfFrames; i ++){
//        if (x > frames[i]->xPos && x < frames[i]->xPos + frameWidth && y > frames[i]->yPos && y < frames[i]->yPos + frameHeight){
//            frames[i]->endClick = false;
//        }
//    }
    for (int i = 0; i < numOfFrames; i++){
        if (x > frames[i]->xPos && x < frames[i]->xPos + frameWidth && y > frames[i]->yPos && y < frames[i]->yPos + frameHeight){
            whatObjectIsClicked = 1;
            frames[i]->endClick = true;
        }

    }
    head->xPos = 620;
    head->yPos = 305;
    leftEye->xPos = 586;
    leftEye->yPos = 328;
    rightEye->xPos = 661;
    rightEye->yPos = 328;
    body1->xPos = 620;
    body1->yPos = 250;
    body1->xPosLeft = 500;
    body1->yPosLeft = 600;
    body1->xPosRight = 750;
    body1->yPosRight = 600;
    arm1->transX = 628;
    arm1->transY = 380;
    arm2->transX = 642;
    arm2->transY = 425;
    leg1->transX = initialLeg1X;
    leg1->transY = initialLeg1Y;
    leg2->transX = initialLeg2X;
    leg2->transY = initialLeg2Y;
    ear1->transX = initialEar1X;
    ear1->transY = initialEar1Y;
    ear2->transX = initialEar2X;
    ear2->transY = initialEar2Y;
    bubble->xPos = 815;
    bubble->yPos = 261;
    if (headBeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        dontChangeState = true;
        whatObjectIsClicked = 2;
        for (int i = 0; i < numOfFrames; i ++){
            if (frames[i]->endClick == true){
                frames[i]->typed->typedInput = frames[i]->typed->typedInput + " head ";
            }
        }
        
    }
    if (leftEyeBeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        whatObjectIsClicked = 3;
        for (int i = 0; i < numOfFrames; i ++){
            if (frames[i]->endClick == true){
                frames[i]->typed->typedInput = frames[i]->typed->typedInput + " eye ";
            }
        }
    }
    if (rightEyeBeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        whatObjectIsClicked = 3;
        for (int i = 0; i < numOfFrames; i ++){
            if (frames[i]->endClick == true){
                frames[i]->typed->typedInput = frames[i]->typed->typedInput + " eye ";
            }
        }
    }
    if (body1BeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        for (int i = 0; i < numOfFrames; i ++){
            if (frames[i]->endClick == true){
                frames[i]->typed->typedInput = frames[i]->typed->typedInput + " body ";
            }
        }
        whatObjectIsClicked =4;
    }
    if (arm1BeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        for (int i = 0; i < numOfFrames; i ++){
            if (frames[i]->endClick == true){
                frames[i]->typed->typedInput = frames[i]->typed->typedInput + " arm ";
            }
        }
        whatObjectIsClicked = 5;
    }
    if (arm2BeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        for (int i = 0; i < numOfFrames; i ++){
            if (frames[i]->endClick == true){
                frames[i]->typed->typedInput = frames[i]->typed->typedInput + " arm ";
            }
        }
        whatObjectIsClicked = 5;
    }
    if (leftLegBeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        for (int i = 0; i < numOfFrames; i ++){
            if (frames[i]->endClick == true){
                frames[i]->typed->typedInput = frames[i]->typed->typedInput + " leg ";
            }
        }
        whatObjectIsClicked = 6;
    }
    if (rightLegBeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        for (int i = 0; i < numOfFrames; i ++){
            if (frames[i]->endClick == true){
                frames[i]->typed->typedInput = frames[i]->typed->typedInput + " leg ";
            }
        }
        whatObjectIsClicked = 6;
    }
    if (leftEarBeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        for (int i = 0; i < numOfFrames; i ++){
            if (frames[i]->endClick == true){
                frames[i]->typed->typedInput = frames[i]->typed->typedInput + " ear ";
            }
        }
        whatObjectIsClicked = 7;
    }
    if (rightEarBeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        for (int i = 0; i < numOfFrames; i ++){
            if (frames[i]->endClick == true){
                frames[i]->typed->typedInput = frames[i]->typed->typedInput + " ear ";
            }
        }
        whatObjectIsClicked = 7;
    }
    if (bubbleBeingDragged == true && x > editor->xPos && x < editor->xPos + editor->width){
        for (int i = 0; i < numOfFrames; i ++){
            if (frames[i]->endClick == true){
                frames[i]->typed->typedInput = frames[i]->typed->typedInput + " bubble ";
            }
        }
        whatObjectIsClicked = 8;
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
