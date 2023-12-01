#include "StatusBar.h"

StatusBar::StatusBar() {}

void StatusBar::Render(int checkpointsRemaining)
{
    if (checkpointsRemaining > -1)
    {
        // Draw Text instruction
        DrawText("Collect the flags to open the door", 300, 20, 14, BLACK);

        // Draw Score
        DrawText(TextFormat("Score: %d", score), 650, 20, 20, BLACK);
    }
    else
    {
        // Draw Text instruction - Boss level
        DrawText("Use bombs to kill the boss", 300, 20, 14, BLACK);
    }

    // Render lifebar hearts
    lifeBar.Render();
    for (int i = 0; i < playerLives; i++)
    {
        lives[i]->Render();
    }

    // Render checkpoint bar flags
    if (checkpointsRemaining > -1) // Boss level does not render checkpoing flags
    {
        checkpointBar.Render();
        for (int i = checkpointsRemaining; i < 3; i++)
        {
            checkpointsBar[i]->Render();
        }
    }
}

void StatusBar::Unload()
{
    /*
    UnloadTexture(disappearTexture);
    UnloadTexture(lifebarTexture);
    UnloadTexture(heartTexture);
    UnloadTexture(checkpointBarTexture);
    UnloadTexture(checkpointBarCollectedTexture);
    */
}
