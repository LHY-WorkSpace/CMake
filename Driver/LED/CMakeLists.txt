cmake_minimum_required(VERSION 3.21)

project (LED)

aux_source_directory("./" LIST)

include_directories("./")

add_library(LED ${LIST})

