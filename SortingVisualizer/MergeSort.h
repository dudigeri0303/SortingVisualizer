#pragma once
#include <iostream>
#include <vector>
#include "ISortingAlgo.h"

class MergeSort : public ISortingAlgo {
private:
	std::vector<SortableRect*> d{};
	int subArraySize;
	int k;
	int l;
	int iterations;

	void Merge(std::vector<SortableRect*> rects);

public:
	MergeSort();
	virtual void Sort(std::vector<SortableRect*> rects) override;
	virtual void Reset() override;

};

MergeSort::MergeSort() {
	i = 0;
	j = 2;
	subArraySize = 1;
	k = i + subArraySize;
	l = j + subArraySize;
	iterations = 1;
}

void MergeSort::Merge(std::vector<SortableRect*> rects){
	if (i < k && j < l) {
		if (rects[i]->rect->height < rects[j]->rect->height) {
			d.push_back(rects[i]);
			i++;
		}
		else {
			d.push_back(rects[j]);
			j++;
		}
	}

	else if (i == k) {
		if (j < l) {
			d.push_back(rects[j]);
			j++;
		}
	}
	else {
		if (i < k) {
			d.push_back(rects[i]);
			i++;
		}
	}
}

void MergeSort::Sort(std::vector<SortableRect*> rects) {
	Merge(rects);
	if (d.size() == subArraySize * 2){
		//std::cout << d.size() << std::endl;
		int q = i - subArraySize;
		for (auto r : d) {
			rects[q]->rect->height = r->rect->height;
		}
		d.clear();
		k = i + subArraySize;
		l = j + subArraySize;
		if (k > rects.size() - 1) {
			k = rects.size() - 1;
			//std::cout << "i:" << i << "-k:" << k << std::endl;
		}
		else if (l > rects.size() - 1) {
			l = rects.size() - 1;
			//std::cout << "j:" << j << "-l:" << l << std::endl;
		}
	}
}

void MergeSort::Reset() {
	
}