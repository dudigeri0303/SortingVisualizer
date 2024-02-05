#include <chrono>
#include <iostream>
#include <thread>
#include "raylib.h"
#include "RectContainer.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"

int main(void)
{
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

    const int windowWidth = 1200;
    const int windowHeight = 800;
    RectContainer* rects = new RectContainer();
    BubbleSort* bubbleSort = new BubbleSort();
    InsertionSort* insertionSort = new InsertionSort();
    SelectionSort* selectionSort = new SelectionSort();

    //selectionSort->Sort(rects->rects);

    InitWindow(windowWidth, windowHeight, "Sorting Visualizer");

    while (!WindowShouldClose())
    {
        if (!rects->IsSorted()) {
            rects->ChangeSelectedColor(insertionSort->i, insertionSort->j);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        rects->Draw();
        EndDrawing();

        if (!rects->IsSorted()) {
            rects->ChangeSelectedColorBack(insertionSort->i, insertionSort->j);
        }

        if (!rects->IsSorted()) {
            selectionSort->Sort(rects->rects);
        }
        else {
            std::cout << "SORTED" << std::endl;
        }
        //std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    CloseWindow();
    delete rects;
    delete bubbleSort;
    delete insertionSort;
    delete selectionSort;

    _CrtDumpMemoryLeaks();
    return 0;
}