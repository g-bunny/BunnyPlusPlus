//
//  Typed.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/7/15.
//
//

#include "Typed.h"

Typed::Typed(string typedInput){
    this->typedInput = typedInput;
}

void Typed::setup(){
    typedInput = "";
}

void Typed::update(){
    //    cout<<typed<<endl;
    if (typedInput == ""){
        empty = true;
//        cout << "Im empty" << endl;
    }else{
    }
}

void Typed::keyPressed(int key){
    if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
        typedInput = typedInput.substr(0 , typedInput.length()-1);
    }
    else if(key == OF_KEY_RETURN){
        typedInput += "\n";
    }
}

void Typed::keyReleased(int key){
    if (key !=OF_KEY_DEL || key == OF_KEY_BACKSPACE){
        pressed = (char)key;
        typedInput = typedInput + pressed;
    }
}

//float Typed::stringWidth(string s){
//    //    cout << stringWidth(typed) <<endl;
//}