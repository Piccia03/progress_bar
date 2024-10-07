cmake_minimum_required(VERSION 3.29)
project(progress_bar)

set(CMAKE_CXX_STANDARD 17)

# WX WIDGETS
find_package(wxWidgets REQUIRED net gl core base)
include(${wxWidgets_USE_FILE})

# UNIT TESTING
add_subdirectory(test)
set(SOURCE_FILES Subject.h
        Observer.h
        BarFrame.h
        BarFrame.cpp
        FileCopy.h
        FileCopy.cpp
)

add_executable(progress_bar MyApp.cpp MyApp.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(progress_bar ${wxWidgets_LIBRARIES} core)
