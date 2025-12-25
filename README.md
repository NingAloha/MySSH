# MySSH
___
## 目标
___
用C++开发一个在终端界面运行的SSH连接器，要求界面可爱、有字符和色块组成的动画装饰，并且所有交互都在类似于Terminal的UI中完成。
## 可能需要用到的库
___
- SSH功能：libssh 或 libssh2
- 终端UI与动画：ncurses、notcurses、termbox、pdcurses（Windows）
- 多线程/异步：std::thread、Boost.Asio（用于并发和网络处理）
- 颜色和字符渲染：notcurses（支持丰富色彩和动画）、ncurses（基础色彩和字符）
- 可选UI增强：imgui-sfml（如需图形界面）、spdlog（日志输出）
- 核心组合推荐（Provided by gpt-4.1）：libssh2 + notcurses。
## 项目任务
___
- [x]  选定并配置SSH库（libssh2） — CMakeLists.txt, deps/（libssh2）
- [x]  选定并配置终端UI库（notcurses） — CMakeLists.txt, deps/（notcurses）
- [ ]  搭建基础终端UI框架 — main.cpp, ui.cpp, ui.h（notcurses/ncurses）
- [ ]  实现SSH连接与认证功能 — ssh_client.cpp, ssh_client.h（libssh2）
- [ ]  实现命令输入与远程输出显示 — main.cpp, ssh_client.cpp（libssh2, notcurses/ncurses）
- [ ]  设计并实现动画装饰（字符/色块） — ui.cpp, ui.h（notcurses/ncurses）
- [ ]  支持UTF-8和多语言字符显示 — ui.cpp, utils.cpp, utils.h（notcurses/ncurses, ICU/codecvt 可选）
- [ ]  添加异常处理和错误提示 — ssh_client.cpp, ui.cpp（libssh2, notcurses/ncurses）
- [ ]  加强SSH密钥/密码的本地安全 — ssh_client.cpp, config.h（libssh2, 可选加密库如OpenSSL）
- [ ]  优化界面响应和动画流畅性 — ui.cpp, main.cpp（notcurses/ncurses, std::thread）