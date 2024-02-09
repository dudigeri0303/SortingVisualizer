#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "ISortingAlgo.h"
#include "BubbleSort.h";
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "CountingSort.h"
#include "BucketSort.h"

class SortingAlgoContainer {
private:
	

public:
	int selectedAlgoIndex = 0;
	std::vector<ISortingAlgo*> algos;
	std::vector<const char*> algoNames;

	SortingAlgoContainer(int);
	~SortingAlgoContainer();
	void InscraseSelectedAlgoIndex();
	void DecreaseSelectedAlgoIndex();
};

SortingAlgoContainer::SortingAlgoContainer(int shellSortN) {
	algos = {
		new BubbleSort(),
		new SelectionSort(),
		new InsertionSort(),
		new ShellSort(shellSortN),
		new CountingSort(),
		new BucketSort(),
		new MergeSort()
	};
	algoNames = {
		"Bubble Sort",
		"Selection Sort",
		"Insertion Sort",
		"Shell Sort",
		"Counting Sort",
		"Bucket Sort",
		"Merge Sort"
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