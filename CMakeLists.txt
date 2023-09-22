project(Snake)

cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_FLAG -Wall -Werror -Wextra)

# Subdirectories
add_subdirectory(src)
add_subdirectory(test)

# Unit tests
enable_testing()
add_test(NAME check_snake COMMAND check_snake)
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND}
                  DEPENDS check_snake)

