cmake_minimum_required(VERSION 3.29)
project(progress_bar)

set(CMAKE_CXX_STANDARD 17)

# WX WIDGETS
find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

add_executable(progress_bar
        Subject.h
        Observer.h
        MyApp.h
        MyFrame.h
        MyApp.cpp
        MyFrame.cpp
        FileTransfer.h
        FileTransfer.cpp)

target_link_libraries(progress_bar ${wxWidgets_LIBRARIES})
