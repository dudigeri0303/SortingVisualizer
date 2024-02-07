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
	SortingAlgoContainer* algoChooser;

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
	algoChooser = new SortingAlgoContainer();
}

Gui::~Gui() {
	delete rectContainer;
	delete algoChooser;
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
		algoChooser->DecreaseSelectedAlgoIndex();
	}

	GuiLabel({ 760, 0, 90, 50 }, algoChooser->algoNames[algoChooser->selectedAlgoIndex]);

	if (GuiButton({ 860, 0, 100, 50 }, "Next!")) {
		algoChooser->InscraseSelectedAlgoIndex();
	}
}

void Gui::SortingLogic() {
	if (sortingRunning) {
		//Changing the actual rects colors back to black
		if (algoChooser->selectedAlgoIndex == 0) {
			if (!rectContainer->IsSorted()) {
				rectContainer->ChangeSelectedColorBack(algoChooser->algos[algoChooser->selectedAlgoIndex]->j, algoChooser->algos[algoChooser->selectedAlgoIndex]->j + 1);
			}
		}
		else {
			rectContainer->ChangeSelectedColorBack(algoChooser->algos[algoChooser->selectedAlgoIndex]->i, algoChooser->algos[algoChooser->selectedAlgoIndex]->j);
		}

		//Running the sorting algo if the rects arent sorted already
		if (!rectContainer->IsSorted()) {
			algoChooser->algos[algoChooser->selectedAlgoIndex]->Sort(rectContainer->rects);
		}
		else {
			std::cout << "SORTED" << std::endl;
			sortingRunning = false;
			algoChooser->algos[algoChooser->selectedAlgoIndex]->Reset();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(0));

		//Changing the the actual rects colors to green
		if (algoChooser->selectedAlgoIndex == 0) {
			if (!rectContainer->IsSorted()) {
				rectContainer->ChangeSelectedColor(algoChooser->algos[algoChooser->selectedAlgoIndex]->j, algoChooser->algos[algoChooser->selectedAlgoIndex]->j + 1);
			}
		}
		else {
			rectContainer->ChangeSelectedColor(algoChooser->algos[algoChooser->selectedAlgoIndex]->i, algoChooser->algos[algoChooser->selectedAlgoIndex]->j);
		}
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