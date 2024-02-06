#pragma once
#include <iostream>
#include "RectContainer.h"
#include "BubbleSort.h";
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

class Gui {
private:
	bool sortingRunning = false;

	RectContainer* rectContainer;
	BubbleSort* bubbleSort;
	InsertionSort* insertionSort;
	SelectionSort* selectionSort;

	void SortingLogic();
	void HandleAndDrawSortButton();


public:
	Gui();
	~Gui();
	void Update();
	void Draw();
};

Gui::Gui() {
	rectContainer = new RectContainer();
	bubbleSort = new BubbleSort();
	insertionSort = new InsertionSort();
	selectionSort = new SelectionSort();
}

Gui::~Gui() {
	delete rectContainer;
	delete bubbleSort;
	delete insertionSort;
	delete selectionSort;
}
//Button Handling
void Gui::HandleAndDrawSortButton() {
	if (GuiButton({ 0, 0, 200, 50 }, "Sort!")) {
		sortingRunning = sortingRunning == true ? false : true;
	}
}

void Gui::SortingLogic() {
	if (sortingRunning) {
		if (!rectContainer->IsSorted()) {
			rectContainer->ChangeSelectedColorBack(bubbleSort->j, insertionSort->j + 1);
		}

		if (!rectContainer->IsSorted()) {
			bubbleSort->Sort(rectContainer->rects);
		}
		else {
			std::cout << "SORTED" << std::endl;
			sortingRunning = false;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(0));

		if (!rectContainer->IsSorted()) {
			rectContainer->ChangeSelectedColor(bubbleSort->j, insertionSort->j + 1);
		}
	}
}

void Gui::Update() {
	HandleAndDrawSortButton();
	SortingLogic();
}

void Gui::Draw() {
	
	rectContainer->Draw();

	
}