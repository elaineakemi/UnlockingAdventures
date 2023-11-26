#include "StatusBar.h"

StatusBar::StatusBar() {}

void StatusBar::Render(int checkpointsRemaining)
{
    // Draw Text instruction
    DrawText("Collect the flags to open the door", 300, 20, 14, BLACK);

    // Draw Score
    DrawText(TextFormat("Score: %d", score), 650, 20, 20, BLACK);

    // Render lifebar hearts
    lifeBar.Render();
    for (int i = 0; i < playerLives; i++)
    {
        lives[i]->Render();
    }

    // Render checkpoint bar flags
    checkpointBar.Render();
    for (int i = checkpointsRemaining; i < 3; i++)
    {
        checkpointsBar[i]->Render();
    }
}

void StatusBar::Unload()
{
    UnloadTexture(disappearTexture);
    UnloadTexture(lifebarTexture);
    UnloadTexture(heartTexture);
    UnloadTexture(checkpointBarTexture);
    UnloadTexture(checkpointBarCollectedTexture);
}
