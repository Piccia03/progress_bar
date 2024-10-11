//
// Created by Francesco Impicciatore on 04/10/24.
//

#include "BarFrame.h"
#include "FileCopy.h"
#include <wx/wx.h>

wxDEFINE_EVENT(wxEVT_UPDATE_PROGRESS, wxThreadEvent);

BarFrame::BarFrame(FileCopy *fileCopy) : wxFrame(nullptr, wxID_ANY, "Progress Bar", wxDefaultPosition, wxSize(300, 100)), fileCopy(fileCopy) {

    fileCopy->registerObserver(this);

    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

    wxButton *sourceFileButton = new wxButton(panel, wxID_ANY, "Select source file");
    sourceFileButton->Bind(wxEVT_BUTTON, &BarFrame::onSelectionSourceFile, this);
    vbox->Add(sourceFileButton, 0, wxEXPAND | wxALL, 5);

    progressBar = new wxGauge(panel, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL);
    vbox->Add(progressBar, 1, wxEXPAND | wxALL, 5);

    panel->SetSizer(vbox);

    Bind(wxEVT_UPDATE_PROGRESS, &BarFrame::onUpdateProgress, this);
}

void BarFrame::update() {
    wxThreadEvent *event = new wxThreadEvent(wxEVT_UPDATE_PROGRESS);
    event->SetInt(fileCopy->getProgress());
    wxQueueEvent(this, event);
}

void BarFrame::onUpdateProgress(wxThreadEvent &event) {
    int progress = event.GetInt();
    progressBar->SetValue(progress);
    if (progress == 100) {
        wxMessageDialog *dialog = new wxMessageDialog(this, "File copied", "Info", wxOK | wxICON_INFORMATION);
        if (dialog->ShowModal() == wxID_OK) {
            Close(true);
        }
    }
}

void BarFrame::onSelectionSourceFile(wxCommandEvent &event) {
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

    //disable the button after file selection
    wxButton* sourceFileButton = dynamic_cast<wxButton*>(event.GetEventObject());
    if (sourceFileButton) {
        sourceFileButton->Disable();
    }

    // Esegui la copia del file in un thread separato
    fileCopyThread = std::thread([this, sourceFilePath, destinationFilePath]() {
        fileCopy->fileCopy(sourceFilePath.ToStdString(), destinationFilePath.ToStdString());
        wxQueueEvent(this, new wxCommandEvent(wxEVT_COMMAND_TEXT_UPDATED));
    });

    fileCopyThread.detach();
}

BarFrame::~BarFrame() {
    fileCopy->removeObserver(this);
}