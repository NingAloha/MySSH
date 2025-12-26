#pragma once
#include "State/State.h"
#include <memory>

struct notcurses;

class StateMachine
{
public:
    StateMachine(std::unique_ptr<State> initialState);
    ~StateMachine();

    void changeState(std::unique_ptr<State> newState);
    void handleInput(struct notcurses *nc); 
    void render(struct notcurses *nc);

private:
    std::unique_ptr<State> currentState;
};
