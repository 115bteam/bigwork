#pragma once
#include "Point.h"
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class OnePara : public Point{
public : 
	Point* op;
	void reset();
	~OnePara() {}
};

class SIN : public OnePara{
public :
	SIN(const string&, Point*);
	float evaluate();
	~SIN() {}
};

class LOG : public OnePara{
public :
	static bool negative_input;
	LOG(const string&, Point*);
	float evaluate();
	~LOG() {}
};

class EXP : public OnePara{
public :
	EXP(const string&, Point*);
	float evaluate();
	~EXP() {}
};

class TANH : public OnePara{
public :
	TANH(const string&, Point*);
	float evaluate();
	~TANH() {}
};

class SIGMOID : public OnePara{
public :
	SIGMOID(const string&, Point*);
	float evaluate();
	~SIGMOID() {}
};

class PRINT : public OnePara {
public :
	PRINT(const string&, Point*);
	float evaluate();
	~PRINT(){}
};
