cmake_minimum_required(VERSION 3.30)
project(FBlockWorld3D)

set(CMAKE_CXX_STANDARD 20)
add_compile_options("/utf-8")

add_library(
        ${PROJECT_NAME} SHARED register_types.cpp
        FBlockWorld3D/FBlockWorld3D.cpp
)

set(FSignal_ROOT "${PROJECT_SOURCE_DIR}/../tool/FSignal")
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/../tool/FSignal/cmake")
find_package(FSignal REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE FSignal::FSignal)
