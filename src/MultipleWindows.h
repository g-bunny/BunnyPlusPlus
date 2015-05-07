//
//  MultipleWindows.h
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/2/15.
//  based on Gene Kogan's SecondWindow
//

#pragma once
#include <stdio.h>
#include "ofMain.h"
#include <GLFW/glfw3.h>
#include "ofxTransparentWindow.h"

class MultipleWindows {
    
public:
    MultipleWindows(int width, int height);
    void setup(const char *name, int xpos, int ypos, int width, int height, bool undecorated);
    void begin();
    void end();
    void show();
    void hide();
    void mousePressed(int x, int y, int button);
    void mouseDragged(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void keyPressed(int key);
    void keyReleased(int key);
    int getWidth() { return width; }
    int getHeight() { return height; }
    
private:
    GLFWwindow *mainWindow, *auxWindow;
    int width, height;
    ofxTransparentWindow transparent2;
    
};
