
cmake_minimum_required(VERSION 3.21)

aux_source_directory("./src" LIST)
include_directories("./include")

# �������ӿ�
add_library (SPI ${LIST})






