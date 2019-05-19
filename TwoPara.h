#pragma once
#include <iostream>
#include <cstring>
#include <cmath>
#include "Point.h"

using std::string;

class TwoPara : public Point {
public:
	Point* op_first;
	Point* op_second;
	void reset();
	~TwoPara() {}
};

class ADD : public TwoPara{
public:
    ADD(const string&, Point*, Point*);
    float evaluate();
    ~ADD() {};
};

class SUBTRACTION : public TwoPara{
public:
    SUBTRACTION(const string&, Point*, Point*);
    float evaluate();
    ~SUBTRACTION() {};
};

class MULTIPLICATION : public TwoPara{
public:
    MULTIPLICATION(const string&, Point*, Point*);
    float evaluate();
    ~MULTIPLICATION() {};
};

class DIVISION : public TwoPara{
public:
	static bool division_zero;
    DIVISION(const string&, Point*, Point*);
    float evaluate();
    ~DIVISION() {};
};

class GREATER_THAN : public TwoPara{
public:
	GREATER_THAN(const string&, Point*, Point*);
	float evaluate();
	~GREATER_THAN() {}
};

class LESS_THAN : public TwoPara{
public:
	LESS_THAN(const string&, Point*, Point*);
	float evaluate();
	~LESS_THAN() {}
};

class GREATER_OR_EQUAL : public TwoPara{
public:
	GREATER_OR_EQUAL(const string&, Point*, Point*);
	float evaluate();
	~GREATER_OR_EQUAL() {}
};

class LESS_OR_EQUAL : public TwoPara{
public:
	LESS_OR_EQUAL(const string&, Point*, Point*);
	float evaluate();
	~LESS_OR_EQUAL() {}
};

class EQUAL : public TwoPara{
public: 
	EQUAL(const string&, Point*, Point*);
	float evaluate();
	~EQUAL() {}
};
