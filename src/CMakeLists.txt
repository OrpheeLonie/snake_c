set(LIB_SOURCES
  queue.c
  utils.c
  snake.c
)

set(MAIN_SOURCES
  main.c
)

set(HEADERS
  queue.h
  utils.h
  snake.h
)

add_library(snake_lib STATIC ${LIB_SOURCES} ${HEADERS})

add_executable(snake ${HEADERS} ${MAIN_SOURCES})
target_link_libraries(snake snake_lib)
