# Software Enginnering - CA1

Video: https://www.youtube.com/watch?v=_BObjt11pEM

## 1. Description of the project

The project is an adventure game in 2D, which the main objective is collect flags in each level to open the door to go to the next level.

The player can select between three different characters in the beginning, but current it just changes the texture and there is no difference in the game play.

The player can collect some apples which increases the score, and kill pig enemies jumping on top of it.

For the final level there is a boss which needs to be killed using bombs. The bombs respawn in random locations on the platforms, and once the user collects it, it falls until reaches the floor and explodes. If the boss is near the explosion it inflicts damage.

The initial idea was to allow player to use the platforms and jump on top of the boss, but due the size difference int the textures I was having some issues with the collision, so I opted for chaning the game dyamics to use a bomb instead, which seems to work well.

## 2. Technologies and features implemented

The technology used was the Raylib library with C++. No additional library was needed for this assignment.

The list of features implemented can be check here: [Features](Features.md)

## 3. An advanced breakdown and explanation of the coding features

The 'official' version of the code on this repo is on the main branch.

The [video](https://www.youtube.com/watch?v=_BObjt11pEM) gives a breakdown and explanation of the coding features.

## 4. Challenges faced and how they were overcome

During the development of this assignment, the initial challenge was my lack of previous knowledge in C++ and Raylib. I overcome that checking the examples in the raylib repo, and running and debugging their code.

Another challenge I had was in relation of the template used, it gives very little flexibility in terms of file structure. I don't like the idea of having all files in the root and it makes the code looks very messy.

When I started developing this game I did not have a clear direction of what I was trying to achieve and as a result I believe I wrote much more code than necessary and ended up having to delete some of that extra code after a while. As a lesson learnt for next time, it's better to spend some time planning the game before start coding it.

Finally as mentioned in the description I had some issues with collisions between the player and the boss so I ended up changing the game to use bombs instead. I believe the collision issue was due to the difference between the textures height, and due to the fact that the Raylib `CheckCollisionRecs` are not very pixel precise.

## 5. Future scope and improvements

The future scope and improvements for this project can be checked here: [Feature Improvements](Improvements.md)
