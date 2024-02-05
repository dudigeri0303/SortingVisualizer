#pragma once
#include "ISortingAlgo.h"
class InsertionSort : ISortingAlgo {
public:
	int j = 0;
	int i = j-1;
	float key = 0.0f;

	virtual void Sort(std::vector<SortableRect*> rects) override {
		if (key == 0.0f) {
			key = rects[j]->rect->height;
		}
		if (i >= 0 && rects[i]->rect->height > key) {
			rects[i + 1]->rect->height = rects[i]->rect->height;
			i--;
		}
		else if(j < rects.size()){
			rects[i + 1]->rect->height = key;
			j++;
			key = rects[j]->rect->height;
			i = j - 1;
		}
	}
};
