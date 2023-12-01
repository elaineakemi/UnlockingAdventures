#ifndef SCENARIO_H
#define SCENARIO_H

#include "raylib.h"
#include "Consts.h"

class Scenario
{

public:
    Texture2D texture;
    int numberFrames; // Number of frames in the texture
    Vector2 position;

    // Used to change frames within texture
    Rectangle frameRec;
    int currentFrame;
    int framesCounter;

    // Constructors
    Scenario(Texture2D txtr, int numFrames, Vector2 pos);

    void Render();

    Vector2 GetPosition() const;
    Rectangle GetPositionRec() const;
};

#endif