#include "calculation.h"
#include <iostream>
#include <functional>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using std::cin; using std::string; using std::cout; using std::map; using std::endl; using std::fixed; using std::setprecision;

map<string, Point*> chart;//保存当前所有节点 
float *memory;//保存操作的结果 

void bulid_variate() {//构建变量节点 
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name; char property; float value;//
		cin >> name >> property;
		if (property == 'P')chart[name] = new Placeholder(name);
		else if (property == 'C') {
			cin >> value;
			chart[name] = new Constant(name, value);
		}
		else if (property == 'V') {
			cin >> value;
			chart[name] = new Variable(name, value);
		}
	}
}

//这里是运算符前置函数的名字和对应的构造函数 
const int prepositive_func_num = 7;
string prepositive_func_name[prepositive_func_num] =
{ "SIN", "LOG", "EXP", "TANH", "SIGMOID", "PRINT", "COND" };
function<Point*(const string&)> prepositive_func_construct[prepositive_func_num] = {
[](const string& name) {string op; cin >> op; return new SIN(name, chart[op]); },
[](const string& name) {string op; cin >> op; return new LOG(name, chart[op]); },
[](const string& name) {string op; cin >> op; return new EXP(name, chart[op]); },
[](const string& name) {string op; cin >> op; return new TANH(name, chart[op]); },
[](const string& name) {string op; cin >> op; return new SIGMOID(name, chart[op]); },
[](const string& name) {string op; cin >> op; return new PRINT(name, chart[op]); },
[](const string& name) {string op[3]; for (int i : {0,1,2})cin >> op[i]; return new COND(name, chart[op[0]], chart[op[1]], chart[op[2]]); } };

//这里是运算符中置函数的名字和对应的构造函数 
const int mid_func_num = 9;
string mid_func_name[mid_func_num] =
{ "+", "-", "*", "/", "<", ">", "<=", ">=", "==" };
function<Point*(const string&, const string&, const string&)>mid_func_construct[mid_func_num] = {
[](const string& name, const string& op_first, const string& op_second) {return new ADD(name, chart[op_first], chart[op_second]); },
[](const string& name, const string& op_first, const string& op_second) {return new SUBTRACTION(name, chart[op_first], chart[op_second]); },
[](const string& name, const string& op_first, const string& op_second) {return new MULTIPLICATION(name, chart[op_first], chart[op_second]); },
[](const string& name, const string& op_first, const string& op_second) {return new DIVISION(name, chart[op_first], chart[op_second]); },
[](const string& name, const string& op_first, const string& op_second) {return new LESS_THAN(name, chart[op_first], chart[op_second]); },
[](const string& name, const string& op_first, const string& op_second) {return new GREATER_THAN(name, chart[op_first], chart[op_second]); },
[](const string& name, const string& op_first, const string& op_second) {return new LESS_OR_EQUAL(name, chart[op_first], chart[op_second]); },
[](const string& name, const string& op_first, const string& op_second) {return new GREATER_OR_EQUAL(name, chart[op_first], chart[op_second]); },
[](const string& name, const string& op_first, const string& op_second) {return new EQUAL(name, chart[op_first], chart[op_second]); }, };

//判断name是否为前置函数名 
bool is_prepositive_func(const string& name) {
	for (string tmp : prepositive_func_name)
		if (tmp == name)return true;
	return false;
}

//判断name是否为中置函数名 
bool is_mid_func(const string& name) {
	for (string tmp : mid_func_name)
		if (tmp == name)return true;
	return false;
}

//构造运算符节点（前置运算符） 
Point* construct_node(const string& name, const string& tmp) {
	for (int i = 0; i < prepositive_func_num; i++) {
		if (tmp == prepositive_func_name[i])return prepositive_func_construct[i](name);
	}
	cout << "node construct error: prepositive_func_construct" << endl;
	return NULL;
}

//构造运算符节点（中置运算符）
Point* construct_node(const string& name, const string& op_first, const string& tmp, const string& op_second) { 
	for (int i = 0; i < mid_func_num; i++) {
		if (tmp == mid_func_name[i])return mid_func_construct[i](name, op_first, op_second);
	}
	cout << "node construct error: mid_func_construct" << endl;
	return NULL;
}

//读入并构造运算符节点 
void bulid_node() {
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string name, tmp;
		cin >> name >> tmp;
		if (tmp == "=")cin >> tmp;
		else { cout << "node construct error: wrong sentence!!!" << endl; return; }
		if (is_prepositive_func(tmp))chart[name] = construct_node(name, tmp);
		else if (chart.count(tmp)) {
			string op_name, another_tmp;
			cin >> op_name >> another_tmp;
			if (!is_mid_func(op_name)) {
				cout << "node construct error: operator not found!!!" << endl;
				return;
			}
			if (chart.count(another_tmp)) {
				chart[name] = construct_node(name, tmp, op_name, another_tmp);
			}
			else cout << "node construct error: another_name not found!!!" << endl;
		}
		else cout << name << " " << "node construct error: name not found!!!" << endl;
	}
}

//每次eval前重置保存的赋值语句,清空错误信息,并将所有节点设定为未初始化
void reset(const string& name) {
	valuerecord.clear();
	reset_error();
	chart[name]->reset();
}

//eval操作 
float eval() {
	string wait_to_eval; int input_num = 0;
	char tmpc;
	cin >> wait_to_eval;
	while (cin.peek() == ' ')tmpc = cin.get();
	if (isdigit(cin.peek()))cin >> input_num;
	if (!chart.count(wait_to_eval)) {
		cout << wait_to_eval << " " << "eval error: name not found!!!" << endl;
		return 0;
	}
	reset(wait_to_eval);
	for (int i = 0; i < input_num; i++) {
		string name; float value;
		cin >> name >> value;
		valuerecord[name] = value;
	}
	float result = chart[wait_to_eval]->evaluate();
	if(!error())cout << setprecision(4) << fixed << result << endl;
	return result;
}

//setconstant操作 
void setconstant() {
	string name; float value;
	cin >> name >> value;
	if (!chart.count(name)) {
		cout << "setconstant error: name not found!!!" << endl;
		return;
	}
	chart[name]->setvalue(value);
}

//setanswer操作 
void setanswer() {
	string name; int no;
	cin >> name >> no;
	if (!chart.count(name)) {
		cout << "setanswer error: name not found!!!" << endl;
		return;
	}
	chart[name]->setvalue(memory[no - 1]);
}

//操作 
void operate() {
	int q; string op_name;
	cin >> q;
	memory = new float[q];
	for (int i = 0; i < q; i++) {
		cin >> op_name;
		if (op_name == "EVAL")memory[i] = eval();
		else if (op_name == "SETCONSTANT")setconstant();
		else if (op_name == "SETANSWER")setanswer();
		else cout << "operator not found!!!" << endl;
	}
}

void getbackmemory() {

}

int main() {
	bulid_variate();
	bulid_node();
	operate();
	//getbackmemory();
}


