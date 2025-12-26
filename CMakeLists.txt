
# 让 CMake 能找到 vcpkg 的 SDL2Config.cmake
set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows" ${CMAKE_PREFIX_PATH})

cmake_minimum_required(VERSION 3.13)
project(MySSH)

set(CMAKE_CXX_STANDARD 17)

# ImGui 源码集成
file(GLOB IMGUI_SRC
	src/thirdparty/imgui/imgui.cpp
	src/thirdparty/imgui/imgui_draw.cpp
	src/thirdparty/imgui/imgui_tables.cpp
	src/thirdparty/imgui/imgui_widgets.cpp
	src/thirdparty/imgui/imgui_demo.cpp
	src/thirdparty/imgui/imgui_impl_sdl2.cpp
	src/thirdparty/imgui/imgui_impl_sdlrenderer2.cpp
)

add_executable(MySSH
	src/main.cpp
	src/ui/ui.cpp
	${IMGUI_SRC}
)

# SDL2 极简配置
find_package(SDL2 CONFIG REQUIRED)
target_include_directories(MySSH PRIVATE "${CMAKE_SOURCE_DIR}/vcpkg/installed/x64-windows/include/SDL2")
target_link_libraries(MySSH PRIVATE SDL2::SDL2 SDL2::SDL2main)

# ImGui 头文件
target_include_directories(MySSH PRIVATE src/thirdparty/imgui)



