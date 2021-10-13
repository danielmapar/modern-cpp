#include "setup_screen.h"
#include "player_data.h"
#include "debug.h"

SetupScreen::SetupScreen() : Screen(ScreenType::setup)
{
    if (Debug::active)
        std::cout << "Setup Screen Constructor" << std::endl;
};

SetupScreen::~SetupScreen()
{
    if (Debug::active)
        std::cout << "Setup Screen Destructor" << std::endl;
}

void SetupScreen::Run(Controller const &controller, Renderer &renderer, std::size_t &target_frame_duration)
{
    std::cout << "TODO: Create a Setup Screen using SDL. Using terminal mode" << std::endl;
    Run();
}

void SetupScreen::Run()
{
    if (Debug::active)
        std::cout << "Running Setup Screen" << std::endl;

    std::string user_name;

    std::cout << "Enter your name: ";
    std::cin >> user_name;

    PlayerData player_data;
    player_data.Create(user_name);
}