//
//  Parser.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/5/15.
//
//

#include "Parser.h"

Parser::Parser(){
    
}

//Parser::Parser(int numOfStrings){
//    this->tokens = tokens;
//    this->pressed = pressed;
//    this->setup();
//    this->update();
//    this->numOfStrings = numOfStrings;
//}

void Parser::setup(){
}

void Parser::update(){
    tokens = ofSplitString(toBeParsed, " ");
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
    
//    cout << "token size is" <<tokens.size()<<endl;
//    cout << "token 0 is " << tokens[0] << endl;
//    cout << "token 1 is" << tokens[1] << endl;
//    cout << "token 2 is" << tokens[2] << endl;
}

//float Parser::stringWidth(string s){
////    cout << stringWidth(typed) <<endl;
//}