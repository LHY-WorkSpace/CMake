# cmake_minimum_required(VERSION 3.20.0)
# project(test)
# set(PROJECT_VERSION 12)
# message(${PROJECT_SOURCE_DIR})
# message(${PROJECT_VERSION} ${PROJECT_VERSION_MAJOR})
set(SCR_LIST main.c)
set(LIST_PATH)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR},LIST_PATH)
add_executable(main ${SCR_LIST})




