
cmake_minimum_required(VERSION 3.21)

aux_source_directory("./src" LIST)
include_directories("./include")

# Éú³ÉÁ´½Ó¿â
add_library (SPI ${LIST})






