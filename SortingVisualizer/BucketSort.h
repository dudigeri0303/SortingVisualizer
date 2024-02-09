#pragma once
#include<iostream>
#include <map>
#include "ISortingAlgo.h"

class BucketSort : public ISortingAlgo {
private:
	std::map<float, int> buckets;
	int iteratorOffset;

public:
	BucketSort();
	virtual void Sort(std::vector<SortableRect*> rects) override;
	virtual void Reset() override;
};

BucketSort::BucketSort() {
	i = 0;
	j = 0;
	iteratorOffset = 0;
}

void BucketSort::Sort(std::vector<SortableRect*> rects) {
	if (i < rects.size()) {
		if (buckets.count(rects[i]->rect->height) == 0) {
			buckets.insert({ rects[i]->rect->height, 1 });
		}
		else {
			buckets[rects[i]->rect->height]++;
		}
		i++;
		if (i == rects.size()) {
			buckets.insert({ 0.0, 0 });
		}
	}
	if (i == rects.size() && j < rects.size()) {
		std::map<float, int>::iterator it = buckets.begin();
		for (int p = 0; p <= iteratorOffset; ++p) {
			++it;
		}
		rects[j]->rect->height = it->first;
		it->second--;
		if (it->second == 0) {
			iteratorOffset++;
		}
		j++;
	}
}

void BucketSort::Reset() {
	i = 0;
	j = 0;
	iteratorOffset = 0;
	buckets.clear();
}

