#ifndef SCENARIO_H
#define SCENARIO_H

#include "raylib.h"

class Scenario
{

public:
    Texture2D texture;
    int numberFrames; // Number of frames in the texture
    Vector2 position;
    Color color;

    // Used to change frames within texture
    Rectangle frameRec;
    int currentFrame;
    int framesCounter;

    // Constructors
    Scenario(Texture2D txtr, int numFrames, Vector2 pos, Color c);

    void Render();

    Vector2 GetPosition() const;
    Rectangle GetPositionRec() const;
};

#endif