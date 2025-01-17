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

    ~BarFrame() override;

    int getProgressBarValue() const;
    bool isSourceFileButtonEnabled() const;


private:
    FileCopy *fileCopy;
    wxGauge *progressBar;
    std::thread fileCopyThread;
    wxButton *sourceFileButton;
};
#endif //PROGRESS_BAR_BARFRAME_H