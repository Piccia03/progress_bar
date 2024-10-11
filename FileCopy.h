//
// Created by Francesco Impicciatore on 04/10/24.
//
#include <wx/wx.h>
#include "Subject.h"
#include <list>

#ifndef PROGRESS_BAR_MODEL_H
#define PROGRESS_BAR_MODEL_H


class FileCopy : public Subject {
public:
    void registerObserver(Observer *o) override;
    void removeObserver(Observer *o) override;
    void notifyObservers() const override;

    int getProgress() const;

    bool fileCopy(const std::string &sourceFilePath, const std::string &destinationFilePath);

    void setProgress(int value);

private:
    std::list<Observer *> observers;
    int progress = 0;
};

#endif //PROGRESS_BAR_MODEL_H
