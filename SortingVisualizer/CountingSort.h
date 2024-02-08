#pragma once
#include <iostream>
#include <algorithm>
#include "ISortingAlgo.h"

class CountingSort : public ISortingAlgo {
private:
    std::vector<int> outputArry = {};

public:
	CountingSort();
	virtual void Sort(std::vector<SortableRect*> rects) override;
	virtual void Reset() override;
};

CountingSort::CountingSort() {

}

void CountingSort::Sort(std::vector<SortableRect*> rects) {
    int N = rects.size();

    // Finding the maximum element of array inputArray[].
    int M = 0;

    for (int i = 0; i < N; i++)
        M = std::max(M, (int)rects[i]->rect->height);

    // Initializing countArray[] with 0
    std::vector<int> countArray(M + 1, 0);

    // Mapping each element of inputArray[] as an index
    // of countArray[] array

    for (int i = 0; i < N; i++)
        countArray[(int)rects[i]->rect->height]++;

    // Calculating prefix sum at every index
    // of array countArray[]
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];

    // Creating outputArray[] from countArray[] array
    std::vector<int> outputArray(N);

    for (int i = N - 1; i >= 0; i--)

    {
        outputArray[countArray[rects[i]->rect->height] - 1]
            = rects[i]->rect->height;

        countArray[rects[i]->rect->height]--;
    }

    for (int i = 0; i < rects.size(); i++) {
        rects[i]->rect->height = outputArray[i];
    }
}

void CountingSort::Reset() {

}