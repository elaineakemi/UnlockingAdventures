#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "Player.h"

extern int currentScreen;
extern int playerSelected;

class Menu
{

private:
    Font customFont{LoadFont("resources/fonts/playpenSans.ttf")};

    Music backgroundMusic{LoadMusicStream("resources/sounds/menu.wav")};
    Sound trampolineSound{LoadSound("resources/sounds/trampoline.wav")};
    Sound confirmSound{LoadSound("resources/sounds/apple.wav")};
    Sound beepSound{LoadSound("resources/sounds/beep.wav")};
    Sound doorSound{LoadSound("resources/sounds/door_open.wav")};

    Texture2D backgroundBorder{LoadTexture("resources/textures/background/border.png")};
    Texture2D background{LoadTexture("resources/textures/background/menu.png")};

    Texture2D frogTexture{LoadTexture("resources/textures/characters/frog.png")};
    Texture2D blueGuyTexture{LoadTexture("resources/textures/characters/blue_guy.png")};
    Texture2D pinkGuyTexture{LoadTexture("resources/textures/characters/pink_guy.png")};

    bool isSelectPlayer{false};

    Player option1{frogTexture, 11, {150.0f, 240.0f}, RAYWHITE};
    Player option2{blueGuyTexture, 11, {375.0f, 230.0f}, RAYWHITE};
    Player option3{pinkGuyTexture, 11, {600.0f, 230.0f}, RAYWHITE};

public:
    Menu();
    void Init();
    void Render();
    void Update();
    void Unload();
};

#endif