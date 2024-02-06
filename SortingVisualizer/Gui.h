#pragma once
#include <iostream>
#include "RectContainer.h"
#include "SortingAlgoContainer.h"
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

class Gui {
private:
	bool sortingRunning = false;

	RectContainer* rectContainer;
	SortingAlgoContainer* sortingAlgoContainer;

	void SortingLogic();
	void HandleAndDrawSortButton();
	void HandleAndDrawStopButton();
	void HandleAndDrawGenerateButton();
	void HandleAlgoChooser();


public:
	Gui();
	~Gui();
	void DrawAndHandleButtons();
	void Update();
	void Draw();
};

Gui::Gui() {
	rectContainer = new RectContainer();
	sortingAlgoContainer = new SortingAlgoContainer();
}

Gui::~Gui() {
	delete rectContainer;
	delete sortingAlgoContainer;
}
//Button Handling
void Gui::HandleAndDrawSortButton() {
	if (GuiButton({ 0, 0, 200, 50 }, "Sort!")) {
		if (!sortingRunning) {
			sortingRunning = true;
		}
	}
}

void Gui::HandleAndDrawStopButton() {
	if (GuiButton({ 210, 0, 200, 50 }, "Stop!")) {
		if (sortingRunning) {
			sortingRunning = false;
		}
	}
}

void Gui::HandleAndDrawGenerateButton() {
	if (GuiButton({ 410, 0, 200, 50 }, "Generate New!")) {
		sortingRunning = false;
		rectContainer->GenerateNewRects();
	}
}

void Gui::HandleAlgoChooser() {
	if (GuiButton({ 650, 0, 100, 50 }, "Previous!")) {
		sortingAlgoContainer->DecreaseSelectedAlgoIndex();
	}

	GuiLabel({ 760, 0, 90, 50 }, sortingAlgoContainer->algoNames[sortingAlgoContainer->selectedAlgoIndex]);

	if (GuiButton({ 860, 0, 100, 50 }, "Next!")) {
		sortingAlgoContainer->InscraseSelectedAlgoIndex();
	}
}

void Gui::SortingLogic() {
	if (sortingRunning) {
		/*if (!rectContainer->IsSorted()) {
			rectContainer->ChangeSelectedColorBack(bubbleSort->j, insertionSort->j + 1);
		}*/

		if (!rectContainer->IsSorted()) {
			sortingAlgoContainer->algos[sortingAlgoContainer->selectedAlgoIndex]->Sort(rectContainer->rects);
		}
		else {
			std::cout << "SORTED" << std::endl;
			sortingRunning = false;
			sortingAlgoContainer->algos[sortingAlgoContainer->selectedAlgoIndex]->Reset();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(0));

		/*if (!rectContainer->IsSorted()) {
			rectContainer->ChangeSelectedColor(bubbleSort->j, insertionSort->j + 1);
		}*/
	}
}

void Gui::DrawAndHandleButtons() {
	HandleAndDrawGenerateButton();
	HandleAndDrawSortButton();
	HandleAndDrawStopButton();
	HandleAlgoChooser();
}

void Gui::Update() {
	SortingLogic();
}

void Gui::Draw() {
	rectContainer->Draw();
}