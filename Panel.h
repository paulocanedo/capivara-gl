/* 
 * File:   Panel.h
 * Author: paulocanedo
 *
 * Created on 9 de Outubro de 2012, 14:39
 */

#ifndef PANEL_H
#define	PANEL_H

#include "Component.h"

class Panel : public Component {
public:
    Panel();
    Panel(const Panel& orig);
    virtual ~Panel();
    
    void add(Component* c);
    void remove(Component* c);
    
    virtual void render(Graphics* graphics);
private:
    vector<Component*> components;

};

#endif	/* PANEL_H */

