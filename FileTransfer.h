//
// Created by Francesco Impicciatore on 04/10/24.
//
#include <wx/wx.h>
#include "Subject.h"
#include <list>

#ifndef PROGRESS_BAR_MODEL_H
#define PROGRESS_BAR_MODEL_H


class FileTransfer : public Subject {
public:
    virtual void registerObserver(Observer *o) override;
    virtual void removeObserver(Observer *o) override;
    virtual void notifyObservers() const override;

private:
    std::list<Observer *> observers;
    int data = 0;
};

#endif //PROGRESS_BAR_MODEL_H
