/* 
 * File:   Panel.cpp
 * Author: paulocanedo
 * 
 * Created on 9 de Outubro de 2012, 14:39
 */

#include "Panel.h"

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
    c->setParent(this);
    
    ivec2 loc = nextLocation();
//    c->setLocation(loc.x, 0);
    c->setLocation(0, loc.y);
    
    components.push_back(c);
}

void Panel::remove(Component* c) {

}

ivec2 Panel::nextLocation() {
    int x = 0, y = 0;
    for (vector<Component*>::iterator it = components.begin(); it != components.end(); ++it) {
        vec2 loc = (*it)->getLocation();
        vec2 dim = (*it)->getDimension();
        
        x += dim.w + 1;
        y += dim.h + 1;
    }
    return {{x,y}};
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