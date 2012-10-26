/* 
 * File:   CheckBoxButton.h
 * Author: paulocanedo
 *
 * Created on 17 de Outubro de 2012, 17:19
 */

#ifndef CHECKBOXBUTTON_H
#define	CHECKBOXBUTTON_H

#include "RadioButton.h"


class CheckBoxButton : public RadioButton {
public:
    CheckBoxButton();
    CheckBoxButton(const CheckBoxButton& orig);
    virtual ~CheckBoxButton();
    
    virtual string getComponentName();
    
    virtual void paintButtonIcon(Graphics *graphics, bool selected, bool pressed, bool hover, int x, int cy, int radius);
//    virtual void render(Graphics* graphics);
private:

};

#endif	/* CHECKBOXBUTTON_H */

