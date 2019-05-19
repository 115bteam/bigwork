#ifndef nfunc_h
#define nfunc_h
#include <iostream>
#include <string>
#include "Point.h"
using std::string; using std::cout; using std::endl;
class nfunc:public Point{
public:
    char property;
	virtual void setvalue(float) { cout << "setvalue error: wrong set object!!!" << endl; }
	void reset();
    virtual float evaluate() = 0;
};

class Placeholder:public nfunc {
public:
	static bool placeholder_missing;
    float value;
	Placeholder(string);
    virtual float evaluate();
    ~Placeholder(){};
};

class Constant:public nfunc{
public:
    float value;
	Constant(string, float);
    virtual float evaluate();
    ~Constant(){};
};

class Variable:public nfunc{
public:
    float value;
	Variable(string, float);
    virtual void setvalue(float);
    virtual float evaluate();
    ~Variable(){};
};
#endif
