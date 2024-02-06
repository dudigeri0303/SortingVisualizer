#pragma once
#include "ISortingAlgo.h"
class SelectionSort : public ISortingAlgo {
public:
	int i = 0;
	int j = i + 1;
	int min = i;

	virtual void Sort(std::vector<SortableRect*> rects) override {
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

	virtual void Reset() override {
		i = 0;
		j = i + 1;
		min = i;
	}
};
