include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)

add_executable(check_queue test_queue.c)
target_link_libraries(check_queue snake_lib ${CHECK_LIBRARIES})

add_executable(check_snake test_snake.c)
target_link_libraries(check_snake snake_lib ${CHECK_LIBRARIES})
