cmake_minimum_required(VERSION 3.14)
project(shapedrawer)

set(CMAKE_CXX_STANDARD 14)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)

enable_testing()

add_executable(
  shapedrawer
  main.cc
  command.cc
  shapes.cc
)

add_executable(
    examples
    examples.cc
    test.cc
    shapes.cc
)

target_include_directories(
    shapedrawer
    PUBLIC
)

target_include_directories(
    examples
    PUBLIC
)

add_executable(
    unittest
    shapes.cc
    command.cc
    ut/unittest.cc
)
target_include_directories(
    unittest
    PUBLIC
    .
)
target_link_libraries(
    unittest PRIVATE Catch2::Catch2WithMain
)

catch_discover_tests(unittest)