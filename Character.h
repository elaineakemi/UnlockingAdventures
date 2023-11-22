#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"

class Character
{
private:
    bool isAlive = true;
    int renderDied = 5; // To render the disappearing texture

public:
    Texture2D texture;
    int numberFrames; // Number of frames in the texture
    Vector2 position;
    Color color;

    // Used to change frames within texture
    Rectangle frameRec;
    int currentFrame;
    int framesCounter;

    Texture2D disappearTexture;

    Character(Texture2D txtr, int numFrames, Vector2 pos, Color c, Texture2D disappearChar);

    bool GetIsAlive() { return isAlive; }
    void SetIsAlive(bool isCharAlive) { isAlive = isCharAlive; }

    void Render();

    void Move(Vector2 offset);

    Rectangle GetPositionRec() const;
};

#endif