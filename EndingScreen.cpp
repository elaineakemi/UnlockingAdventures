#include "EndingScreen.h"

EndingScreen::EndingScreen() {}

void EndingScreen::Init()
{
    // Background Music
    PlayMusicStream(backgroundMusic);
};

void EndingScreen::Render(Player &player)
{
    UpdateMusicStream(backgroundMusic);

    // Draw background
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(backgroundBorder, 0, 0, WHITE);

    // Draw Text
    DrawTextEx(customFont, "The End", (Vector2){300, 40}, 50, 2, DARKGRAY);
    DrawTextEx(customFont, "Thank you for playing.", (Vector2){250, 100}, 30, 2, DARKGRAY);
    DrawTextEx(customFont, "This game was developed as part of a course assignment.", (Vector2){350, 340}, 18, 2, DARKGRAY);
    DrawTextEx(customFont, "References of the material used are in the README file.", (Vector2){350, 360}, 18, 2, DARKGRAY);

    DrawTextEx(customFont, "Elaine Akemi Shinagawa", (Vector2){570, 380}, 20, 2, DARKGRAY);
    DrawTextEx(customFont, "December 2023", (Vector2){640, 400}, 20, 2, DARKGRAY);

    DrawTextEx(customFont, "Press ENTER to go back to menu", (Vector2){160, 240}, 40, 2, DARKGRAY);

    // Draw player
    player.position = {480.0f, 45.0f};
    player.SetFlipTexture(true);
    player.Render();
}
void EndingScreen::Unload()
{
    UnloadTexture(background);
    UnloadTexture(backgroundBorder);

    UnloadTexture(frogTexture);
    UnloadTexture(blueGuyTexture);
    UnloadTexture(pinkGuyTexture);

    UnloadMusicStream(backgroundMusic);

    UnloadFont(customFont);
}
