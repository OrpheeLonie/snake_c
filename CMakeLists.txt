project(Snake)

cmake_minimum_required(VERSION 3.14)

add_compile_options(-Wall -Werror -Wextra -fsanitize=address -fPIC)
add_link_options(-fsanitize=address)

# Subdirectories
add_subdirectory(src)
add_subdirectory(test)

# Unit tests
enable_testing()
add_test(NAME check_queue COMMAND check_queue)
add_test(NAME check_snake COMMAND check_snake)

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND}
                  DEPENDS check_queue)
