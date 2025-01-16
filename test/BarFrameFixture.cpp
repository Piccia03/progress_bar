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
        frame->Close(true);
        delete frame;
        delete fileCopy;
        delete app;
        wxEntryCleanup();
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

TEST_F(BarFrameSuite, FileCopiedMessage) {
    fileCopy->setProgress(100);
    fileCopy->notifyObservers();
    EXPECT_EQ(frame->getProgressBarValue(), 0);
    EXPECT_TRUE(frame->isSourceFileButtonEnabled());
}