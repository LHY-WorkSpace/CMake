cmake_minimum_required(VERSION 3.21)

project(MATH)

aux_source_directory("./" LIST)

include_directories("./")

add_library(MATH ${LIST})

