#include "TwoPara.h"
#include "calculation.h"

using std::string; using std::cout; using std::endl;

void TwoPara::reset() {
	initialized = false;
	op_first->reset();
	op_second->reset();
}

ADD::ADD(const string& tmpname, Point* C,Point* D){
	name = tmpname; op_first = C; op_second = D;
}

float ADD::evaluate(){
    if (initialized) return value;
	if (error())return 0;
	float tmp_first = op_first->evaluate(), tmp_second = op_second->evaluate();
	if (error())return 0;
	if (debug) {
		op_first->output();
		op_second->output();
	}
    initialized=true;
	value = tmp_first + tmp_second;
    return value;
}
SUBTRACTION::SUBTRACTION(const string& tmpname, Point* C,Point* D){
	name = tmpname; op_first =C; op_second=D;
}

float SUBTRACTION::evaluate(){
    if (initialized) return value;
	if (error())return 0;
	float tmp_first = op_first->evaluate(), tmp_second = op_second->evaluate();
	if (error())return 0;
	if (debug) {
		op_first->output();
		op_second->output();
	}
	initialized = true;
	value = tmp_first - tmp_second;
	return value;
}

MULTIPLICATION::MULTIPLICATION(const string& tmpname, Point* C,Point* D){
	name = tmpname; op_first =C; op_second=D;
}

float MULTIPLICATION::evaluate(){
    if (initialized) return value;
	if (error())return 0;
	float tmp_first = op_first->evaluate(), tmp_second = op_second->evaluate();
	if (error())return 0;
	if (debug) {
		op_first->output();
		op_second->output();
	}
	initialized = true;
	value = tmp_first * tmp_second;
	return value;
}

DIVISION::DIVISION(const string& tmpname, Point* C,Point* D){
	name = tmpname; op_first =C; op_second=D;
}

bool DIVISION::division_zero = false;

float DIVISION::evaluate(){
    if (initialized) return value;
	if (error())return 0;
	float tmp_first = op_first->evaluate(), tmp_second = op_second->evaluate();
	if (error())return 0;
	if (debug) {
		op_first->output();
		op_second->output();
	}
	if (fabs(tmp_second) < 1e-6) {
		cout << "ERROR: Division by zero" << endl;
		division_zero = true;
		return 0;
	}
	initialized = true;
	value = tmp_first / tmp_second;
	return value;
}

GREATER_THAN::GREATER_THAN(const string& tmpname, Point* C, Point* D){
	name = tmpname; op_first =C; op_second=D;
}

float GREATER_THAN::evaluate(){
	if(initialized)	return value;
	if (error())return 0;
	float tmp_first = op_first->evaluate(), tmp_second = op_second->evaluate();
	if (error())return 0;
	if (debug) {
		op_first->output();
		op_second->output();
	}
	initialized=true;
	if(tmp_first > tmp_second){
		value = 1.0;
		return value;
	}
	else{
		value=0.0;
		return value;
	}
}

LESS_THAN::LESS_THAN(const string& tmpname, Point* C, Point* D){
	name = tmpname; op_first =C; op_second=D;
}

float LESS_THAN::evaluate(){
	if(initialized)	return value;
	if (error())return 0;
	float tmp_first = op_first->evaluate(), tmp_second = op_second->evaluate();
	if (error())return 0;
	if (debug) {
		op_first->output();
		op_second->output();
	}
	initialized = true;
	if (tmp_first < tmp_second) {
		value = 1.0;
		return value;
	}
	else {
		value = 0.0;
		return value;
	}
}

GREATER_OR_EQUAL::GREATER_OR_EQUAL(const string& tmpname, Point* C, Point* D){
	name = tmpname; op_first =C; op_second=D;
}

float GREATER_OR_EQUAL::evaluate(){
	if(initialized)	return value;
	if (error())return 0;
	float tmp_first = op_first->evaluate(), tmp_second = op_second->evaluate();
	if (error())return 0;
	if (debug) {
		op_first->output();
		op_second->output();
	}
	initialized = true;
	if (tmp_first >= tmp_second) {
		value = 1.0;
		return value;
	}
	else {
		value = 0.0;
		return value;
	}
}

LESS_OR_EQUAL::LESS_OR_EQUAL(const string& tmpname, Point* C, Point* D){
	name = tmpname; op_first =C; op_second=D;
}

float LESS_OR_EQUAL::evaluate(){
	if(initialized)	return value;
	if (error())return 0;
	float tmp_first = op_first->evaluate(), tmp_second = op_second->evaluate();
	if (error())return 0;
	if (debug) {
		op_first->output();
		op_second->output();
	}
	initialized = true;
	if (tmp_first <= tmp_second) {
		value = 1.0;
		return value;
	}
	else {
		value = 0.0;
		return value;
	}
}

EQUAL::EQUAL(const string& tmpname, Point* C, Point* D){
	name = tmpname; op_first =C; op_second=D;
}

float EQUAL::evaluate(){
	if(initialized)	return value;
	if (error())return 0;
	float tmp_first = op_first->evaluate(), tmp_second = op_second->evaluate();
	if (error())return 0;
	if (debug) {
		op_first->output();
		op_second->output();
	}
	initialized = true;
	if (fabs(tmp_first - tmp_second) < 1e-6) {
		value = 1.0;
		return value;
	}
	else {
		value = 0.0;
		return value;
	}
}
