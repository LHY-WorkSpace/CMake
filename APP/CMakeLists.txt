cmake_minimum_required(VERSION 3.21)

project(main)

# target_include_directories(main )



# target_include_directories(main "../Driver/BEEP")
# target_include_directories(main "../Driver/KEY")
# target_include_directories(main "../Driver/LED")
# target_include_directories(main "../USER/SPI/include")
# target_include_directories(main "../USER/IIC/include")

add_executable(main main.c)

target_link_libraries(main BEEP)
target_link_libraries(main LED)
target_link_libraries(main KEY)
target_link_libraries(main SPI)
target_link_libraries(main IIC)
target_link_libraries(main MATH)

