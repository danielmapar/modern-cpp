#ifndef SCREEN_H
#define SCREEN_H
#include "controller.h"
#include "renderer.h"

class Screen {
    public:
        Screen();
        void logic(const Controller& controller, const Renderer& renderer, const Snake& snake, bool &running);
    private:
        enum Type { setup, game, score };
        Type type;
};

#endif