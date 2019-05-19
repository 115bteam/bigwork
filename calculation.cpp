#include "calculation.h"

//#define DEBUG//这是手动debug开关（当然你可以编译calculation.cpp时添加） 
//debug操作为在计算中输出每一个经过节点的值 
#ifdef DEBUG
bool debug = true;
#else
bool debug = false;
#endif // DEBUG

map<string, float> valuerecord;//用来保存所有赋值操作 

//判断是否出现错误 
bool error() {
	return LOG::negative_input || DIVISION::division_zero || Placeholder::placeholder_missing;
}

//清空错误信息 
void reset_error() {
	LOG::negative_input = false;
	DIVISION::division_zero = false;
	Placeholder::placeholder_missing = false;
}
