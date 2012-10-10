/* 
 * File:   GroupButtonControl.h
 * Author: paulocanedo
 *
 * Created on 9 de Outubro de 2012, 16:16
 */

#ifndef GROUPBUTTONCONTROL_H
#define	GROUPBUTTONCONTROL_H

#include "RadioButton.h"
#include <vector>

class GroupButtonControl {
public:
    GroupButtonControl();
    GroupButtonControl(const GroupButtonControl& orig);
    virtual ~GroupButtonControl();
    
    void add(RadioButton* rbutton);
    void remove(RadioButton* rbutton);
private:
    RadioButton* currentButton;
    vector<RadioButton*> buttons;

};

#endif	/* GROUPBUTTONCONTROL_H */

