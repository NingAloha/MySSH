#pragma once
#ifdef _WIN32
// Some Windows builds use notcurses headers that expect __MINGW32__ to be defined
// even when compiling with a non-MinGW toolchain. We temporarily define __MINGW32__
// around this include to select the correct notcurses code paths, and then undo it
// to avoid leaking a fake toolchain definition into the rest of the translation unit.
#ifndef __MINGW32__
#define __MINGW32__
#define STATE_TEMP_DEFINED_MINGW32
#endif
#include <notcurses/notcurses.h>
#ifdef STATE_TEMP_DEFINED_MINGW32
#undef __MINGW32__
#undef STATE_TEMP_DEFINED_MINGW32
#endif
#endif
class StateMachine;

class State
{
public:
    virtual ~State() = default;
    virtual void handleInput(StateMachine &machine, struct notcurses *nc) {}
    virtual void render(struct notcurses *nc) {}
};
