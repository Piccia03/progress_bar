//
// Created by Francesco Impicciatore on 04/10/24.
//
#include "MyApp.h"
#include "MyFrame.h"

bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame();
    frame->Show();
    return true;
}
wxIMPLEMENT_APP(MyApp);