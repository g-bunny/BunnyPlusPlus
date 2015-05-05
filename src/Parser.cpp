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
//    cout<<typed<<endl;
    tokens = ofSplitString(typed, " ");
    if (typed == ""){
//        cout << "Im empty" << endl;
    }

    for (string n : tokens) cout << n << ' ';
    
    if (tokens[0] =="run"){
        renderWindow = true;
    }
}

void Parser::keyPressed(int key){
    if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
        typed = typed.substr(0 , typed.length()-1);
    }
    else if(key == OF_KEY_RETURN){
        typed += "\n";
    }
}

void Parser::keyReleased(int key){
    if (key !=OF_KEY_DEL || key == OF_KEY_BACKSPACE){
        pressed = (char)key;
    }
    typed = typed + pressed;

    

}