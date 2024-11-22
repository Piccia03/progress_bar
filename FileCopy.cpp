//
// Created by Francesco Impicciatore on 04/10/24.
//
#include <fstream>
#include "FileCopy.h"


void FileCopy::registerObserver(Observer *o) {
    observers.push_back(o);
}

void FileCopy::removeObserver(Observer *o) {
    observers.remove(o);
}

void FileCopy::notifyObservers() const {
    for (auto &observer : observers) {
        observer->update();
        wxYield();
    }
}

bool FileCopy::fileCopy(const std::string &sourceFilePath, const std::string &destinationFilePath) {
    std::ifstream sourceFile(sourceFilePath, std::ios::binary);
    if(!sourceFile.is_open()) {
        wxLogError("Cannot open source file");
        return false;
    }

    std::ofstream destinationFile(destinationFilePath, std::ios::binary);
    if(!destinationFile.is_open()) {
        wxLogError("Cannot open destination file");
        return false;
    }

    // get length of file:
    sourceFile.seekg(0, std::ifstream::end);
    std::streamsize size = sourceFile.tellg();
    sourceFile.seekg(0, std::ifstream::beg);

    const std::streamsize bufferSize = 1024;
    char buffer[bufferSize];
    std::streamsize bytesRead = 0;

    while (sourceFile.read(buffer, bufferSize)) {
        bytesRead += sourceFile.gcount();
        destinationFile.write(buffer, sourceFile.gcount());
        progress = (int) (bytesRead * 100 / size);
        notifyObservers();

        //simulate slow copy
        wxMilliSleep(100);
    }

    // read remaining bytes
    if (sourceFile.gcount() > 0) {
        bytesRead += sourceFile.gcount();
        destinationFile.write(buffer, sourceFile.gcount());
        progress = (int) (bytesRead * 100 / size);
        notifyObservers();
    }

    sourceFile.close();
    destinationFile.close();
    return true;
}

int FileCopy::getProgress() const {
    return progress;
}

void FileCopy::setProgress(int value) {
    FileCopy::progress = value;
}

FileCopy::~FileCopy() {
    observers.clear();
}
