//
// Created by Francesco Impicciatore on 04/10/24.
//

#include "BarFrame.h"
#include "FileCopy.h"
#include <wx/wx.h>

BarFrame::BarFrame(FileCopy *fileCopy) : wxFrame(nullptr, wxID_ANY, "Progress Bar", wxDefaultPosition, wxSize(300, 100)), fileCopy(fileCopy) {

    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    wxButton *sourceFileButton = new wxButton(panel, wxID_ANY, "Select source file");
    sourceFileButton->Bind(wxEVT_BUTTON, &BarFrame::onSelectionSurceFile, this);
    vbox->Add(sourceFileButton, 0, wxEXPAND | wxALL, 5);

    progressBar = new wxGauge(panel, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
    vbox->Add(progressBar, 1, wxEXPAND | wxALL, 5);

    panel->SetSizer(vbox);
}

void BarFrame::update() {
    progressBar->SetValue(fileCopy->getProgress());
}

void BarFrame::onSelectionSurceFile(wxCommandEvent &event) {
    wxFileDialog openFileDialog(this, "Open source file", "", "", "All files (*.*)|*.*", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL) {
        return;
    }

    wxString sourceFilePath = openFileDialog.GetPath();
    wxFileDialog saveFileDialog(this, "Save destination file", "", "", "All files (*.*)|*.*", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL) {
        return;
    }

    wxString destinationFilePath = saveFileDialog.GetPath();

    fileCopy->fileCopy(sourceFilePath.ToStdString(), destinationFilePath.ToStdString());
}