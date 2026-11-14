cmake_minimum_required(VERSION 3.31.0)
set(CMAKE_CXX_STANDARD 17)

project(Triangle_n
    VERSION 1.0.0
    LANGUAGES CXX
)

add_executable(main_testing
    src/app_testing/main_testing.cpp
    src/common/board.cpp
    src/common/board_printers.cpp
    src/common/board_construct_reset.cpp
    src/common/sigma_calc.cpp
    src/common/board_node.cpp
    src/common/simulator.cpp
)

add_executable(sigma_over_time
    src/app_sigma_over_time/sigma_over_time.cpp
    src/common/board.cpp
    # src/common/board_printers.cpp
    src/common/board_construct_reset.cpp
    src/common/sigma_calc.cpp
    src/common/board_node.cpp
    src/common/simulator.cpp
)

# DEPLOY ANOTHER ADD EXECUTABLE
# State dependencies separatly for each executable. It should repeat!

# Cpp min version
target_compile_features(main_testing PRIVATE cxx_std_17)
target_compile_features(sigma_over_time PRIVATE cxx_std_17)

# Locate header files
target_include_directories(main_testing PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(sigma_over_time PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Exec location
set_target_properties(main_testing PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../build")
set_target_properties(sigma_over_time PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/../build")
