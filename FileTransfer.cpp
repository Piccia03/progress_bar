//
// Created by Francesco Impicciatore on 04/10/24.
//
#include "FileTransfer.h"
#include "Observer.h"

void FileTransfer::registerObserver(Observer *o) {
    observers.push_back(o);
}

void FileTransfer::removeObserver(Observer *o) {
    observers.remove(o);
}

void FileTransfer::notifyObservers() const {
    for (auto &observer : observers) {
        observer->update(data);
    }
}