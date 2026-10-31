cmake_minimum_required(VERSION 3.31.0)

project(Triangle_n
    VERSION 1.0.0
    LANGUAGES CXX
)

add_executable(Triangle_n
    cpp/src/main.cpp
    cpp/src/board.cpp
    cpp/src/board_node.cpp
)

target_compile_features(Triangle_n PRIVATE cxx_std_17)

set(CMAKE_CXX_STANDARD 17)

target_include_directories(Triangle_n PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/cpp/include
)
