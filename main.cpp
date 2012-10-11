/* 
 * File:   main.cpp
 * Author: paulocanedo
 *
 * Created on 23 de Agosto de 2012, 16:43
 */

#include <GL/glew.h>
#include "gl3.h"
#include <GL/glfw.h>
#include <cstdlib>
#include <iostream>
#include <sstream>

#include "Image.h"
#include "Label.h"
#include "Button.h"
#include "RootContainer.h"
#include "RadioButton.h"
#include "Panel.h"

using namespace std;

RootContainer* rootc = new RootContainer();
Label* label1 = new Label();

class CustomAction : public Action {

    void executed(Component *src) {
        label1->setText("Evento disparado.");
    }
};

void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    rootc->render();
}

void charCallback(int key, int action) {
}

void keyCallback(int key, int action) {
}

void reshape(int width, int height) {
    glLoadIdentity();
    glViewport(0, 0, width, height);
    glOrtho(0, width, height, 0, -1, 1);
}

void mousePosition(int x, int y) {
    rootc->mousePosition(x, y);

    ostringstream ss;
    ss << "X: " << x << ", Y: " << y;
    string text = ss.str();
    label1->setText(text);
}

void mouseButton(int button, int state) {
    rootc->mouseButton(button, state);
}

/*
 * 
 */
int main(int argc, char** argv) {
    int running = GL_TRUE;
    // Initialize GLFW
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4); // 4x antialiasing
    // Open an OpenGL window
    if (!glfwOpenWindow(1280, 720, 0, 0, 0, 0, 0, 0, GLFW_WINDOW)) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    GLenum result = glewInit();
    if (result != GLEW_OK) {
        cerr << "Failed to initialize GLEW: " << result << endl;
        exit(-1);
    }
    
    cout << "FSAA_SAMPLES: " << glfwGetWindowParam(GLFW_FSAA_SAMPLES) << endl;

//    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
//    glLineWidth(1.5f);

    glfwEnable(GLFW_KEY_REPEAT);
    glfwEnable(GLFW_STICKY_KEYS);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glfwSetKeyCallback(keyCallback);
    glfwSetCharCallback(charCallback);
    glfwSetWindowRefreshCallback(display);
    glfwSetWindowSizeCallback(reshape);
    glfwSetMousePosCallback(mousePosition);
    glfwSetMouseButtonCallback(mouseButton);
    //-------------------------------------------------------------------------
    //    Label* label1 = new Label();
    //    label1->setText("Render\npaulo\nterceira linha\nquarta linha\n6alinha");
//    label1->setLocation(250, 300);
    
    Image* image = Image::loadImage("/home/paulocanedo-pc/Downloads/firefox11.png");
//    label1->setImage(image);
    //    label1->setDimension(200, 200);
    //    label1->setAlign(Component::ComponentAlign::TopCenter);
    //    label1->setAlign(Component::ComponentAlign::MiddleCenter);
    //    label1->setAlign(Component::ComponentAlign::BottomCenter);
    //    label1->setForegroundColor(pcglYellow);
//        label1->setBackgroundColor(pcglBootstrapBlue);
    
    int y = 80;
    int increase = 30;
    int gap = 2;

    Button* button = new Button();
    button->setLocation(20, 30);
    button->setDimension(300, 30);
    CustomAction *caction = new CustomAction();
    button->setAction(caction);
    
    RadioButton* rbutton1 = new RadioButton();
    rbutton1->setLocation(20, y);
    rbutton1->setDimension(300, 30);
    
    y += increase + gap;
    RadioButton* rbutton2 = new RadioButton();
    rbutton2->setLocation(20, y);
    rbutton2->setDimension(300, 30);
    
    y += increase + gap;
    RadioButton* rbutton3 = new RadioButton();
    rbutton3->setLocation(20, y);
    rbutton3->setDimension(300, 30);
    
    y += increase + gap;
    RadioButton* rbutton4 = new RadioButton();
    rbutton4->setLocation(20, y);
    rbutton4->setDimension(300, 30);
    
    Panel* panel = new Panel();
    panel->setDimension(1920 * 4, 1080 * 4);
    panel->add(label1);
    
    rootc->add(panel);
    rootc->add(rbutton1);
    rootc->add(rbutton2);
    rootc->add(rbutton3);
    rootc->add(rbutton4);
    rootc->add(button);
    //-------------------------------------------------------------------------
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDisable(GL_DEPTH);
    glEnable(GL_MULTISAMPLE);

    // Main loop
    while (running) {
        display();
        glfwSwapBuffers();

        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
    }
    delete image;
    // Close window and terminate GLFW
    glfwTerminate();
    return EXIT_SUCCESS;
}

/**
 * controle do focus
 * Menu contextual
 * TextField
 * render de imagem - ok
 * Borda - ok
 * Painel - ok
 * Bindings de posicao
 * barra de progresso
 * radiobutton - ok
 * checkbox
 * GroupButtonControl
 * button - ok
 * togglebutton
 * ComboBox
 */