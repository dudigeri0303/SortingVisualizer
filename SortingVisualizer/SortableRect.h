#ifndef SORTABLERECT_H
#define SORTABLERECT_H
#include <iostream>
#include "raylib.h"
#include "raygui.h"

class SortableRect {
private:
	Vector2 origin;

public:
	RAYLIB_H::Rectangle* rect;
	RAYLIB_H::Color color;

	SortableRect(float, float, float, float);
	~SortableRect();
	void Update();
	void Draw();
};

SortableRect::SortableRect(float x, float y, float width, float height) {
	SortableRect::color = BLACK;
	SortableRect::rect = new Rectangle{x, y, width, height};
	SortableRect::origin = { 0, 0 };
}

SortableRect::~SortableRect() {
	delete rect;
}

void SortableRect::Update() {

}

void SortableRect::Draw() {
	DrawRectanglePro(*rect, origin, 180.0f, color);
}
#endif
