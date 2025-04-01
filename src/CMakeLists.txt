add_executable(${PROJECT_NAME})

add_subdirectory(sdl)
target_sources(${PROJECT_NAME} PRIVATE main.c player.c entity.c map.c camera.c PUBLIC player.h entity.h map.h camera.h)
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)