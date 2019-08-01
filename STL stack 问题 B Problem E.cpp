#include <cstdio>
#include <stack>
#include <map>
#include <iostream>
#include <string>
using namespace std;
map<char, int> op;
stack<char> l; 
bool check(char c) {
	if(c == '(' || c == '{' || c == '[' || c == ')' || c == '}' || c == ']') return true;
	else return false;
}
bool deal(string str) {
	while(l.empty() == false) l.pop();				//清空栈 
	int i;
	for(i = 0; i < str.length(); i++) {
		if(check(str[i]) == true && op[str[i]] < 0) l.push(str[i]);
		else if(check(str[i]) == true && op[str[i]] > 0) {
			if(l.empty() == false && (op[l.top()] + op[str[i]] == 0)) l.pop();
			else {
				return false;
			} 
		}
	}
	return l.empty();		//注意，完全匹配栈最后为空， 非空说明未匹配
} 
int main() {
	op['('] = -1;
	op['{'] = -2;
	op['['] = -3;
	op[')'] = 1;
	op['}'] = 2;
	op[']'] = 3;
	int n;
	scanf("%d", &n);
	getchar();
	while(n--) {
		string str;
		getline(cin, str);
		if(deal(str) == true) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
