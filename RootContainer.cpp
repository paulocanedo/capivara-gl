/* 
 * File:   RootContainer.cpp
 * Author: paulocanedo
 * 
 * Created on 21 de Setembro de 2012, 09:36
 */

#include "RootContainer.h"
#include "Button.h"
#include "RadioButton.h"
#include <GL/glfw.h>

RootContainer::RootContainer() {
}

RootContainer::RootContainer(const RootContainer& orig) {
}

RootContainer::~RootContainer() {
}

void RootContainer::add(Component* c) {
    container.push_back(c);
}

void RootContainer::mousePosition(int x, int y) {
    this->mouseLocation.x = x;
    this->mouseLocation.y = y;

    for (vector<Component*>::iterator it = container.begin(); it != container.end(); ++it) {
        Component::PaintState state = (*it)->getPaintState();

        if ((*it)->cover(x, y) == true) {
            if (state == Component::PaintState::Normal)
                (*it)->setPaintState(Component::PaintState::Hover);
        } else {
            if (state == Component::PaintState::Hover)
                (*it)->setPaintState(Component::PaintState::Normal);
        }
    }
}

void RootContainer::mouseButton(int button, int state) {
    for (vector<Component*>::iterator it = container.begin(); it != container.end(); ++it) {
        Component::PaintState pstate = (*it)->getPaintState();

        if (button == 0 && state == GLFW_PRESS && pstate == Component::PaintState::Hover) {
            (*it)->setPaintState(Component::PaintState::Pressed);
        } else if (button == 0 && state == GLFW_RELEASE) {
            bool hover = (*it)->cover(this->mouseLocation.x, this->mouseLocation.y);
            if (hover) {
                Button *button = dynamic_cast<Button*> (*it);
                if (button != NULL)
                    button->fireAction(button);
                
                RadioButton *rbutton = dynamic_cast<RadioButton*> (*it);
                if (rbutton != NULL)
                    rbutton->setSelected(!rbutton->isSelected());
            }

            (*it)->setPaintState(hover ? Component::PaintState::Hover : Component::PaintState::Normal);
        }
    }
}

void RootContainer::render() {
    for (vector<Component*>::iterator it = container.begin(); it != container.end(); ++it) {
        (*it)->render(&graphics);
    }
}
