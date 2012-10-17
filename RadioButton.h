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

#include <vector>

class RadioButton : public Component {
public:
    RadioButton();
    RadioButton(const RadioButton& orig);
    virtual ~RadioButton();

    string getComponentName();
    bool isSelected();
    void setSelected(bool selected);
    string getText();
    void setText(string text);
    void actionExecuted();
    vec2 getCalculatedDimension();

    inline void setGroupId(int groupId) { this->groupId = groupId; }
    inline int getGroupId() { return this->groupId; }

    RadioButton* querySelectedRadioButton();
    static RadioButton* querySelectedRadioButton(int groupId);
    void clearGroupSelection();
    static void clearGroupSelection(int groupId);

    virtual void paintButtonIcon(Graphics *graphics, bool selected, bool pressed, bool hover, int x, int cy, int radius);
    virtual void render(Graphics* graphics);
private:
    bool selected;
    Label* label;
    int groupId;

    static vector<RadioButton*> buttons;
};

#endif	/* RADIOBUTTON_H */

