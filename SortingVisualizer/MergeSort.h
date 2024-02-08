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
	iterations = 0;
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
		for (int q = 0; q < d.size(); q++) {
			rects[iterations * (q + 1 ) + 1 + iterations]->rect->height = d[q]->rect->height;
			std::cout << q << std::endl;
			std::cout << iterations * (q + 1) + iterations<< std::endl;
			std::cout << "---------------" << std::endl;
		}
		std::cout << "++++++++" << std::endl;
		iterations++;
		d.clear();
		i += 2 * subArraySize;
		j += 2 * subArraySize;
		k = i + subArraySize;
		l = j + subArraySize;
		if (j + subArraySize == rects.size() - 1) {
			subArraySize *= 2;
			iterations = 0;
		}
	}
}

void MergeSort::Reset() {
	
}