cmake_minimum_required(VERSION 3.10)
project(spinBall)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DFREEGLUT_STATIC -Wl,--subsystem,windows")
link_directories("D:/Program Files/mingw64/x86_64-w64-mingw32/lib")

set(EXECUTABLE_OUTPUT_PATH bin/)
set(EXENAME rotate)
add_executable(${EXENAME} ${EXENAME}.cpp)
target_link_libraries(${EXENAME} freeglut_static opengl32 glu32 winmm gdi32)