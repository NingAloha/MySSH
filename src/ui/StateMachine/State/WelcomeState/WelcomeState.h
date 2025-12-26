#pragma once
#include "State/State.h"
#include <notcurses/notcurses.h>

class StateMachine;

class WelcomeState : public State
{
public:
    void handleInput(StateMachine &machine, struct notcurses *nc) override;
    void render(struct notcurses *nc) override;
};
