#ifndef ENDING_H
#define ENDING_H

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

class EndingScreen
{

private:
    // Sounds
    Music backgroundMusic{LoadMusicStream("resources/sounds/end.wav")};

public:
    EndingScreen() = default;
    void Init();
    void Render(Player &player);
    void Unload();
};

#endif