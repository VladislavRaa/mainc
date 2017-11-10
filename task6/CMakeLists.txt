cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp fclass.cpp fclass.h fclass_image.cpp fclass_image.h fclass_video.cpp fclass_video.h fclass_document.cpp fclass_document.h)
add_executable(untitled ${SOURCE_FILES})