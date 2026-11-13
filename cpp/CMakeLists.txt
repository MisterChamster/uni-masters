cmake_minimum_required(VERSION 3.31.0)
set(CMAKE_CXX_STANDARD 17)

project(Triangle_n
    VERSION 1.0.0
    LANGUAGES CXX
)

add_executable(Triangle_n
    src/main.cpp
    src/board.cpp
    src/board_simulations.cpp
    src/board_printers.cpp
    src/sigma_calc.cpp
    src/board_node.cpp
)

# Cpp min version
target_compile_features(Triangle_n PRIVATE cxx_std_17)

# Locate header files
target_include_directories(Triangle_n PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Exec location
set_target_properties(Triangle_n PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../build"
)
