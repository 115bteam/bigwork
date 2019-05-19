#ifndef point_h
#define point_h
#include <string>
#include <iostream>
#include <iomanip>
using std::cout; using std::string; using std::cout; using std::endl; using std::fixed; using std::setprecision;
class Point{
public:
    string name;
    float value;
    bool initialized = false;
	virtual void reset() = 0;
    virtual float evaluate() = 0;
    virtual ~Point(){}
	virtual void setvalue(float) { cout << "setvalue error: wrong set object!!!" << endl; }
	void output() { cout << name << " = " << fixed << setprecision(4) << value << endl; }
};
#endif
