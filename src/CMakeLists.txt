add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.c player.c PUBLIC player.h entity.h )
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)