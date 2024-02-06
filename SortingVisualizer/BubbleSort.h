#pragma once
#include "ISortingAlgo.h"

class BubbleSort : public ISortingAlgo{
public:
	int i = 1;
	int j = 0;

	virtual void Sort(std::vector<SortableRect*> rects) override {
		if (rects[j]->rect->height > rects[j+1]->rect->height) {
			auto temp = rects[j]->rect->height;
			rects[j]->rect->height = rects[j+1]->rect->height;
			rects[j+1]->rect->height = temp;
		}
		if (j < rects.size() - i) {
			j++;
		}
		if (j == rects.size() - i && i < rects.size()) {
			i++;
			j = 0;
		}
	}
	
	virtual void Reset() override {
		i = 1;
		j = 0;
	}
};