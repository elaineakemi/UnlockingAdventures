#include "StatusBar.h"

void StatusBar::Render(int checkpointsRemaining)
{
    if (checkpointsRemaining > -1)
    {
        // Draw Text instruction
        DrawTextEx(customFont, "Collect the flags to open the door", (Vector2){250, 20}, 24, 2, BLACK);

        // Draw Score
        DrawTextEx(customFont, TextFormat("Score: %d", score), (Vector2){650, 20}, 24, 2, BLACK);
    }
    else
    {
        // Draw Text instruction - Boss level
        DrawTextEx(customFont, "Use bombs to kill the boss", (Vector2){250, 20}, 24, 2, BLACK);
        DrawTextEx(customFont, "Boss does not take damage directly from you", (Vector2){200, 40}, 24, 2, BLACK);
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
