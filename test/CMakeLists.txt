include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})

set(TEST_SOURCES
  test_queue.c
)

add_executable(check_snake ${TEST_SOURCES})
target_link_libraries(check_snake snake_lib ${CHECK_LIBRARIES})
