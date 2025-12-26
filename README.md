# MySSH

---
## 目标
---
用C++开发一个在终端风格窗口中运行的SSH连接器，要求界面可爱、有像素风格的字符和色块动画装饰，所有交互都在自定义UI中完成。

## UI 实现方案
---
### ✅ 现行方案（推荐）

**ImGui + SDL2（跨平台像素风 UI）**

- 使用 Dear ImGui 作为 UI 框架，配合 SDL2 渲染后端。
- 支持像素风格自定义、中文字体、跨平台（Windows/Linux/Mac）。
- 代码结构清晰，易于扩展和维护。
- 依赖通过 vcpkg 管理，集成简单。

### ❌ 废案展示

**notcurses（已废弃）**

- 原方案尝试基于 notcurses 实现终端 UI，但由于其对 Windows/MSVC 支持不佳，依赖大量 Unix-only 头文件和特性，移植难度极高。
- 编译和运行在 Windows 下存在大量兼容性问题，最终放弃。

---
## 依赖与推荐库
---
- SSH功能：libssh 或 libssh2
- UI与动画：ImGui + SDL2（现行），notcurses（已废弃）
- 多线程/异步：std::thread、Boost.Asio（用于并发和网络处理）
- 日志输出：spdlog

---
## 项目任务
---
- [x]  选定并配置SSH库（libssh2） — CMakeLists.txt, deps/（libssh2）
- [x]  选定并配置UI库（ImGui+SDL2） — CMakeLists.txt, vcpkg, src/thirdparty/imgui
- [x]  搭建基础像素风UI框架（窗口、渲染循环） — main.cpp, ui.cpp, ui.h（ImGui+SDL2）
- [ ]  UI状态管理与主界面布局（进行中）— StateMachine, 各State类、主界面结构
- [ ]  动画与交互实现（未完成）— ui.cpp, ui.h, ImGui自定义控件
- [ ]  终端风格美化与主题（未完成）— ui.cpp, 主题配置
- [ ]  实现SSH连接与认证功能 — ssh_client.cpp, ssh_client.h（libssh2）
- [ ]  实现命令输入与远程输出显示 — main.cpp, ssh_client.cpp（libssh2, ImGui+SDL2）
- [ ]  支持UTF-8和多语言字符显示 — ui.cpp, utils.cpp, utils.h（ImGui+SDL2, ICU/codecvt 可选）
- [ ]  添加异常处理和错误提示 — ssh_client.cpp, ui.cpp（libssh2, ImGui+SDL2）
- [ ]  加强SSH密钥/密码的本地安全 — ssh_client.cpp, config.h（libssh2, 可选加密库如OpenSSL）
- [ ]  优化界面响应和动画流畅性 — ui.cpp, main.cpp（ImGui+SDL2, std::thread

---
## 当前已实现结构图
```
main.cpp
	└─ 初始化 SDL2/ImGui 环境
	└─ 创建 StateMachine（状态机）
			└─ StateMachine
					├─ currentState : std::unique_ptr<State>
					├─ changeState(std::unique_ptr<State>)
					├─ handleInput()/render()
					└─ 各 UI 状态类（State 及派生类）
								├─ WelcomeState
								├─ HostSelectState
								├─ ExitState
								├─ MainState
								├─ LoadingState
								├─ ErrorState
								└─ LoginState
											├─ ConfirmState
											├─ InputState
											└─ SelectState
	└─ 渲染循环
			└─ currentState->render()
			└─ currentState->handleInput()

src/
	├─ ui/
	│   ├─ StateMachine/         # 状态机与各 State 类实现
	│   └─ thirdparty/imgui/     # ImGui 源码
	└─ ...
```
> 说明：
> - 已实现状态模式驱动的 UI 逻辑骨架，支持状态切换与扩展。
> - 主循环已集成 ImGui+SDL2 渲染，后续可在各 State 内自定义界面与交互。
