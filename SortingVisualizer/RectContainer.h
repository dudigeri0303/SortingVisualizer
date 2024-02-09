#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "SortableRect.h"

class RectContainer {
private:
	std::vector<SortableRect*> FillRectsList(int);
public:
	std::vector<SortableRect*> rects;

	RectContainer();
	~RectContainer();
	bool IsSorted();
	void ChangeSelectedColor(int, int, int);
	void ChangeSelectedColorBack(int, int, int);
	void GenerateNewRects(int);
	void Draw();
};

RectContainer::RectContainer() {
	rects = FillRectsList(170);
}

RectContainer::~RectContainer() {
	for (int i = 0; i < rects.size(); i++) {
		delete rects[i];
	}
	rects.clear();
}

std::vector<SortableRect*> RectContainer::FillRectsList(int numOfRects) {
	float rectWidth = 1200 / numOfRects - 2.0f;
	if (rects.size() == 0) {
		std::vector<SortableRect*> returnList;
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist6(20, 640);
		for (int i = 0; i < numOfRects; i++) {
			//(self.sbc + self.width)* self.y + self.sbc
			returnList.push_back(new SortableRect((i * (rectWidth + 2.0f)), 650.0f, rectWidth, (float)dist6(rng)));
		}
		return returnList;
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

void RectContainer::ChangeSelectedColor(int i, int j, int max) {
	if (i > 0 && i < max) {
		rects[i]->color = GREEN;
	}
	if (j > 0 && j < max) {
		rects[j]->color = GREEN;
	}
}

void RectContainer::ChangeSelectedColorBack(int i, int j, int max) {
	if (i > 0 && i < max) {
		rects[i]->color = BLACK;
	}
	if (j > 0 && j < max) {
		rects[j]->color = BLACK;
	}
}

void RectContainer::GenerateNewRects(int numOfRects) {
	for (int i = 0; i < rects.size(); i++) {
		delete rects[i];
	}
	rects.clear();
	rects = FillRectsList(numOfRects);
}

void RectContainer::Draw() {
	for (auto rect : rects) {
		rect->Draw();
	}
}

