#include "StateMachine.h"
#include <utility>

StateMachine::StateMachine(State *initialState)
    : currentState(initialState) {}

StateMachine::~StateMachine() = default;

void StateMachine::changeState(State *newState)
{
    currentState.reset(newState);
}

void StateMachine::handleInput(struct notcurses *nc)
{
    if (currentState)
        currentState->handleInput(*this, nc);
}

void StateMachine::render(struct notcurses *nc)
{
    if (currentState)
        currentState->render(nc);
}
