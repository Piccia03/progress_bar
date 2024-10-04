//
// Created by Francesco Impicciatore on 04/10/24.
//
#ifndef PROGRESS_BAR_MYFRAME_H
#define PROGRESS_BAR_MYFRAME_H
#include <wx/wx.h>

class MyFrame: public wxFrame {
public:
    MyFrame();

private:
    void onHello(wxCommandEvent& event);
    void onExit(wxCommandEvent& event);
    void onAbout(wxCommandEvent& event);
};

enum {
    ID_Hello = 1
};
#endif //PROGRESS_BAR_MYFRAME_H
