#pragma once
#include "ISortingAlgo.h"

class RadixSort : public ISortingAlgo {
private:

public:
	RadixSort();
	virtual void Sort(std::vector<SortableRect*> rects) override;
	virtual void Reset() override;

};
