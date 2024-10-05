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
    void registerObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notifyObservers() const override;

    bool transferFile(const std::string &sourceFilePath, const std::string &destinationFilePath);


private:
    std::list<Observer *> observers;
};

#endif //PROGRESS_BAR_MODEL_H
