#include <chrono>
#include <iostream>
#include <thread>
#include "raylib.h"
#include "RectContainer.h"
#include "BubbleSort.h"


int main(void)
{
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

    const int windowWidth = 1200;
    const int windowHeight = 800;
    RectContainer* rects = new RectContainer();
    BubbleSort* bubbleSort = new BubbleSort();

    InitWindow(windowWidth, windowHeight, "Sorting Visualizer");
    
    while (!WindowShouldClose())
    {
        if (!rects->IsSorted()) {
            rects->ChangeSelectedColor(bubbleSort->j, bubbleSort->j + 1);
        }
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        rects->Draw();
        EndDrawing();
        
        if (!rects->IsSorted()) {
            rects->ChangeSelectedColorBack(bubbleSort->j, bubbleSort->j + 1);
        }

        if (!rects->IsSorted()) {
            bubbleSort->Sort(rects->rects);
        }
        else {
            std::cout << "SORTED" << std::endl;
        }
        //std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    CloseWindow();
    delete rects;
    delete bubbleSort;
    
    _CrtDumpMemoryLeaks();
    return 0;
}