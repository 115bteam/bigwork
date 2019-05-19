#include "OnePara.h"
#include "calculation.h"
#include <iomanip>
using std::sin; using std::log; using std::exp; using std::cout; using std::endl; using std::fixed; using std::setprecision;

void OnePara::reset() {
	initialized = false;
	op->reset();
}


SIN::SIN(const string& tmpname, Point* tmpop){
	name = tmpname;
	op=tmpop;
}

float SIN::evaluate(){
	if(initialized)	return value;
	if (error())return 0;
	float tmp = op->evaluate();
	if (error())return 0;
	if (debug) {
		op->output();
	}
	initialized=true;
	value = sin(tmp);
	return value;
}

LOG::LOG(const string& tmpname, Point* tmpop){
	name = tmpname;
	op=tmpop;
}

bool LOG::negative_input = false;

float LOG::evaluate(){
	if(initialized)	return value;
	if (error())return 0;
	float tmp = op->evaluate();
	if (error())return 0;
	if (debug) {
		op->output();
	}
	if (tmp <= 0) {
		cout << "ERROR: LOG operator's input must be positive" << endl;
		negative_input = true;
		return 0;
	}
	initialized=true;
	value = log(tmp);
	return value;
}

EXP::EXP(const string& tmpname, Point* tmpop){
	name = tmpname;
	op=tmpop;
}

float EXP::evaluate(){
	if(initialized)	return value;
	if (error())return 0;
	float tmp = op->evaluate();
	if (error())return 0;
	if (debug) {
		op->output();
	}
	initialized=true;
	value = exp(tmp);
	return value;
}

TANH::TANH(const string& tmpname, Point* tmpop){
	name = tmpname;
	op=tmpop;
}

float TANH::evaluate(){
	if(initialized)	return value;
	if (error())return 0;
	float tmp = op->evaluate();
	if (error())return 0;
	if (debug) {
		op->output();
	}
	initialized=true;
	value = (exp(tmp)-1/exp(tmp))/(exp(tmp)+1/exp(tmp));
	return value;
}

SIGMOID::SIGMOID(const string& tmpname, Point* tmpop){
	name = tmpname;
	op=tmpop;
}

float SIGMOID::evaluate(){
	if(initialized)	return value;
	if (error())return 0;
	float tmp = op->evaluate();
	if (error())return 0;
	if (debug) {
		op->output();
	}
	initialized=true;
	value = 1/(1+1/exp(tmp));
	return value;
}

PRINT::PRINT(const string& tmpname, Point* tmpop) {
	name = tmpname;
	op = tmpop;
}

float PRINT::evaluate() {
	if (initialized)return value;
	if (error())return 0;
	float tmp = op->evaluate();
	if (error())return 0;
	if (debug) {
		op->output();
	}
	initialized = true;
	cout << "PRINT operator: " << op->name << " = " << fixed << setprecision(4) << tmp << endl;
	value = tmp;
	return value;
}


