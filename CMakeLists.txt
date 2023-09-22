project(Snake)

cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_FLAG -Wall -Werror -Wextra)

# Subdirectories
add_subdirectory(src)
add_subdirectory(test)

# Unit tests
enable_testing()
add_test(NAME check_snake COMMAND check_snake)
