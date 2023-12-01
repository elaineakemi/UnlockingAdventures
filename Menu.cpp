#include "Menu.h"

void Menu::Init()
{
    // Background Music
    PlayMusicStream(backgroundMusic);
    isSelectPlayer = false;
}

void Menu::Render()
{
    DrawTexture(backgroundTextures.menu, 0, 0, WHITE);
    DrawTexture(backgroundTextures.border, 0, 0, WHITE);

    // First screen
    if (!isSelectPlayer)
    {
        // Draw Text
        DrawTextEx(customFont, "Game name here", (Vector2){200, 40}, 50, 2, DARKGRAY);
        DrawTextEx(customFont, "Controls", (Vector2){200, 180}, 24, 2, DARKGRAY);
        DrawTextEx(customFont, "Use left/right or A/D to move", (Vector2){200, 200}, 20, 2, DARKGRAY);
        DrawTextEx(customFont, "Use up or W or space to jump", (Vector2){200, 220}, 20, 2, DARKGRAY);
        DrawTextEx(customFont, "Press ENTER to start", (Vector2){250, 350}, 40, 2, DARKGRAY);
    }
    // Second screen
    else
    {
        DrawTextEx(customFont, "Game name here", (Vector2){200, 40}, 50, 2, DARKGRAY);
        DrawTextEx(customFont, "Select your hero", (Vector2){200, 150}, 30, 2, DARKGRAY);

        // Render players textures
        option1.Render();
        option2.Render();
        option3.Render();
        DrawTextEx(customFont, "Ninja Frog", (Vector2){130, 280}, 18, 2, BLACK);
        DrawTextEx(customFont, "Blue Guy", (Vector2){355, 280}, 18, 2, BLACK);
        DrawTextEx(customFont, "Pink Guy", (Vector2){580, 280}, 18, 2, BLACK);

        // Draw circle to show selection
        switch (playerSelected)
        {
        case 1:
            DrawCircleLines(170, 270, 60, DARKBLUE);
            break;
        case 2:
            DrawCircleLines(390, 270, 60, DARKBLUE);
            break;
        case 3:
            DrawCircleLines(615, 270, 60, DARKBLUE);
            break;
        default:
            break;
        }

        DrawTextEx(customFont, "Press ENTER to confirm", (Vector2){250, 350}, 40, 2, DARKGRAY);
    }
}

void Menu::Update()
{
    UpdateMusicStream(backgroundMusic);
    // First screen
    if (!isSelectPlayer)
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            PlaySound(gameSounds.apple);
            isSelectPlayer = true;
            playerSelected = 1;
        }
    }
    // Screen to select player
    else
    {
        // Check keys to select player
        if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A))
        {
            if (playerSelected > 1)
            {
                PlaySound(beepSound);
                playerSelected--;
            }
        }
        if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D))
        {
            if (playerSelected < 3)
            {
                PlaySound(beepSound);
                playerSelected++;
            }
        }
        if (IsKeyPressed(KEY_ENTER))
        {
            currentScreen = 1;
        }
    }
}

void Menu::Unload()
{
    UnloadMusicStream(backgroundMusic);
    UnloadSound(beepSound);
}
