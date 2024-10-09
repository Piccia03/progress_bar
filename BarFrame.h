//
// Created by Francesco Impicciatore on 04/10/24.
//
#ifndef PROGRESS_BAR_BARFRAME_H
#define PROGRESS_BAR_BARFRAME_H
#include <wx/wx.h>
#include "Observer.h"
#include "FileCopy.h"

class BarFrame: public wxFrame, public Observer {
public:
    BarFrame(FileCopy *fileCopy);
    void update() override;
    void onSelectionSurceFile(wxCommandEvent &event);

    ~BarFrame() override;

private:
    FileCopy *fileCopy;
    wxGauge *progressBar;
};

enum {
};
#endif //PROGRESS_BAR_BARFRAME_H
