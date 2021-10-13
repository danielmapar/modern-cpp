#include "screen.h"
#include "debug.h"

Screen::Screen(ScreenType type) : type(type)
{
    if (Debug::active)
        std::cout << "Base Screen Constructor" << std::endl;
};

Screen::~Screen()
{
    if (Debug::active)
        std::cout << "Base Screen Destructor" << std::endl;
};

ScreenType Screen::getType() { return type; }