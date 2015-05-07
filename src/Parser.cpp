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
    for (int i=0; i < tokens.size(); i++){
        if (tokens[i] =="run"){
            renderWindow = true;
            cout<< "renderWindow is" << renderWindow << endl;
        }
        else if (tokens[i] == "circle"){
            renderWindowWithCode = true;
            cout<<"circle!"<<endl;
        }
        else if(tokens[i] == "no"){
            renderWindowHideWindow = true;
            renderWindowWithCode = false;
        }
    }
    
    cout << "token size is" <<tokens.size()<<endl;
    cout << "token 0 is " << tokens[0] << endl;
//    cout << "token 1 is" << tokens[1] << endl;
//    cout << "token 2 is" << tokens[2] << endl;
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

float Parser::stringWidth(string s){
//    cout << stringWidth(typed) <<endl;
}