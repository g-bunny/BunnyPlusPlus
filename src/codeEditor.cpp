//
//  codeEditor.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/4/15.
//
//

#include "CodeEditor.h"

CodeEditor::CodeEditor(int xPos, int yPos, int width, int height){
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;
    this->setup();
}

void CodeEditor::setup(){
    
//    xPos = 800;
//    yPos = 50;
//    width = 495;
//    height = 800;
}

void CodeEditor::draw(){
    ofSetColor(255,255,255);
    ofRect(xPos, yPos, width, height);
    ofSetColor(100, 100, 100);
    ofRect(xPos + 10, yPos + 10, width - 20, 10);
    textAreaWidth = width - 20;
    textStartX = xPos + 10;
    textStartY = yPos + 35;
}