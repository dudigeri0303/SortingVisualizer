#pragma once
#include "ISortingAlgo.h"

class SelectionSort : public ISortingAlgo {
private:
	int min;

public:
	SelectionSort();
	virtual void Sort(std::vector<SortableRect*> rects) override;
	virtual void Reset() override;
};

SelectionSort::SelectionSort() {
	i = 0;
	j = i + 1;
	min = i;
}

void SelectionSort::Sort(std::vector<SortableRect*> rects){
	if (rects[j]->rect->height < rects[min]->rect->height) {
		min = j;
	}
	if (j < rects.size()) {
		j++;
	}
	if (j == rects.size() && i < rects.size() - 1) {
		auto temp = rects[i]->rect->height;
		rects[i]->rect->height = rects[min]->rect->height;
		rects[min]->rect->height = temp;
		std::cout << i << std::endl;
		std::cout << j << std::endl;
		std::cout << "--------------" << std::endl;
		i++;
		if (j < rects.size()) {
			j = i + 1;
		}
		else {
			j = i;
		}
		
		min = i;
	}
}

void SelectionSort::Reset(){
	std::cout << "++++++++++++++" << std::endl;
	i = 0;
	j = i + 1;
	min = i;
}
