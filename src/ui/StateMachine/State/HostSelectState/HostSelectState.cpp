#include "HostSelectState.h"
#include <notcurses/notcurses.h>

void HostSelectState::handleInput(StateMachine &machine, struct notcurses *nc)
{
    // TODO: 实现主机选择逻辑
}

void HostSelectState::render(struct notcurses *nc)
{
    // TODO: 渲染主机选择界面
    notcurses_render(nc);
}
