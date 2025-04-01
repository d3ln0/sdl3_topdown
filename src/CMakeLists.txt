add_executable(${PROJECT_NAME})

add_subdirectory(sdl)
target_sources(${PROJECT_NAME} PRIVATE main.c player.c entity.c PUBLIC player.h entity.h)
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)