//
// Created by Francesco Impicciatore on 04/10/24.
//
#include "MyFrame.h"
MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "Hello World") {
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
    Bind(wxEVT_MENU, &MyFrame::onHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::onExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MyFrame::onAbout, this, wxID_ABOUT);
}

void MyFrame::onHello(wxCommandEvent &event) {
    wxLogMessage("Hello world from wxWidgets!");
}

void MyFrame::onExit(wxCommandEvent &event) {
    Close(true);
}

void MyFrame::onAbout(wxCommandEvent &event) {
    wxMessageBox("This is a wxWidgets' Hello world sample", "About Hello World", wxOK | wxICON_INFORMATION);
}