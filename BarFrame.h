//
// Created by Francesco Impicciatore on 04/10/24.
//
#ifndef PROGRESS_BAR_BARFRAME_H
#define PROGRESS_BAR_BARFRAME_H
#include <wx/wx.h>
#include "Observer.h"
#include "FileCopy.h"
#include <thread>

class BarFrame: public wxFrame, public Observer {
public:
    BarFrame(FileCopy *fileCopy);
    void update() override;
    void onSelectionSourceFile(wxCommandEvent &event);
    void onUpdateProgress(wxThreadEvent &event);

    ~BarFrame() override;

    int getProgressBarValue() const;


private:
    FileCopy *fileCopy;
    wxGauge *progressBar;
    std::thread fileCopyThread;
};
#endif //PROGRESS_BAR_BARFRAME_H