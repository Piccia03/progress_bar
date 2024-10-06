//
// Created by Francesco Impicciatore on 06/10/24.
//

#include "gtest/gtest.h"
#include "../FileCopy.h"
#include <fstream>
#include <filesystem>



class FileCopySuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        std::ofstream testFile("testFileSource.txt");
        testFile << "this is a test file" << std::endl;
        testFile.close();
    }

    virtual void TearDown() {
        remove("testFileSource.txt");
        remove("testFileDestination.txt");
    }

    
};

TEST_F(FileCopySuite, FileCopyOK) {
    FileCopy copy;
    copy.fileCopy("testFileSource.txt", "testFileDestination.txt");

    std::ifstream sourceFile("testFileSource.txt", std::ios::binary);
    std::ifstream destinationFile("testFileDestination.txt", std::ios::binary);

    ASSERT_TRUE(sourceFile.is_open());
    ASSERT_TRUE(destinationFile.is_open());

    std::string sourceContent((std::istreambuf_iterator<char>(sourceFile)), std::istreambuf_iterator<char>());
    std::string destinationContent((std::istreambuf_iterator<char>(destinationFile)), std::istreambuf_iterator<char>());

    ASSERT_EQ(sourceContent, destinationContent);

    sourceFile.close();
    destinationFile.close();
}
