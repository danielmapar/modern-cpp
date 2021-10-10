#include "screen.h"

Screen::Screen() {
    type = setup;
}

void Screen::logic(const Controller &controller, const Renderer &renderer, const Snake &snake, bool &running) {
    if (type == setup) {
        // Input, Update, Render - the main game loop.
        controller.HandleInput(running, snake);
        if (!snake.alive) return;

        snake.Update();

        int new_x = static_cast<int>(snake.head_x);
        int new_y = static_cast<int>(snake.head_y);

        // Check if there's food over here
        if (food.x == new_x && food.y == new_y) {
            score++;
            PlaceFood();
            // Grow snake and increase speed.
            snake.GrowBody();
            snake.speed += 0.02;
        }
        renderer.Render(snake, food);
    }
}