#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include <random>
#include "screen.h"
#include "snake.h"
#include "SDL.h"

class GameScreen : public Screen
{
public:
    GameScreen(std::size_t grid_width, std::size_t grid_height);
    ~GameScreen();
    void Run(Controller const &controller, Renderer &renderer, std::size_t &target_frame_duration) override; // Run using SDL
    void Run() override;                                                                                     // Run using terminal
    int GetScore() const;
    int GetSize() const;

private:
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;
    std::random_device dev;
    std::mt19937 engine;
    SDL_Point food;
    Snake snake;
    int score{0};
    void PlaceFood();
};

#endif