cmake_minimum_required(VERSION 3.21)

project(BEEP)

aux_source_directory("./" LIST)

include_directories("./")

add_library(BEEP ${LIST})

target_link_libraries(BEEP IIC)
