#pragma once
#include "../State.h"

class HostSelectState : public State
{
public:
    void handleInput(StateMachine &machine, struct notcurses *nc) override;
    void render(struct notcurses *nc) override;
};
