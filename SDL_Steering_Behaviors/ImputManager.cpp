#include "ImputManager.h"

void InputManager::Listen()
{
    //1 - Update PRESSED and RELEASED keys
    for (auto i = keys.begin(); i != keys.end(); i++)
    {
        if ((i->second & PRESSED) > 0)
            i->second = HOLD;
        else if ((i->second & RELEASED) > 0)
            i->second = UP;
    }
    //2 - Listen to SDL events and process them
    SDL_Event evt;

    while (SDL_PollEvent(&evt))
    {
        switch (evt.type)
        {
        case SDL_KEYDOWN:
            if ((keys[evt.key.keysym.sym] & (PRESSED | HOLD)) == 0)
                keys[evt.key.keysym.sym] = (PRESSED | HOLD);
            break;
        case SDL_KEYUP:
            keys[evt.key.keysym.sym] = (RELEASED | UP);
            break;
        case SDL_QUIT:
            quitEvent = true;
            break;
        default:
            break;
        }
    }

    //Mouse
    SDL_GetMouseState(&mouseX, &mouseY);
}