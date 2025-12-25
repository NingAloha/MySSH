cmake_minimum_required(VERSION 3.13)
project(MySSH)

set(CMAKE_CXX_STANDARD 17)

# 添加 libssh2

add_subdirectory(deps/libssh2)

# 添加 notcurses
add_subdirectory(deps/notcurses)


add_executable(MySSH src/main.cpp)

target_link_libraries(MySSH PRIVATE libssh2 notcurses)


