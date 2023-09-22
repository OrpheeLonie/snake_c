include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})

set(TEST_SOURCES
  test_queue.c
)

add_executable(check_queue ${TEST_SOURCES})
target_link_libraries(check_queue queue ${CHECK_LIBRARIES})
