#include <iostream>
#include "nfunc.h"
#include "calculation.h"
using std::string; using std::cout; using std::endl;

void nfunc::reset() {
	initialized = false;
}

Placeholder::Placeholder(string N) { name = N; property = 'P'; }

bool Placeholder::placeholder_missing = false;

float Placeholder::evaluate(){
	if (initialized)return value;
	if (valuerecord.count(name)) {
		value = valuerecord[name];
		initialized = true;
		return value;
	}
	if (error())return 0;
	placeholder_missing = true;
	cout << "ERROR: Placeholder missing" << endl;
	return 0;
}

Constant::Constant(string N, float V) { name = N; value = V; property = 'C'; }


float Constant::evaluate(){
    return value;
}

Variable::Variable(string N, float V) { name = N; value = V; property = 'V'; }


void Variable::setvalue(float VALUE){
    value=VALUE;
}

float Variable::evaluate(){
	if (valuerecord.count(name)) {
		value = valuerecord[name];
	}
    return value;
}

