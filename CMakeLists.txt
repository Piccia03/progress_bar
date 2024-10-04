cmake_minimum_required(VERSION 3.29)
project(progress_bar)

set(CMAKE_CXX_STANDARD 17)

add_executable(progress_bar main.cpp
        Subject.h
        Observer.h)
