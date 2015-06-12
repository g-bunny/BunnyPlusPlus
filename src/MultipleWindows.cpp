//
//  MultipleWindows.cpp
//  BunnyPlusPlus
//
//  Created by Miri Park on 5/2/15.
//  based on Gene Kogan's SecondWindow
//

#include "MultipleWindows.h"

MultipleWindows::MultipleWindows(int width, int height){
    this->width = width;
    this->height = height;
}

void MultipleWindows::setup(const char *name, int xpos, int ypos, int width, int height, bool undecorated) {
    this->width = width;
    this->height = height;
    //    transparent.afterMainSetup(ofxTransparentWindow::NORMAL);
    
    glfwWindowHint(GLFW_DECORATED, !undecorated);
    mainWindow = glfwGetCurrentContext();
    auxWindow = glfwCreateWindow(width, height, name, NULL, mainWindow);
    //    GLFWwindow* auxWindow = glfwCreateWindow(width, height, name, NULL, mainWindow);
    glfwSetWindowPos(auxWindow, xpos, ypos);
    
    /* enable alpha blending by default */
    glfwMakeContextCurrent(auxWindow);
    glEnable(GL_BLEND);
#ifndef TARGET_OPENGLES
    glBlendEquation(GL_FUNC_ADD);
#endif
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glfwMakeContextCurrent(mainWindow);
    transparent2.afterMainSetup(ofxTransparentWindow::NORMAL);

}

void MultipleWindows::begin(){
    glfwMakeContextCurrent(auxWindow);
    int width, height;
    glfwGetFramebufferSize(auxWindow, &width, &height);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MultipleWindows::end(){
    glfwSwapBuffers(auxWindow);
    glfwPollEvents();
    glfwMakeContextCurrent(mainWindow);
}

void MultipleWindows::show(){
    glfwShowWindow(auxWindow);
}

void MultipleWindows::hide(){
    glfwHideWindow(auxWindow);
//    glfwDestroyWindow(auxWindow);

}

void MultipleWindows::destroy(){
    glfwDestroyWindow(auxWindow);
}
void MultipleWindows::mousePressed(int x, int y, int button){
    //    if(mouseDragged == true){
    glfwDestroyWindow(auxWindow);
    cout << "mouseDragged" << x << "," << y << " button: " << button << endl;
    if (x > 10) {
        cout << "WOOHOO!" << endl;
    }
}
void MultipleWindows::mouseDragged(int x, int y, int button){
    //    if(mouseDragged == true){
    cout << "mouseDragged" << x << "," << y << " button: " << button << endl;
    if (x > 10) {
        cout << "WOOHOO!" << endl;
    }
}

void MultipleWindows::mouseReleased(int x, int y, int button){
    
}

void MultipleWindows::keyPressed(int key){
    
}

void MultipleWindows::keyReleased(int key){
    
}