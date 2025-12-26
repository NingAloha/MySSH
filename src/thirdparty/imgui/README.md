# ImGui integration for MySSH

This folder contains the ImGui source code for integration.

- 官方仓库：https://github.com/ocornut/imgui
- 只需包含 imgui 源码文件，无需单独编译库。
- 推荐将 imgui 源码放入 src/thirdparty/imgui/ 目录。

集成步骤：
1. 下载 ImGui 源码（imgui.cpp, imgui_draw.cpp, imgui_tables.cpp, imgui_widgets.cpp, imgui_demo.cpp, imgui.h, imgui_internal.h, imconfig.h, imstb_*.h）。
2. 将源码放入 src/thirdparty/imgui/。
3. 在 CMakeLists.txt 添加源文件和 include 目录。
4. main.cpp 示例代码见同级文件。

如需自定义像素风皮肤，可修改 ImGui::GetStyle() 相关参数。
