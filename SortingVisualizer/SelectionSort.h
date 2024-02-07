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
		i++;
		j = i + 1;
		min = i;
	}
}

void SelectionSort::Reset(){
	i = 0;
	j = i + 1;
	min = i;
}
