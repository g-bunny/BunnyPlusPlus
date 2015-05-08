//
//  Parser.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/5/15.
//
//

#include "Parser.h"

Parser::Parser(string toBeParsed){
    this->toBeParsed = toBeParsed;
}

//Parser::Parser(int numOfStrings){
//    this->tokens = tokens;
//    this->pressed = pressed;
//    this->setup();
//    this->update();
//    this->numOfStrings = numOfStrings;
//}

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
}
//float Parser::stringWidth(string s){
////    cout << stringWidth(typed) <<endl;
//}