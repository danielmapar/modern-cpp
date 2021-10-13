#include <iostream>
#include "game.h"
#include "debug.h"

int main(int argc, char **argv)
{

  if (argc > 1 && argv[1] == std::string("-d"))
  {
    Debug::active = true;
  }

  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Game game(kGridWidth, kGridHeight, kScreenWidth, kScreenHeight, kFramesPerSecond, kMsPerFrame);
  game.Run();
  std::cout << "Game has terminated successfully!\n";
  return 0;
}