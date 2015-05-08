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
    Parser();
    void setup();
    void update();
//    vector<Typed*> typed;
    vector<string> tokens;
    string toBeParsed;
    int tokenLength;
    bool empty;
    bool renderWindow, renderWindowWithCode, renderWindowHideWindow;
//    ofTrueTypeFont myFont;
};