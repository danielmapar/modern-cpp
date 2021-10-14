#include <thread>
#include <future>
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
    
    std::promise<bool> promise;
    std::future<bool> future = promise.get_future();

    std::thread thread([this] (std::promise<bool> && promise) {
        PlayerData player_data;
        player_data.Update(score);
        player_data.PrintScoreBoard();
        promise.set_value(true);
    }, std::move(promise));

    auto status = future.wait_for(std::chrono::milliseconds(5000));

    //  timeout has expired or function has not yet been started
    if (status == std::future_status::timeout || status == std::future_status::deferred)
    {
        std::cout << "Score failed to process!" << std::endl;
    }

    // thread barrier
    thread.join();
}