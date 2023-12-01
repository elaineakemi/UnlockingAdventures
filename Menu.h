#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "Player.h"

// Global variables
extern int currentScreen;
extern int playerSelected;

class Menu
{

private:
    // Font
    Font customFont{LoadFont("resources/fonts/playpenSans.ttf")};

    // Sounds
    Music backgroundMusic{LoadMusicStream("resources/sounds/menu.wav")};
    Sound trampolineSound{LoadSound("resources/sounds/trampoline.wav")};
    Sound confirmSound{LoadSound("resources/sounds/apple.wav")};
    Sound beepSound{LoadSound("resources/sounds/beep.wav")};
    Sound doorSound{LoadSound("resources/sounds/door_open.wav")};

    // Textures
    Texture2D backgroundBorder{LoadTexture("resources/textures/background/border.png")};
    Texture2D background{LoadTexture("resources/textures/background/menu.png")};

    Texture2D frogTexture{LoadTexture("resources/textures/characters/frog.png")};
    Texture2D blueGuyTexture{LoadTexture("resources/textures/characters/blue_guy.png")};
    Texture2D pinkGuyTexture{LoadTexture("resources/textures/characters/pink_guy.png")};

    bool isSelectPlayer{false}; // To control which screen to show

    // To allow player selection
    Player option1{frogTexture, 11, {150.0f, 240.0f}};
    Player option2{blueGuyTexture, 11, {375.0f, 230.0f}};
    Player option3{pinkGuyTexture, 11, {600.0f, 230.0f}};

public:
    // Constructor
    Menu();

    void Init();
    void Render();
    void Update();
    void Unload();
};

#endif