cmake_minimum_required(VERSION 3.7)

project(SDL2Test)
set(CMAKE_MODULE_PATH /home/something/Dev/C-Playgroud/TextTest)
set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_CFLAGS} -fopenmp")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")

find_package(SDL2 REQUIRED)
find_package(SDL2TTF)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(SDL2Test /home/something/Dev/C-Playgroud/TextTest/testText.c /home/something/Dev/C-Playgroud/TextTest/Texture.c)
target_link_libraries(SDL2Test ${SDL2_LIBRARIES} ${SDL2TTF_LIBRARY} ${SDL2_IMAGE_LIBRARIES})