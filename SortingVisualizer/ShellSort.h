#pragma once
#include "ISortingAlgo.h"


class ShellSort : public ISortingAlgo {
private:
    int interval;
    int temp;

public:
    int n;
	ShellSort(int);
	virtual void Sort(std::vector<SortableRect*> rects) override;
	virtual void Reset() override;

};

ShellSort::ShellSort(int nValue) {
    n = nValue;
    interval = n / 2;
    i = interval;
    j = i;
    temp = 0;
}

void ShellSort::Sort(std::vector<SortableRect*> rects) {
    if (temp == 0) {
        temp = rects[i]->rect->height;
    }
    if (j >= interval && rects[j - interval]->rect->height > temp) {
        rects[j]->rect->height = rects[j - interval]->rect->height;
        j -= interval;
    }
    if ((j < interval || rects[j - interval]->rect->height <= temp) && i < n) {
        rects[j]->rect->height = temp;
        i++;
        temp = rects[i]->rect->height;
        j = i;
    }
    if ((j < interval || rects[j - interval]->rect->height <= temp) && i >= n && interval > 0) {
        interval /= 2;
        i = interval;
        j = i;
    }
}

void ShellSort::Reset() {
    interval = n / 2;
    i = interval;
    j = i;
    temp = 0;
}

