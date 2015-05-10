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
    
    for (int i = 0; i < tokens.size(); i++){
        if (tokens[i] =="play"){
            playWindow = true;
            cout<< "playWindow is " << playWindow << endl;
        }
    }
    for (int i = 0; i < tokens.size(); i++){
        if (tokens[i] =="eye"){
            eye = true;
            cout<< "eye is " << eye << endl;
        }
    }
    for (int i = 0; i < tokens.size(); i++){
        if (tokens[i] =="shape" && eye == true){
            shape = true;
            cout<< "playWindow is" << shape << endl;
        }
    }
    for (int i = 0; i < tokens.size(); i++){
        if (tokens[i] =="ear"){
            ear = true;
            cout<< "playWindow is" << ear << endl;
        }
    }
//    for (int i=0; i < tokens.size(); i++){
//        if (tokens[i] =="head"){
//            //when there is no head in the code, the head state is 0. if 1 head found, head state is 1
//            if (head == 0){head=1;}
//            //when there is already 1 head in the code, and another one is added, the head state is 2
//            //2 headstates would open and close the group of things inside this head function
//            else if (head ==1){head = 2;}
//            else if (head ==2){head = 0;}
//        }
//        if (tokens[i] =="arm"){
//            if (arm != true){arm=true;}
//        }
//        if (tokens[i] =="eye"){
//            if (eye != true){eye=true;}
//        }
//        if (tokens[i] =="leg"){
//            if (leg != true){leg = true;}
//        }
//        if (tokens[i] =="ear"){
//            if (ear != true){ear=true;}
//        }
//        if (tokens[i] =="body"){
//            if (body != true){body=true;}
//        }
//        if (tokens[i] =="bubble"){
//            if (bubble != true){bubble=true;}
//        }
//        if (tokens[i] =="play"){
//            playWindow = true;
//            cout<< "playWindow is" << playWindow << endl;
//        }
//        else if (tokens[i] == "circle"){
//            renderWindowWithCode = true;
//            cout<<"circle!"<<endl;
//        }
//        else if(tokens[i] == "no"){
//            renderWindowHideWindow = true;
//            renderWindowWithCode = false;
//        }
//    }
}
//float Parser::stringWidth(string s){
////    cout << stringWidth(typed) <<endl;
//}