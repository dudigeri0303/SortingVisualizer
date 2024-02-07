#pragma once
#include "ISortingAlgo.h"

class InsertionSort : public ISortingAlgo {
private:
	float key = 0.0f;

public:
	InsertionSort();
	virtual void Sort(std::vector<SortableRect*> rects) override; 
	virtual void Reset() override;
};

InsertionSort::InsertionSort() {
	j = 0;
	i = j - 1;
}

void InsertionSort::Sort(std::vector<SortableRect*> rects){
	if (key == 0.0f) {
		key = rects[j]->rect->height;
	}
	if (i >= 0 && rects[i]->rect->height > key) {
		rects[i + 1]->rect->height = rects[i]->rect->height;
		i--;
	}
	else if (j < rects.size()) {
		rects[i + 1]->rect->height = key;
		j++;
		key = rects[j]->rect->height;
		i = j - 1;
	}
}

void InsertionSort::Reset(){
	j = 0;
	i = j - 1;
	key = 0.0f;
}
