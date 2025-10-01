cmake_minimum_required(VERSION 3.16)
project(lab-oop-2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(lab_oop_2_logic
    src/array.cpp
    src/thirteen.cpp
)

add_executable(lab_oop_2_app src/main.cpp)
target_link_libraries(lab_oop_2_app PRIVATE lab_oop_2_logic)

enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(run_tests tests/test_array.cpp tests/test_thirteen.cpp)
target_link_libraries(run_tests PRIVATE gtest_main lab_oop_2_logic)
add_test(NAME unit_tests COMMAND run_tests)