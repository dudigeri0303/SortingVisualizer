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
	RectContainer* rectContainer;
	BubbleSort* bubbleSort;
	InsertionSort* insertionSort;
	SelectionSort* selectionSort;


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

void Gui::Update() {
	if (!rectContainer->IsSorted()) {
		rectContainer->ChangeSelectedColorBack(bubbleSort->j, insertionSort->j + 1);
	}

	if (!rectContainer->IsSorted()) {
		bubbleSort->Sort(rectContainer->rects);
	}
	else {
		std::cout << "SORTED" << std::endl;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(0));
}

void Gui::Draw() {
	if (!rectContainer->IsSorted()) {
		rectContainer->ChangeSelectedColor(bubbleSort->j, insertionSort->j + 1);
	}
	rectContainer->Draw();

}