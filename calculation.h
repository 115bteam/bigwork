#pragma once
#include "nfunc.h"
#include "OnePara.h"
#include "TwoPara.h"
#include "ThreePara.h"
#include "Point.h"
#include <map>

using std::map;

extern bool debug;

extern map<string, float> valuerecord;

bool error();

void reset_error();