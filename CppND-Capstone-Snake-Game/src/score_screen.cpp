#include "score_screen.h"
#include "player_data.h"
#include "debug.h"

ScoreScreen::ScoreScreen(int score) : Screen(ScreenType::score), score(score)
{
    if (Debug::active)
        std::cout << "Score Screen Constructor" << std::endl;
};

ScoreScreen::~ScoreScreen()
{
    if (Debug::active)
        std::cout << "Score Screen Destructor" << std::endl;
}

void ScoreScreen::Run(Controller const &controller, Renderer &renderer, std::size_t &target_frame_duration)
{
    std::cout << "TODO: Create a Score Screen using SDL. Using terminal mode" << std::endl;
    Run();
}

void ScoreScreen::Run()
{
    if (Debug::active)
        std::cout << "Running Score Screen" << std::endl;

    PlayerData player_data;
    player_data.Update(score);
    player_data.PrintScoreBoard();
}