//
// Created by Francesco Impicciatore on 04/10/24.
//
#include <fstream>
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
        observer->update();
    }
}

bool FileTransfer::transferFile(const std::string &sourceFilePath, const std::string &destinationFilePath) {
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

    const std::streamsize bufferSize = 1024; // 1KB
    char buffer[bufferSize];
    std::streamsize bytesRead = 0;

    while (sourceFile.read(buffer, bufferSize)) {
        bytesRead += sourceFile.gcount();
        destinationFile.write(buffer, sourceFile.gcount());
        notifyObservers(); //todo: implement update method

        //simulate slow transfer
        wxMilliSleep(100);
    }

    // read remaining bytes
    if (sourceFile.gcount() > 0) {
        bytesRead += sourceFile.gcount();
        destinationFile.write(buffer, sourceFile.gcount());
        notifyObservers(); //todo: implement update method
    }

    sourceFile.close();
    destinationFile.close();
    return true;
}