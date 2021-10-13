#include <iostream>
#include <memory>
#include "game.h"
#include "renderer.h"
#include "controller.h"
#include "screen.h"
#include "setup_screen.h"
#include "game_screen.h"
#include "score_screen.h"

Game::Game(std::size_t grid_width, std::size_t grid_height, std::size_t screen_width,
           std::size_t screen_height, std::size_t frames_per_second, std::size_t ms_per_frame) : grid_width(grid_width),
                                                                                                 grid_height(grid_height),
                                                                                                 screen_width(screen_width),
                                                                                                 screen_height(screen_height),
                                                                                                 frames_per_second(frames_per_second),
                                                                                                 ms_per_frame(ms_per_frame)
{
}

void Game::Run()
{
  // Load Setup Screen
  std::unique_ptr<Screen> screen = std::make_unique<SetupScreen>();
  screen->Run();

  // Load Game Screen
  Renderer renderer(screen_width, screen_height, grid_width, grid_height);
  Controller controller;

  screen = std::make_unique<GameScreen>(grid_width, grid_height);
  screen->Run(controller, renderer, ms_per_frame);

  GameScreen *game_screen = static_cast<GameScreen *>(screen.get());
  int score = game_screen->GetScore();

  // Load Score Screen
  screen = std::make_unique<ScoreScreen>(score);
  screen->Run();
}