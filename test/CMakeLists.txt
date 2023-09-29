include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

set(TEST_SOURCES
  test_queue.c
)

add_executable(check_queue ${TEST_SOURCES})
target_link_libraries(check_queue snake_lib ${CHECK_LIBRARIES})
