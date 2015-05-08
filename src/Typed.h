//
//  Typed.h
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/7/15.
//
//

#include "ofMain.h"

class Typed{
public:
    Typed(string typedInput);
    void setup();
    void update();
    void keyPressed(int key);
    void keyReleased(int key);
    string typedInput;
    string pressed = "";
    int state;
    bool empty;
};