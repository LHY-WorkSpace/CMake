cmake_minimum_required(VERSION 3.20.0)

project(CMAKE VERSION 1.0.3 LANGUAGES C)


# 添加头文件路径,具体到.h
include_directories("./APP")
include_directories("./Driver/BEEP")
include_directories("./Driver/KEY")
include_directories("./Driver/LED")
include_directories("./USER/SPI/include")
include_directories("./USER/IIC/include")

# add_subdirectory必须在include_directories之后！！！！！！
# 添加子模块的 CMakeLists.txt 路径
add_subdirectory("./APP")
add_subdirectory("./Driver")
add_subdirectory("./USER")











