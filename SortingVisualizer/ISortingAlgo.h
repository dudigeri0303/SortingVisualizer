#ifndef ISORTINGALGO_H
#define ISORTINGALGO_H
#include <iostream>
#include <vector>
#include "SortableRect.h"

class ISortingAlgo {
public:
	int i;
	int j;

	virtual ~ISortingAlgo() {};
	virtual void Sort(std::vector<SortableRect*>) = 0;
	virtual void Reset() = 0;
};
#endif