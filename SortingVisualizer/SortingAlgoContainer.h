#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "ISortingAlgo.h"
#include "BubbleSort.h";
#include "SelectionSort.h"
#include "InsertionSort.h"

class SortingAlgoContainer {
private:
	

public:
	int selectedAlgoIndex = 0;
	std::vector<ISortingAlgo*> algos;
	std::vector<const char*> algoNames;

	SortingAlgoContainer();
	~SortingAlgoContainer();
	void InscraseSelectedAlgoIndex();
	void DecreaseSelectedAlgoIndex();
};

SortingAlgoContainer::SortingAlgoContainer() {
	algos = {
		new BubbleSort(),
		new SelectionSort(),
		new InsertionSort()
	};
	algoNames = {
		"Bubble Sort",
		"Selection Sort",
		"InsertionSort"
	};
}

SortingAlgoContainer::~SortingAlgoContainer() {
	for (auto a : algos) {
		delete a;
	}
	algos.clear();
}

void SortingAlgoContainer::InscraseSelectedAlgoIndex() {
	if (selectedAlgoIndex < algos.size() - 1) {
		selectedAlgoIndex++;
	}
}

void SortingAlgoContainer::DecreaseSelectedAlgoIndex() {
	if (selectedAlgoIndex > 0) {
		selectedAlgoIndex--;
	}
}