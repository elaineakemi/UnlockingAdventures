#include "Level1.h"

Level1::Level1() {}

void Level1::Init()
{
}

void Level1::RenderBackground()
{
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(backgroundBorder, 0, 0, WHITE);
}

void Level1::RenderItems()
{
    for (auto apple : apples)
    {
        apple->Render();
    }

    for (auto checkpoint : checkpoints)
    {
        checkpoint->Render();
    }
}

void Level1::Update(Rectangle playerRect)
{
    for (auto checkpoint : checkpoints)
    {
        if (CheckCollisionRecs(playerRect, checkpoint->GetPositionRec()))
        {
            checkpoint->SetIsAlive(false);
            checkpoint->SetIsDisappearAfterCollect(false);
        }
    }

    for (auto apple : apples)
    {
        if (CheckCollisionRecs(playerRect, apple->GetPositionRec()))
        {
            apple->SetIsAlive(false);
        }
    }
}

void Level1::Unload()
{
    UnloadTexture(background);
    UnloadTexture(backgroundBorder);
    UnloadTexture(disappearTexture);
    UnloadTexture(appleTexture);
    UnloadTexture(checkpointTexture);
}