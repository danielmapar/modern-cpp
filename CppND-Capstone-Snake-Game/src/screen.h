#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include "controller.h"
#include "renderer.h"

enum ScreenType
{
    setup,
    game,
    score
};

class Screen
{
public:
    Screen(ScreenType type);
    virtual ~Screen();
    virtual void Run(Controller const &controller, Renderer &renderer, std::size_t &target_frame_duration) = 0; // Run using SDL
    virtual void Run() = 0;                                                                                     // Run using terminal
    ScreenType getType();

private:
    ScreenType type;
};

#endif