cmake_minimum_required(VERSION 3.29)
project(FBlockWorld3D)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        godot-cpp/include/
        godot-cpp/gdextension/
        godot-cpp/gen/include/
)

add_library(FBlockWorld3D SHARED
        src/register_types.cpp
        src/FBlockWorld3D.cpp
        src/FBlockWorld3D.h
)
