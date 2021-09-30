/**
 * @file    main.cpp
 * @author  Martin Cagas
 * @date    2021-09-29
 *
 * @brief   Physics-based particle game.
 *
 * @section DESCRIPTION
 *
 * A particle simulation game built using C++ and a low-level game creation library.
 */

#include "main.hpp"

int main()
{
    InitWindow(800, 450, "Particle Game v0.1");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("It's something!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
