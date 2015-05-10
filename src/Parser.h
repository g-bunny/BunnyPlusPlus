//
//  Parser.h
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/5/15.
//
//

#include "ofMain.h"
//#include "Typed.h"

class Parser{
public:
    Parser(string toBeParsed);
    void setup();
    void update();
//    vector<Typed*> typed;
    vector<string> tokens;
    string toBeParsed;
    int tokenLength;
    bool empty;
    bool playWindow = false;
    bool renderWindowWithCode, renderWindowHideWindow;
    
    bool head, ear, eye = false;
    bool body, arm, leg, bubble;
    bool shape, circle, color, red;
//    ofTrueTypeFont myFont;
};