#ifndef MENU_H
#define MENU_H

#include "raylib.h"
#include "Player.h"
#include "Assets.h"

// Global variables
extern int currentScreen;
extern int playerSelected;
extern bool isMute;

// Global assets
extern Font customFont;
extern BackgroundTextures backgroundTextures;
extern PlayerTextures playerTextures;
extern GameSounds gameSounds;
extern Texture2D logo;

class Menu
{

private:
    // Sounds
    Music backgroundMusic{LoadMusicStream("resources/sounds/menu.wav")};
    Sound beepSound{LoadSound("resources/sounds/beep.wav")};

    bool isSelectPlayer{false}; // To control which screen to show

    // To allow player selection
    Player option1{playerTextures.frog, {150.0f, 240.0f}};
    Player option2{playerTextures.blueGuy, {375.0f, 230.0f}};
    Player option3{playerTextures.pinkGuy, {600.0f, 230.0f}};

public:
    // Constructor
    Menu() = default;

    void Init();
    void Render();
    void Update();
    void Unload();
};

#endif