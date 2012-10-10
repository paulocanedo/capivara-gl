/* 
 * File:   RadioButton.h
 * Author: paulocanedo
 *
 * Created on 9 de Outubro de 2012, 11:14
 */

#ifndef RADIOBUTTON_H
#define	RADIOBUTTON_H

#include "Component.h"
#include "Label.h"

class RadioButton : public Component {
public:
    RadioButton();
    RadioButton(const RadioButton& orig);
    virtual ~RadioButton();
    
    bool isSelected();
    void setSelected(bool selected);
    void setText(string text);
    
    virtual void render(Graphics* graphics);
private:
    bool selected;
    
    Label* label;
};

#endif	/* RADIOBUTTON_H */

