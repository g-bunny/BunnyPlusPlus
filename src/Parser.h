//
//  Parser.h
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/5/15.
//
//

#include "ofMain.h"

class Parser{
public:
    Parser(string typed);
    void setup();
    void update();
    void keyPressed(int key);
    void keyReleased(int key);
    string typed;
    vector<string> tokens;
    string pressed = "";
    int tokenLength;
    bool empty;
    bool renderWindow;
//    ofTrueTypeFont myFont;
};