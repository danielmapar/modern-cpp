#ifndef GAME_H
#define GAME_H

class Game
{
public:
  Game(std::size_t grid_width, std::size_t grid_height, std::size_t screen_width,
       std::size_t screen_height, std::size_t frames_per_second, std::size_t ms_per_frame);
  void Run();

private:
  std::size_t grid_width;
  std::size_t grid_height;
  std::size_t screen_width;
  std::size_t screen_height;
  std::size_t frames_per_second;
  std::size_t ms_per_frame;
};

#endif