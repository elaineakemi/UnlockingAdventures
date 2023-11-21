#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"

class Character
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
    int framesSpeed;

    Character(Texture2D txtr, int numFrames, Vector2 pos, Color c);

    void Render();

    void Move(Vector2 offset);

    Vector2 GetPosition() const;

    Rectangle GetPositionRec() const;
};

#endif