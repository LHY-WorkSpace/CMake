cmake_minimum_required(VERSION 3.20.0)

project(CMAKE VERSION 1.0.3 LANGUAGES C)


# 添加头文件路径,具体到.h
include_directories("./APP")
include_directories("./Driver/BEEP")
include_directories("./Driver/KEY")
include_directories("./Driver/LED")
include_directories("./Driver/FastMath")
include_directories("./User/SPI/include")
include_directories("./User/IIC/include")


# add_subdirectory必须在include_directories之后！！！！！！
# 添加子模块的 CMakeLists.txt 路径
add_subdirectory("./APP")
add_subdirectory("./Driver")
add_subdirectory("./User")



# set(varrr 1;2;3;4;5;6;7)
# list(LENGTH varrr len)

# list(FIND varrr 8 POS)

# message(${POS})

# message(Length: ${len})







# message(==================)
# function(Macroname indata)
#     set(indata "Change")
#     # set(varM "Change")
#     message(Macro info : ${indata})
# endfunction()

# set(varM "before")
# message(Value 1: ${varM})
# Macroname("NO change")
# message(Value 2: ${varM})

# message(==================)

# if(varM)
#     message("YES")
# else()
#     message("NO")
# endif()


set(num 0 1 2 3)
set(char A B C D)

foreach(Var IN ZIP_LISTS num char)
    message(num "${Var_0}")
    message(cahr "${Var_1}")
endforeach()




