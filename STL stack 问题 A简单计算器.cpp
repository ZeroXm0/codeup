#include <cstdio>
#include <stack>
#include <queue>
#include <map>
#include <iostream>
#include <string>
using namespace std;
struct node{
	double num;
	char op;
	bool flag;		// true���������� false������ 
};
string str;
queue<node> n;
stack<node> list;
map<char, int> op;	
void change() {
	node temp;
	for(int i = 0; i < str.length();) {
		if(str[i] >= '0' && str[i] <= '9') {
			temp.flag = true;
			temp.num = str[i++] - '0';
			while(i < str.length() && str[i] >= '0' && str[i] <= '9') {
				temp.num = temp.num * 10 + (str[i++] - '0');
			}
			n.push(temp);
		} else {
			temp.flag = false;
			while(list.empty() == false && op[str[i]] <= op[list.top().op]){		 //ֻҪ������С�ڵ��ڲ�����ջ��ջ��Ԫ�����ȼ����ͰѲ�����ջջ��Ԫ�ص�������׺���ʽ�Ķ�����
				n.push(list.top());
				list.pop();
			}
			temp.op = str[i++];
			list.push(temp);
		}
	}
	while(list.empty() == false) {
		n.push(list.top());
		list.pop();
	}
} 
double calcul() {
	double temp1, temp2;
	node cur, temp;
	while(n.empty() == false){
		cur = n.front();
		n.pop();
		if(cur.flag == true) list.push(cur);
		else {
			temp2 = list.top().num;
			list.pop();
			temp1 = list.top().num;
			list.pop();
			temp.flag = true;
			if(cur.op == '+') temp.num = temp1 + temp2;
			else if(cur.op == '-') temp.num = temp1 - temp2;
			else if(cur.op == '*') temp.num = temp1 * temp2;
			else temp.num = temp1 / temp2;				//ע�ⱻ������ǰһλ����һλ 
			list.push(temp);
		}
	}
	return list.top().num;
}
int main(){
	op['+'] = 1;
	op['-'] = 1;
	op['*'] = 2;
	op['/'] = 2;
	while(getline(cin, str), str != "0") {
		for(string::iterator it = str.end(); it != str.begin(); it--) {
			if(*it == ' ') str.erase(it);
		}
		while(list.empty() == false) list.pop();
		change();
		printf("%.2f\n", calcul());
	}
	return 0;
}
 
