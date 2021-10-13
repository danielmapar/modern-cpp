#ifndef SCORE_SCREEN_H
#define SCORE_SCREEN_H

#include "screen.h"

class ScoreScreen : public Screen
{
private:
    int score;

public:
    ~ScoreScreen();
    ScoreScreen(int score);
    void Run(Controller const &controller, Renderer &renderer, std::size_t &target_frame_duration) override; // Run using SDL
    void Run() override;                                                                                     // Run using terminal
};

#endif