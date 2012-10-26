/* 
 * File:   Panel.cpp
 * Author: paulocanedo
 * 
 * Created on 9 de Outubro de 2012, 14:39
 */

#include "Panel.h"
#include <iostream>
#include <typeinfo>

Panel::Panel() {
    backgroundColor = pcglCLightGray;
}

Panel::Panel(const Panel& orig) {
}

Panel::~Panel() {
}

string Panel::getComponentName() {
    return "Panel";
}

void Panel::add(Component* c) {
    components.push_back(c);
    c->setParent(this);
}

void Panel::remove(Component* c) {

}

void Panel::mouseMoved(int x, int y) {
    for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
        Panel* panel = dynamic_cast<Panel*> (*it);
        if (panel != NULL) {
            for (vector<Component*>::iterator pit = panel->components.begin(); pit != panel->components.end(); ++pit) {
                vec2 loc = panel->getLocation();

                int nx = x - loc.x;
                int ny = y - loc.y;
                if (nx >= 0 && ny >= 0) {
                    panel->mouseMoved(nx, ny);
                }
            }
        }

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

void Panel::mousePressed(int button, int x, int y) {
    for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
        Panel* panel = dynamic_cast<Panel*> (*it);
        if (panel != NULL) {
            for (vector<Component*>::iterator pit = panel->components.begin(); pit != panel->components.end(); ++pit) {
                vec2 loc = panel->getLocation();
                panel->mousePressed(button, x - loc.x, y - loc.y);
            }
        }

        if ((*it)->cover(x, y)) {
            (*it)->mousePressed(button, x, y);
        }
    }
}

void Panel::mouseReleased(int button, int x, int y) {
    for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
        Panel* panel = dynamic_cast<Panel*> (*it);
        if (panel != NULL) {
            for (vector<Component*>::iterator pit = panel->components.begin(); pit != panel->components.end(); ++pit) {
                vec2 loc = panel->getLocation();
                panel->mouseReleased(button, x - loc.x, y - loc.y);
            }
        }

        if ((*it)->cover(x, y)) {
            (*it)->mouseReleased(button, x, y);
        } else {
            (*it)->setPaintState(Component::PaintState::Normal);
        }
    }
}

ivec2 Panel::relativePos(int x, int y) {
    if (parent != NULL) {
        Panel* panel = dynamic_cast<Panel*> (parent);
        if (panel != NULL) {
            vec2 loc = panel->getLocation();
            x += loc.x;
            y += loc.y;
        }
        //        parent
    }
    vec2 loc = getLocation();
    x += loc.x;
    y += loc.y;

    return
    {
        {
            x, y
        }
    };
}

vector<Component*> Panel::getComponents() {
    return components;
}

void Panel::render(Graphics* graphics) {
    paintBackground(graphics);
    vec2 location = getLocation();
    graphics->setOffset(location.x, location.y);

    for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
        Panel* container = dynamic_cast<Panel*> (*it);
        if (container != NULL) {
            container->render(graphics);
        }

        (*it)->render(graphics);
    }

    graphics->setOffset(0, 0);
    paintBorder(graphics);
}