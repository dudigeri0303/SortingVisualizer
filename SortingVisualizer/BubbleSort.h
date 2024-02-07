#pragma once
#include "ISortingAlgo.h"

class BubbleSort : public ISortingAlgo{
public:
	BubbleSort();
	virtual void Sort(std::vector<SortableRect*> rects) override;
	virtual void Reset() override;
};

BubbleSort::BubbleSort() {
	i = 1;
	j = 0;
}

void BubbleSort::Sort(std::vector<SortableRect*> rects){
	if (rects[j]->rect->height > rects[j + 1]->rect->height) {
		auto temp = rects[j]->rect->height;
		rects[j]->rect->height = rects[j + 1]->rect->height;
		rects[j + 1]->rect->height = temp;
	}
	if (j < rects.size() - i) {
		j++;
	}
	if (j == rects.size() - i && i < rects.size()) {
		i++;
		j = 0;
	}
}

void BubbleSort::Reset(){
	i = 1;
	j = 0;
}