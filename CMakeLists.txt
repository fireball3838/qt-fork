cmake_minimum_required(VERSION 3.5)

project(fork LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Core)

include_directories(class_first class_second class_third)

add_executable(fork main.cpp
    settings.ini
    SettingsLoader.h
    SettingsLoader.cpp
    class_first/ClassFirst.cpp
    class_first/ClassFirst.h
    class_second/ClassSecond.cpp
    class_second/ClassSecond.h
    class_third/ClassThird.cpp
    class_third/ClassThird.h
    )


target_link_libraries(fork Qt5::Core)
