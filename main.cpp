/* 
 * File:   main.cpp
 * Author: paulocanedo
 *
 * Created on 23 de Agosto de 2012, 16:43
 */

#include <iostream>
#include <sstream>

#include "Image.h"
#include "Label.h"
#include "Button.h"
#include "RootContainer.h"
#include "RadioButton.h"
#include "Panel.h"
#include "gl3.h"
#include "CheckBoxButton.h"

RootContainer* rootc = new RootContainer();
Label* label1;
Label* label2;
Button* button;
RadioButton* rbutton1;
RadioButton* rbutton2;
RadioButton* rbutton3;
RadioButton* rbutton4;
CheckBoxButton* cbbutton1;
CheckBoxButton* cbbutton2;
Panel* panel;
Action* caction;
Image* image;

class CustomAction : public Action {

    void executed(Component *src) {
        label1->setText("Evento disparado.");

        RadioButton* selectedRB = rbutton1->querySelectedRadioButton();
        if (selectedRB == NULL) {
            label1->setText("Nenhum botão radio está selecionado.");
        } else {
            ostringstream ss;
            ss << "RadioButton selecionado: " << selectedRB->getText();
            string text = ss.str();
            label1->setText(text);
        }
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

void initComponents() {
    button = new Button();
    label1 = new Label();
    label2 = new Label();

    label1->setLocation(20, 0);
    label2->setLocation(20, 690);

    image = Image::loadImage("/home/paulocanedo-pc/Downloads/firefox11.png");
    //    label1->setImage(image);
    //    label1->setDimension(200, 200);
    //    label1->setAlign(Component::ComponentAlign::TopCenter);
    //    label1->setAlign(Component::ComponentAlign::MiddleCenter);
    //    label1->setAlign(Component::ComponentAlign::BottomCenter);
    //    label1->setForegroundColor(pcglYellow);
    //        label1->setBackgroundColor(pcglBootstrapBlue);

    int y = 80;
    int gap = 2;

    button->setLocation(20, 30);
    //    button->setDimension(300, 30);
    CustomAction *caction = new CustomAction();
    button->setAction(caction);
    button->setText("Button 1");

    rbutton1 = new RadioButton();
    rbutton1->setLocation(20, y);
    rbutton1->setText("RadioButton 1");

    y += rbutton1->getDimension().h + gap;
    rbutton2 = new RadioButton();
    rbutton2->setLocation(20, y);
    rbutton2->setText("RadioButton 2");

    y += rbutton1->getDimension().h + gap;
    rbutton3 = new RadioButton();
    rbutton3->setLocation(20, y);
    rbutton3->setText("RadioButton 3");

    y += rbutton1->getDimension().h + gap;
    rbutton4 = new RadioButton();
    rbutton4->setLocation(20, y);
    rbutton4->setText("RadioButton 4");

    rbutton1->setGroupId(1);
    rbutton2->setGroupId(1);
    rbutton3->setGroupId(1);
    rbutton4->setGroupId(1);
    
    cbbutton1 = new CheckBoxButton();
    cbbutton1->setText("CheckBox 1");
    cbbutton1->setLocation(200, 80);
    
    cbbutton2 = new CheckBoxButton();
    cbbutton2->setText("CheckBox 2");
    cbbutton2->setLocation(200, 105);
    
    panel = new Panel();
    panel->setDimension(1920 * 4, 1080 * 4);

    panel->add(label1);
    panel->add(label2);
    panel->add(rbutton1);
    panel->add(rbutton2);
    panel->add(rbutton3);
    panel->add(rbutton4);
    panel->add(cbbutton1);
    panel->add(cbbutton2);
    panel->add(button);
    rootc->add(panel);

    int a, b, c, i, j, k;
    glfwGetVersion(&a, &b, &c);
    glfwGetGLVersion(&i, &j, &k);

    ostringstream ss;
    ss << "GLFW Version: " << a << "." << b << "." << c << " | ";
    ss << "OpenGL Version: " << i << "." << j << "." << k << " | ";
    ss << "FSAA_SAMPLES: " << glfwGetWindowParam(GLFW_FSAA_SAMPLES);
    label2->setText(ss.str());
}

void deleteComponents() {
    delete rbutton1;
    delete rbutton2;
    delete rbutton3;
    delete rbutton4;
    delete cbbutton1;
    delete cbbutton2;
    delete panel;
    delete button;
    delete caction;
    delete image;
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
//    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
//    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 1);
//        glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

    // Open an OpenGL window
    if (!glfwOpenWindow(1280, 720, 0, 0, 0, 0, 32, 0, GLFW_WINDOW)) {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwSetWindowTitle("Capivara-GL Test");

    //    glEnable(GL_LINE_SMOOTH);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    //    glLineWidth(1.2f);

    glfwEnable(GLFW_KEY_REPEAT);
    glfwEnable(GLFW_STICKY_KEYS);

    glEnable(GL_MULTISAMPLE);
    glDisable(GL_DEPTH_TEST);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    initComponents();
    glfwSetKeyCallback(keyCallback);
    glfwSetCharCallback(charCallback);
    glfwSetWindowRefreshCallback(display);
    glfwSetWindowSizeCallback(reshape);
    glfwSetMousePosCallback(mousePosition);
    glfwSetMouseButtonCallback(mouseButton);
    //-------------------------------------------------------------------------
    // Main loop
    while (running) {
        display();
        glfwSwapBuffers();

        running = !glfwGetKey(GLFW_KEY_ESC) && glfwGetWindowParam(GLFW_OPENED);
    }
    deleteComponents();

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
 * checkbox - ok
 * GroupButtonControl - not necessary for moment ->groupId in RadioButton
 * button - ok
 * togglebutton
 * ComboBox
 */