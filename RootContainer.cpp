/* 
 * File:   RootContainer.cpp
 * Author: paulocanedo
 * 
 * Created on 21 de Setembro de 2012, 09:36
 */

#include "RootContainer.h"

RootContainer::RootContainer() {
}

RootContainer::RootContainer(const RootContainer& orig) {
}

RootContainer::~RootContainer() {
}

void RootContainer::add(Panel* c) {
    container.push_back(c);
}

void RootContainer::mousePosition(int x, int y) {
    this->mouseLocation.x = x;
    this->mouseLocation.y = y;

    for (vector<Panel*>::iterator it = container.begin(); it != container.end(); ++it) {
        if ((*it)->cover(x, y)) {
            if (!(*it)->isStateHover() && !(*it)->isStatePressed())
                (*it)->mouseEntered();
        } else {
            if ((*it)->isStateHover())
                (*it)->mouseExited();
        }

        (*it)->mouseMoved(x, y);
    }
}

void RootContainer::mouseButton(int button, int state) {
    int x, y;
    glfwGetMousePos(&x, &y);

    for (vector<Panel*>::iterator it = container.begin(); it != container.end(); ++it) {
        if ((*it)->cover(x, y)) {
            if (state == GLFW_PRESS) {
                (*it)->mousePressed(button, x, y);
            } else if (state == GLFW_RELEASE) {
                (*it)->mouseReleased(button, x, y);
            }
        } else if (state == GLFW_RELEASE) {
            (*it)->setPaintState(Component::PaintState::Normal);
        }
    }
}

void RootContainer::render() {
    for (vector<Panel*>::iterator it = container.begin(); it != container.end(); ++it) {
        (*it)->render(&graphics);
    }
}
