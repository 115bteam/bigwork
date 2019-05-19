#include "ThreePara.h"
#include "calculation.h"

void ThreePara::reset() {
	initialized = false;
	op_first->reset();
	op_second->reset();
	op_third->reset();
}

COND::COND(const string& tmpname, Point* tmpop_first, Point* tmpop_second, Point* tmpop_third) {
	name = tmpname;
	op_first = tmpop_first; op_second = tmpop_second; op_third = tmpop_third;
}

float COND::evaluate() {
	if (initialized)return value;
	if (error())return 0;
	float tmp = (op_first->evaluate() > 0 ? op_second->evaluate() : op_third->evaluate());
	if (error())return 0;
	if (debug) {
		op_first->output();
		op_second->output();
		op_third->output();
	}
	initialized = true;
	value = tmp;
	return value;
}
