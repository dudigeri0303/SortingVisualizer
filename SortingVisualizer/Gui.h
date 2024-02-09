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
	float delay = 0.0f;
	float size = 170.0f;
	RectContainer* rectContainer;
	SortingAlgoContainer* algoChooser;

	void SortingLogic();
	void HandleAndDrawSortButton();
	void HandleAndDrawStopButton();
	void HandleAndDrawGenerateButton();
	void HandleAndDrawDelaySlider();
	void HandleAndDrawSizeSlider();
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
	algoChooser = new SortingAlgoContainer(rectContainer->rects.size()-1);
}

Gui::~Gui() {
	delete rectContainer;
	delete algoChooser;
}
//Button Handling
void Gui::HandleAndDrawSortButton() {
	if (GuiButton({ 210, 700, 50, 30 }, "Sort!") && !sortingRunning) {
		sortingRunning = true;
	}
}

void Gui::HandleAndDrawStopButton() {
	if (GuiButton({ 210, 750, 50, 30 }, "Stop!") && sortingRunning) {
		sortingRunning = false;
	}
}

void Gui::HandleAndDrawGenerateButton() {
	if (GuiButton({ 300, 700, 150, 30 }, "Generate New!") && !sortingRunning) {
		sortingRunning = false;
		rectContainer->GenerateNewRects();
		algoChooser->algos[algoChooser->selectedAlgoIndex]->Reset();
	}
}

void Gui::HandleAndDrawDelaySlider() {
	delay = GuiSlider({ 530, 750, 170, 30 }, "Delay", NULL, &delay, 0.0f, 500.0f);
}

void Gui::HandleAndDrawSizeSlider() {
	size = GuiSlider({ 320, 750, 130, 30 }, "Size", NULL, &size, 10.0f, 170.0f);
}

void Gui::HandleAlgoChooser() {
	if (GuiButton({ 490, 700, 70, 30 }, "Previous!")) {
		algoChooser->DecreaseSelectedAlgoIndex();
	}

	GuiLabel({ 570, 700, 90, 30 }, algoChooser->algoNames[algoChooser->selectedAlgoIndex]);

	if (GuiButton({ 650, 700, 70, 30 }, "Next!")) {
		algoChooser->InscraseSelectedAlgoIndex();
	}
}

void Gui::SortingLogic() {
	if (sortingRunning) {
		//Changing the actual rects colors back to black
		if (algoChooser->selectedAlgoIndex == 0) {
			if (!rectContainer->IsSorted()) {
				rectContainer->ChangeSelectedColorBack(algoChooser->algos[algoChooser->selectedAlgoIndex]->j, algoChooser->algos[algoChooser->selectedAlgoIndex]->j + 1, rectContainer->rects.size());
			}
		}
		else {
			rectContainer->ChangeSelectedColorBack(algoChooser->algos[algoChooser->selectedAlgoIndex]->i, algoChooser->algos[algoChooser->selectedAlgoIndex]->j, rectContainer->rects.size());
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
		
		//Changing the the actual rects colors to green
		if (algoChooser->selectedAlgoIndex == 0) {
			if (!rectContainer->IsSorted()) {
				rectContainer->ChangeSelectedColor(algoChooser->algos[algoChooser->selectedAlgoIndex]->j, algoChooser->algos[algoChooser->selectedAlgoIndex]->j + 1, rectContainer->rects.size());
			}
		}
		else {
			rectContainer->ChangeSelectedColor(algoChooser->algos[algoChooser->selectedAlgoIndex]->i, algoChooser->algos[algoChooser->selectedAlgoIndex]->j, rectContainer->rects.size());
		}

		//Applying the choosen delay
		//std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
}

void Gui::DrawAndHandleButtons() {
	HandleAndDrawGenerateButton();
	HandleAndDrawSortButton();
	HandleAndDrawStopButton();
	HandleAndDrawDelaySlider();
	HandleAndDrawSizeSlider();
	HandleAlgoChooser();
}

void Gui::Update() {
	SortingLogic();
	//std::cout << GetFPS() << std::endl;
}

void Gui::Draw() {
	rectContainer->Draw();
}