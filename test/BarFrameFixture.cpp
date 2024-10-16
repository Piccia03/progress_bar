//
// Created by Francesco Impicciatore on 11/10/24.
//

#include <gtest/gtest.h>
#include <wx/wx.h>
#include "../BarFrame.h"
#include "../FileCopy.h"

class BarFrameSuite : public ::testing::Test {
protected:
    wxApp* app;
    BarFrame* frame;
    FileCopy* fileCopy;

    void SetUp() override {
        int argc = 0;
        char** argv = nullptr;
        app = new wxApp();
        wxApp::SetInstance(app);
        wxEntryStart(argc, argv);
        app->OnInit();

        fileCopy = new FileCopy();
        frame = new BarFrame(fileCopy);
        frame->Show();
    }

    void TearDown() override {
        frame->Destroy();
        delete fileCopy;
        wxEntryCleanup();
        delete app;
    }
};

TEST_F(BarFrameSuite, ProgressBarUpdatesCorrectly) {
    fileCopy->setProgress(50);
    fileCopy->notifyObservers();

    EXPECT_EQ(frame->getProgressBarValue(), 50);

    fileCopy->setProgress(80);
    fileCopy->notifyObservers();
    EXPECT_EQ(frame->getProgressBarValue(), 80);
}

TEST_F(BarFrameSuite, DialogAppearsOnCompletion) {
    // Simulate file copy completion
    fileCopy->setProgress(100);
    frame->update();

    // Check if the dialog appears
    wxMessageDialog* dialog = new wxMessageDialog(frame, "File copied", "Info", wxOK | wxICON_INFORMATION);
    EXPECT_EQ(dialog->ShowModal(), wxID_OK);
    delete dialog;
}