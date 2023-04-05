cmake_minimum_required(VERSION 3.26.0)
project(CMAKE VERSION 1.0.3 LANGUAGES C)

# 添加源文件路径
add_subdirectory(User Driver)
# 添加头文件路径
include_directories(Driver)

# message("PROJECT_VERSION ="  ${PROJECT_VERSION_MAJOR} "-" ${PROJECT_VERSION_MINOR} - ${PROJECT_VERSION_PATCH})
# message(STATUS ${tttt})
# configure_file(config.in config.h)
#cmakedefine tttt

# 变量追加内容
list(APPEND 变量名  值)




# set(SRC_LIST main.c)
# message(STATUS "Bin File Dir " ${BIN_FIR})
# message(STATUS "Src File Dir " ${SRC_FIR})
# message(STATUS "SRC_LIST = " ${SRC_LIST})
# add_executable(main ${SRC_LIST})










