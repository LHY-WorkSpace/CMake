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



set(varrr 1;2;3;4;5;6;7)
list(LENGTH varrr len)

list(FIND varrr 8 POS)

message(${POS})

message(Length: ${len})


message(==================)
macro(Macroname indata)
    set(indata "Change")
    set(varM "Change")
    message(Macro info : ${indata})
endmacro()

set(varM "before")
message(Value 1: ${varM})
Macroname("NO change")
message(Value 2: ${varM})

message(==================)




