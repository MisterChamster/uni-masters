cmake_minimum_required(VERSION 3.31.0)
set(CMAKE_CXX_STANDARD 17)

project(Triangle_n
    VERSION 1.0.0
    LANGUAGES CXX
)

add_executable(main_testing
    # app
    src/app_testing/main_testing.cpp

    # board
    src/board/board.cpp
    src/board/board_printers.cpp
    src/board/board_construct_reset.cpp
    src/board/board_node.cpp

    # simulator
    src/simulator/simulator.cpp
    src/simulator/simulator_construct_reset.cpp
    src/simulator/simulator_simulations.cpp
    src/simulator/sigma_calc.cpp

    # common
    src/common/file_ops.cpp
    src/common/utils.cpp
)

add_executable(sigma_over_time
    # app
    src/app_sigma_over_time/sigma_over_time.cpp

    # board
    src/board/board.cpp
    # src/board/board_printers.cpp
    src/board/board_construct_reset.cpp
    src/board/board_node.cpp

    # simulator
    src/simulator/simulator.cpp
    src/simulator/simulator_construct_reset.cpp
    src/simulator/simulator_simulations.cpp
    src/simulator/sigma_calc.cpp

    # common
    src/common/file_ops.cpp
    src/common/utils.cpp
)

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
