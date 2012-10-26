/* 
 * File:   Panel.h
 * Author: paulocanedo
 *
 * Created on 9 de Outubro de 2012, 14:39
 */

#ifndef PANEL_H
#define	PANEL_H

#include "Component.h"
#include <vector>

class Panel : public Component {
public:
    Panel();
    Panel(const Panel& orig);
    virtual ~Panel();
    
    virtual string getComponentName();
    void add(Component* c);
    void remove(Component* c);
    vector<Component*> getComponents();
    ivec2 nextLocation();
    
    void mouseMoved(int x, int y);
    void mousePressed(int button, int x, int y);
    void mouseReleased(int button, int x, int y);
    
    virtual void render(Graphics* graphics);
private:
    vector<Component*> components;

};

#endif	/* PANEL_H */

