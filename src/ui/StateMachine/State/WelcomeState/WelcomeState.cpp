#include "WelcomeState.h"
#include "../../StateMachine.h"
#include "../HostSelectState/HostSelectState.h"
#include "../ExitState/ExitState.h"
#include <notcurses/notcurses.h>

void WelcomeState::handleInput(StateMachine &machine, struct notcurses *nc)
{
    ncinput ni;
    // 阻塞等待按键
    if (notcurses_get_blocking(nc, &ni) == 0)
    {
        // ESC 键退出
        if (ni.id == NCKEY_ESC)
        {
            machine.changeState(std::make_unique<ExitState>());
        }
        else if (ni.evtype == NCTYPE_PRESS && ni.id < 0x110000)
        { // 普通键
            machine.changeState(std::make_unique<HostSelectState>());
        }
        // 其他特殊键可根据 ni.id 过滤
    }
}

void WelcomeState::render(struct notcurses *nc)
{
    // 这里可以用 notcurses API 渲染欢迎界面
    notcurses_render(nc);
}