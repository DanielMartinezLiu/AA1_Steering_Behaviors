#pragma once
#include <SDL.h>
#include <unordered_map>

#define IM InputManager::Instance()

enum KeyState
{
    EMPTY = 0,
    PRESSED = 1,
    HOLD = 2,
    RELEASED = 4,
    UP = 8
};

class InputManager
{
private:
    std::unordered_map<Sint32, int> keys;

    bool quitEvent;
    int mouseX;
    int mouseY;

    InputManager()
        : quitEvent(0), mouseX(0), mouseY(0) {}
    InputManager(const InputManager&) = delete;
    InputManager& operator =(const InputManager&) = delete;

public:
    inline static InputManager& Instance()
    {
        static InputManager manager;
        return manager;
    }

    void Listen();

    inline bool CheckKeyState(Sint32 key, KeyState state) { return (keys[key] & state) > 0; }
    inline bool GetQuitEvent() { return quitEvent; }
    inline int GetMouseX() { return mouseX; }
    inline int GetMouseY() { return mouseY; }

};