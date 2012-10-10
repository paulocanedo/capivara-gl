/* 
 * File:   Action.h
 * Author: paulocanedo
 *
 * Created on 25 de Setembro de 2012, 17:24
 */

#ifndef ACTION_H
#define	ACTION_H

#include "Component.h"

class Action {
public:
    Action();
    Action(const Action& orig);
    virtual ~Action();
    
    virtual void executed(Component *src);
private:

};

#endif	/* ACTION_H */

