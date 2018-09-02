cmake_minimum_required(VERSION 3.10)
project(project5 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32 -DFREEGLUT_STATIC -Wl,--subsystem,windows")
link_directories("D:/Program Files(x86)/MingW64/x86_64-w64-mingw32/lib32")
add_executable(project5 main.c)
target_link_libraries(project5 freeglut_static opengl32 glu32 winmm gdi32)