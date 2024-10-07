//
// Created by Francesco Impicciatore on 04/10/24.
//
#include "MyApp.h"
#include "BarFrame.h"

bool MyApp::OnInit() {
    BarFrame *frame = new BarFrame();
    frame->Show();
    return true;
}
wxIMPLEMENT_APP(MyApp);