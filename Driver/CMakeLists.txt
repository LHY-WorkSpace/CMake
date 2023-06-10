cmake_minimum_required(VERSION 3.21)

#此 CMakeLists 用于连接 上层CMakeLists 和 子模块中的CMakeLists
#管理此路径下的各个文件夹

add_subdirectory(BEEP)
add_subdirectory(KEY)
add_subdirectory(LED)
add_subdirectory(FastMath)

