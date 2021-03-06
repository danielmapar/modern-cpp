#include <random>
#include <ctime>
#include <future>
#include <thread>
#include "SDL.h"
#include "game_screen.h"
#include "debug.h"

GameScreen::GameScreen(std::size_t grid_width, std::size_t grid_height) : Screen(ScreenType::game),
                                                                          snake(grid_width, grid_height),
                                                                          engine(dev()),
                                                                          random_w(0, static_cast<int>(grid_width - 1)),
                                                                          random_h(0, static_cast<int>(grid_height - 1))
{
    if (Debug::active)
        std::cout << "Game Screen Constructor" << std::endl;
    PlaceFood();
};

GameScreen::~GameScreen()
{
    if (Debug::active)
        std::cout << "Game Screen Destructor" << std::endl;
}

void GameScreen::Run()
{
    std::cout << "TODO: Create a Game Screen using the console." << std::endl;
}

void GameScreen::Run(Controller const &controller, Renderer &renderer, std::size_t &target_frame_duration)
{
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;
    bool running = true;

    std::time_t thread_start_time = std::time(nullptr);
    std::time_t thread_end_time = std::time(nullptr);

    while (running)
    {
        frame_start = SDL_GetTicks();

        // Input, Update, Render - the main game loop.
        controller.HandleInput(running, snake);

        if (!snake.alive)
            return;

        snake.Update();

        thread_end_time = std::time(nullptr);

        // Move food every 10 seconds
        const int timeout_move_food = 10;
        if ((thread_end_time - thread_start_time) > timeout_move_food) {
            thread_start_time = std::time(nullptr);

            std::future<void> future_moving = std::async(std::launch::async, [this] () {
                if (Debug::active)
                    std::cout << "Moving food!" << std::endl;
                PlaceFood();
                condition_variable.notify_one();
            });

            std::future<void> future_score = std::async(std::launch::async, [this] () {
                std::unique_lock<std::mutex> uLock(mutex);
                condition_variable.wait(uLock, [] () { 
                    return true;
                });
                std::cout << "Food changed position!" << std::endl << "Your score is: " << score << std::endl; 
            });
        }


        int new_x = static_cast<int>(snake.head_x);
        int new_y = static_cast<int>(snake.head_y);

        // Check if there's food over here
        if (food.x == new_x && food.y == new_y)
        {
            score++;
            PlaceFood();
            // Grow snake and increase speed.
            snake.GrowBody();
            snake.speed += 0.02;
        }
        renderer.RenderSnake(snake, food);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render cycle
        // takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000)
        {

            renderer.UpdateWindowTitle(GetScore(), frame_count);
            frame_count = 0;
            title_timestamp = frame_end;
        }

        // If the time for this frame is too small (i.e. frame_duration is
        // smaller than the target ms_per_frame), delay the loop to
        // achieve the correct frame rate.
        if (frame_duration < target_frame_duration)
        {
            SDL_Delay(target_frame_duration - frame_duration);
        }
    }
}

void GameScreen::PlaceFood()
{

    std::lock_guard<std::mutex> lck(mutex);
    int x, y;
    while (true)
    {
        x = random_w(engine);
        y = random_h(engine);
        // Check that the location is not occupied by a snake item before placing
        // food.
        if (!snake.SnakeCell(x, y))
        {
            food.x = x;
            food.y = y;
            return;
        }
    }
}

int GameScreen::GetScore() const { return score; }
int GameScreen::GetSize() const { return snake.size; }