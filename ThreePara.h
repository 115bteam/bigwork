#pragma once
#include "Point.h"

class ThreePara :public Point {
public:
	Point *op_first, *op_second, *op_third;
	void reset();
	virtual float evaluate() = 0;
};

class COND :public ThreePara {
public:
	COND(const string&, Point*, Point*, Point*);
	float evaluate();
};
