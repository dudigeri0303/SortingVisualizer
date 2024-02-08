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

	void Merge(std::vector<SortableRect*> rects);

public:
	MergeSort();
	virtual void Sort(std::vector<SortableRect*> rects) override;
	virtual void Reset() override;

};

MergeSort::MergeSort() {
	i = 0;
	j = 1;
	subArraySize = 1;
	k = i + subArraySize;
	l = j + subArraySize;
}

void MergeSort::Merge(std::vector<SortableRect*> rects){
	if (i < k && j < l) {
		if (rects[i]->rect->height < rects[j]->rect->height) {
			d.push_back(rects[i]);
			//std::cout << "i1:" << rects[i]->rect->height << std::endl;
			i++;
		}
		else {
			d.push_back(rects[j]);
			//std::cout << "j1:" << rects[j]->rect->height << std::endl;
			j++;
		}
	}
	else {
		if (j < l) {
			d.push_back(rects[j]);
			//std::cout << "j2:" << rects[j]->rect->height << std::endl;
			j++;
		}
		else {	
			d.push_back(rects[i]);
			//std::cout << "i2:" << rects[i]->rect->height << std::endl;
			i++;		
		}
	}
}

void MergeSort::Sort(std::vector<SortableRect*> rects) {
	std::cout << "i= " << i << std::endl;
	std::cout << "j= " << j << std::endl;
	std::cout << "------------" << std::endl;
	Merge(rects);
	if (d.size() == subArraySize * 2){
		int q = i - subArraySize;
		for (auto r : d) {
			//std::cout << "dRect:" << r->rect->height << std::endl;
			rects[q]->rect->height = r->rect->height;
			q++;
		}
		d.clear();
		//std::cout << "---------" << std::endl;
		if (j < rects.size()) {
			if (i + subArraySize < rects.size() - 1) {
				i = j;
				k = i + subArraySize;
				j = i + subArraySize;
				l = j + subArraySize;
			}
			else {
				i = j;
				k = i + subArraySize;
				j = rects.size() - 2;
				l = rects.size() - 1;
				//std::cout << "fostosfos" << std::endl;
			}
		}
		else {
			subArraySize *= 2;
			i = 0;
			j = i + subArraySize;
			k = i + subArraySize;
			l = j + subArraySize;
		}
	}
}

void MergeSort::Reset() {
	i = 0;
	j = 1;
	subArraySize = 1;
	k = i + subArraySize;
	l = j + subArraySize;
}