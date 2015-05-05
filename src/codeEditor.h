//
//  codeEditor.h
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/4/15.
//
//

#pragma once
#include "ofMain.h"

class CodeEditor{
public:
    CodeEditor(int xPos, int yPos, int width, int height);
    void setup();
    void draw();
    
    int xPos, yPos, width, height;
    int textAreaWidth;
    int textAreaHeight;
    int textStartX;
    int textStartY;
    

};