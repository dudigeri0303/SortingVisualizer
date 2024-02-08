#pragma once
#include <iostream>
#include <algorithm>
#include "ISortingAlgo.h"

class CountingSort : public ISortingAlgo {
private:
    std::vector<int> outputArray;
    bool outputArrayCreated;
    std::vector<int> CreateOutputArray(std::vector<SortableRect*> rects);

public:
	CountingSort();
	virtual void Sort(std::vector<SortableRect*> rects) override;
	virtual void Reset() override;
};

CountingSort::CountingSort() {
    i = 0;
    outputArrayCreated = false;
}

std::vector<int> CountingSort::CreateOutputArray(std::vector<SortableRect*> rects) {
    int vectorSize = rects.size();
    int maxValue = 0;
    for (int i = 0; i < vectorSize; i++) {
        if ((int)rects[i]->rect->height > maxValue) {
            maxValue = std::max(maxValue, (int)rects[i]->rect->height);
        }
    }

    std::vector<int> countArray(maxValue + 1, 0);
    for (int i = 0; i < vectorSize; i++) {
        countArray[(int)rects[i]->rect->height]++;
    }
    for (int i = 1; i <= maxValue; i++) {
        countArray[i] += countArray[i - 1];
    }

    std::vector<int> oArray(vectorSize);
    for (int i = vectorSize - 1; i >= 0; i--){
        oArray[countArray[rects[i]->rect->height] - 1]
            = rects[i]->rect->height;

        countArray[rects[i]->rect->height]--;
    }
    outputArrayCreated = true;
    return oArray;
}

void CountingSort::Sort(std::vector<SortableRect*> rects) {
    if (!outputArrayCreated) {
        std::cout << i << std::endl;
        outputArray = CreateOutputArray(rects);
    }
    if (i < rects.size() - 1) {
        rects[i]->rect->height = outputArray[i];
        i++;
    }
    else {
        rects[rects.size() - 1]->rect->height = outputArray[outputArray.size() - 1];
    }
}

void CountingSort::Reset() {
    i = 0;
    outputArrayCreated = false;
    outputArray.clear();
}