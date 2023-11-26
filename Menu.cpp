#include "Menu.h"

Menu::Menu() {}

void Menu::Init()
{
    PlayMusicStream(backgroundMusic);
}

void Menu::Render()
{
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(backgroundBorder, 0, 0, WHITE);

    // Draw Text
    DrawTextEx(customFont, "Game name here", (Vector2){200, 40}, 50, 2, DARKGRAY);
    DrawTextEx(customFont, "Controls", (Vector2){200, 180}, 24, 2, DARKGRAY);
    DrawTextEx(customFont, "Use left/right or A/D to move", (Vector2){200, 200}, 20, 2, DARKGRAY);
    DrawTextEx(customFont, "Use up or W or space to jump", (Vector2){200, 220}, 20, 2, DARKGRAY);
    DrawTextEx(customFont, "Press ENTER to start", (Vector2){250, 350}, 40, 2, DARKGRAY);
}

void Menu::Update()
{
    if (IsKeyDown(KEY_ENTER))
    {
        PlaySound(appleSound);

        currentScreen = 1;
        DrawTextEx(customFont, "asdfsadf", (Vector2){250, 350}, 40, 2, DARKGRAY);
    }
}

void Menu::Unload()
{
    UnloadTexture(background);
    UnloadTexture(backgroundBorder);

    UnloadMusicStream(backgroundMusic);
    UnloadSound(trampolineSound);
    UnloadSound(appleSound);
    UnloadSound(checkpointSound);
    UnloadSound(doorSound);

    UnloadFont(customFont);
}
