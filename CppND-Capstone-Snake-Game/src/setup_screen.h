#ifndef SETUP_SCREEN_H
#define SETUP_SCREEN_H

#include "screen.h"

class SetupScreen : public Screen
{
public:
    ~SetupScreen();
    SetupScreen();
    void Run(Controller const &controller, Renderer &renderer, std::size_t &target_frame_duration) override; // Run using SDL
    void Run() override;                                                                                     // Run using terminal
};

#endif