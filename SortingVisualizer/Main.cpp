#include <chrono>
#include <iostream>
#include <thread>
#include "raylib.h"
#include "Gui.h"

int main(void)
{
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
    const int windowWidth = 1200;
    const int windowHeight = 800;
    InitWindow(windowWidth, windowHeight, "Sorting Visualizer");
    //SetTargetFPS(500);
    Gui* gui = new Gui();

    while (!WindowShouldClose())
    {
        gui->DrawAndHandleButtons();
        gui->Update();
        BeginDrawing();
        ClearBackground(RAYWHITE);
        gui->Draw();
        EndDrawing();
    }
    CloseWindow();
    delete gui;

    _CrtDumpMemoryLeaks();
    return 0;
}