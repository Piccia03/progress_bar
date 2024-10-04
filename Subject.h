//
// Created by Francesco Impicciatore on 04/10/24.
//

#ifndef PROGRESS_BAR_SUBJECT_H
#define PROGRESS_BAR_SUBJECT_H

#include "Observer.h"

class Subject{
protected:
    virtual ~Subject() {};
public:
    virtual void registerObserver(Observer *o) = 0;
    virtual void removeObserver(Observer *o) = 0;
    virtual void notifyObservers() const = 0;
};
#endif //PROGRESS_BAR_SUBJECT_H
