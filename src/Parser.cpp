//
//  Parser.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/5/15.
//
//

#include "Parser.h"

Parser::Parser(string typed){
    this->typed = typed;
    this->tokens = tokens;
    this->pressed = pressed;
    this->setup();
    this->update();
}

void Parser::setup(){
    typed = "";
    
}

void Parser::update(){
    cout<<typed<<endl;
    tokens = ofSplitString(typed, " ");
    if (typed == ""){
        cout << "Im empty" << endl;
    }
    cout << "Im a token!" << tokens[0] << endl;
    if (tokens[0] =="run"){
        renderWindow = true;
    }
}

void Parser::keyReleased(int key){
    pressed = (char)key;
    typed = typed + pressed;
}