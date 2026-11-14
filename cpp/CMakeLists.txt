cmake_minimum_required(VERSION 3.31.0)
set(CMAKE_CXX_STANDARD 17)

project(Triangle_n
    VERSION 1.0.0
    LANGUAGES CXX
)

add_executable(Triangle_n
    src/app_testing/main_testing.cpp
    src/common/board.cpp
    src/common/board_printers.cpp
    src/common/sigma_calc.cpp
    src/common/board_node.cpp
    src/common/simulator.cpp
)

# DEPLOY ANOTHER ADD EXECUTABLE
# State dependencies separatly for each executable. It should repeat!

# Cpp min version
target_compile_features(Triangle_n PRIVATE cxx_std_17)

# Locate header files
target_include_directories(Triangle_n PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Exec location
set_target_properties(Triangle_n PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../build/executables"
)
