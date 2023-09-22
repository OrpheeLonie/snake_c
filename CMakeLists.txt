project(Snake)

cmake_minimum_required(VERSION 3.14)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAG -Wall -Werror -Wextra)

# Subdirectories
add_subdirectory(src)
add_subdirectory(test)

# Unit tests
enable_testing()
add_test(NAME test_queue COMMAND check)
