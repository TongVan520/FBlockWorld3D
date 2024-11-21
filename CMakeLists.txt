cmake_minimum_required(VERSION 3.29)
project(FBlockWorld3D)

set(CMAKE_CXX_STANDARD 17)

include_directories(
        godot-cpp/include/
        godot-cpp/gdextension/
        godot-cpp/gen/include/
)

add_library(FBlockWorld3D SHARED
        src/register_types.cpp
        src/FBlockWorld3D.cpp
        src/FBlockWorld3D.h
        src/GodotHelper/GodotHelper.h
        src/ChunkManager.cpp
        src/ChunkManager.h
        src/FSignal/FSignal.cpp
        src/FSignal/FSignal.h
)
