cmake_minimum_required(VERSION 2.8)

project(ZeroReversible)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
add_compile_options(-Wall -Wpedantic)
endif()
add_definitions(-Wall)
aux_source_directory(. SRC_LIST)

file(GLOB SRC_HEAD
    "*.h"
    "*.cpp"
)

add_executable(${PROJECT_NAME} ${SRC_HEAD})
