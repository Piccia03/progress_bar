//
// Created by Francesco Impicciatore on 04/10/24.
//
#include "MyApp.h"
#include "BarFrame.h"

bool MyApp::OnInit() {
    auto *fileCopy = new FileCopy();
    auto *barFrame = new BarFrame(fileCopy);
    barFrame->Show(true);
    return true;
}
wxIMPLEMENT_APP(MyApp);