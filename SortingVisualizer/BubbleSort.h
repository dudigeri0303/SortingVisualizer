#pragma once
#include "ISortingAlgo.h"

class BubbleSort : ISortingAlgo{
public:
	int i = 1;
	int j = 0;

	virtual void Sort(std::vector<SortableRect*> rects) override {
		if (rects[j]->rect->height > rects[j+1]->rect->height) {
			auto temp = rects[j]->rect->height;
			rects[j]->rect->height = rects[j+1]->rect->height;
			rects[j+1]->rect->height = temp;
		}
		if (j < rects.size() - 1) {
			j++;

		}
		if (j == rects.size() - 1 && i < rects.size()) {
			i++;
			j = 0;
		}
	}
};