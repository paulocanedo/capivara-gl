/* 
 * File:   Button.h
 * Author: paulocanedo
 *
 * Created on 21 de Setembro de 2012, 17:43
 */

#ifndef BUTTON_H
#define	BUTTON_H

#include "Component.h"
#include "Label.h"
#include "Action.h"

class Button : public Component {
public:
    Button();
    Button(const Button& orig);
    virtual ~Button();

    void setAction(Action *action);
    void fireAction(Component *c);

    void setText(string text);
    string getText();
    void setImage(Image* image);

    virtual void render(Graphics* graphics);
    virtual void paintBackground(Graphics* graphics);
    virtual void paintBorder(Graphics* graphics);
private:
    Label* label;
    Action* action;
};

#endif	/* BUTTON_H */

