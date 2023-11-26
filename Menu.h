#ifndef MENU_H
#define MENU_H

#include "raylib.h"

extern int currentScreen;

class Menu
{

private:
    Font customFont{LoadFont("resources/fonts/playpenSans.ttf")};

    Music backgroundMusic{LoadMusicStream("resources/sounds/menu.wav")};
    Sound trampolineSound{LoadSound("resources/sounds/trampoline.wav")};
    Sound appleSound{LoadSound("resources/sounds/apple.wav")};
    Sound checkpointSound{LoadSound("resources/sounds/checkpoint.wav")};
    Sound doorSound{LoadSound("resources/sounds/door_open.wav")};

    Texture2D backgroundBorder{LoadTexture("resources/textures/background/border.png")};
    Texture2D background{LoadTexture("resources/textures/background/menu.png")};

public:
    Menu();
    void Init();
    void Render();
    void Update();
    void Unload();
};

#endif