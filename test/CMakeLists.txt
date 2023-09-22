include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

set(TEST_SOURCES
  test_main.c
)

add_executable(check_snake ${TEST_SOURCES})
target_link_libraries(check_snake snake_lib ${CHECK_LIBRARIES})
