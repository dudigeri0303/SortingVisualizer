#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "SortableRect.h"

class RectContainer {
private:
	std::vector<SortableRect*> FillRectsList();
public:
	std::vector<SortableRect*> rects;

	RectContainer();
	~RectContainer();
	bool IsSorted();
	void ChangeSelectedColor(int, int);
	void ChangeSelectedColorBack(int, int);
	void Draw();
};

RectContainer::RectContainer() {
	rects = FillRectsList();
}

RectContainer::~RectContainer() {
	for (int i = 0; i < rects.size(); i++) {
		delete rects[i];
	}
	rects.clear();
}

std::vector<SortableRect*> RectContainer::FillRectsList(){
	std::vector<SortableRect*> returnList;
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(20, 500);
	for (int i = 0; i < 170; i++) {
		returnList.push_back(new SortableRect((10.0f + i*7.0f), 700.0f, 5.0f, (float)dist6(rng)));
	}
	return returnList;
}

void RectContainer::Draw(){
	for (auto rect : rects) {
		rect->Draw();
	}
}

bool RectContainer::IsSorted() {
	for (int i = 0; i < rects.size() - 1; i++) {
		if (rects[i]->rect->height > rects[i + 1]->rect->height) {
			return false;
		}
	}
	return true;
}

void RectContainer::ChangeSelectedColor(int i, int j) {
	if (i > 0) {
		rects[i]->color = GREEN;
	}
	if (j > 0) {
		rects[j]->color = GREEN;
	}
}

void RectContainer::ChangeSelectedColorBack(int i, int j) {
	if (i > 0) {
		rects[i]->color = BLACK;
	}
	if (j > 0) {
		rects[j]->color = BLACK;
	}
}

