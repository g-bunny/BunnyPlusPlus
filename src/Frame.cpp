//
//  Frame.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/2/15.
//
//

#include "Frame.h"

Frame::Frame(int xPos, int yPos, int width, int height, ofColor frameColor, bool startClick, bool endClick, int xPosText, int yPosText){
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;
    this->frameColor = frameColor;
    this->startClick = startClick;
    this->endClick = endClick;
    this->typed = new Typed ("");
    this->setup();
    this->xPosText = xPosText;
    this->yPosText = yPosText;
    
}

void Frame::setup(){
    ofTrueTypeFont::setGlobalDpi(72);
    verdana.loadFont("verdana.ttf", 14,true, true);
    verdana.setLineHeight(18.0f);
    verdana.setLetterSpacing(1.037);
    ofSetColor(frameColor);
    ofRect(xPos,yPos,width,height);
    
    //instantiating typed into frame
    typed->setup();
    
    //joints
    topLeft.set(xPos,yPos,0);
    botLeft.set(xPos, yPos+height, 0);
    top.set(xPos + width/2, yPos, 0);
    topRight.set(xPos + width, yPos, 0);
    bot.set(xPos + width/2, yPos + height, 0);
    botRight.set(xPos + width, yPos + height, 0);
    left.set(xPos, yPos + height/2,0);
    right.set(xPos + width, yPos + height/2, 0);
    startClick = false;
    endClick = false;
    this->plusButton = new Button(1);
}

void Frame::draw(){
    ofSetColor(frameColor);
    ofRect(xPos,yPos,width,height);
    typed->update();
    //testing joint positions
    if (startClick == true){
        ofSetColor(255,0,0,50);
        ofRect(xPos,yPos,width,height);
//        ofSetColor(255,0,0);
//        ofRect(topLeft,4,4);
//        ofRect(topRight,4,4);
//        ofRect(top,4,4);
//        ofRect(botLeft,4,4);
//        ofRect(botRight,4,4);
//        ofRect(bot,4,4);
//        ofRect(left,4,4);
//        ofRect(right,4,4);
    }
    
    if (endClick == true){
        ofSetColor(0, 0, 255,100);
        ofRect(xPos,yPos,width,height);
    }
    
//    if (startClicked == true && endClicked == true){
//        ofSetColor(255,255,255,100);
//        ofRect(xPos + 10,yPos + 10,width,height);
//        currentFrame = true;
//    }
    
    if (currentFrame == true){
    }
    cout << startClick <<endl;
    cout << endClick <<endl;
//    if (startClick == true && endClick == true && isAFrame == true){
//        startClicked = true;
//        endClicked = true;
//        startClick = false;
//        endClick = false;
    }
//    if (startClicked == true && endClicked == true){
//        ofSetColor(255, 255, 255, 100);
//        ofRect(xPos + 10, yPos + 10, width, height);
//        currentFrame = true;
//    }
//}
//void Frame::mousePressed(int x, int y, int button){
//    startClick = true;
//    cout<<"HI"<<endl;
//}
//
//void Frame::mouseReleased(int x, int y, int button){
//    endClick = true;
//}

void Frame::frameIsCurrent(){
    ofSetColor(255,0,0);
    ofNoFill();
    ofEllipse(xPos+width/2, yPos+width/2, width/4, height/4);
    ofFill();
    plusButton->xPos = xPos + width * 5/6;
    plusButton->yPos = yPos + width / 6;
    plusButton->width = 10;
    plusButton->height = 10;
    plusButton->drawPlus();
    pressedKey = true;
    verdana.drawString(typed->typedInput, xPosText, yPosText);
    this->parser = new Parser(typed->typedInput);
    parser->update();
    cout << "token size is" << parser->tokens.size()<<endl;
    if (parser->tokens.size() > 3){
        cout << "token 0 is " << parser->tokens[0] << endl;
        cout << "token 1 is " << parser->tokens[1] << endl;
        cout << "token 2 is " << parser->tokens[2] << endl;
    }
}

void Frame::keyPressed(int key){
    if(startClick == true){
        if (pressedKey == true){
            typed->keyPressed(key);
        }
    }
}
void Frame::keyReleased(int key){
    if(startClick == true){
        if (pressedKey == true){
            typed->keyReleased(key);
        }
    }
}