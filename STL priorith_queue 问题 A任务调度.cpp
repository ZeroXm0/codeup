#include <cstdio>
#include <string> 
#include <queue>
#include <map>
#include <iostream>
using namespace std;
struct Task {
	string name;
	int level;
	friend bool operator < (const Task &f1, const Task &f2) {
		if(f1.level != f2.level) return f1.level > f2.level;
		else return f1.name > f2.name;
	}
}; 
void deal(string s, priority_queue<Task> &ans, map<string, int> &list) {			//map记录level 
	Task t;
	string str;
	int i = 0;
	while(s.size() > 0 && s[i] != '(') {		//每行第一个 
		str += s[i];
		i++;
	}
	if(list[str] == 0){		//不存在 ,为第一个? 
		t.name = str;
		t.level = 0;
		list[str] = 0;
		ans.push(t);
	}
	s.erase(s.begin(), s.begin() + i + 1);
	int temp = list[str] + 1;
	str = "";
	i = 0;
	while(i < s.size()) {
		if((s[i] == ')' || s[i] == ',') && list[str] == 0 && str != "NULL") {
			t.name = str;
			t.level = temp;
			list[str] = temp;
			ans.push(t);
			str = "";
		} else {
			str += s[i];
		}
		i++;
	}
}
int main() {
	priority_queue<Task> ans;
	map<string, int> list;
	int n;
	while(scanf("%d", &n) != EOF) {	
		getchar();
		string str;
		while(n--) {
			getline(cin,str);
			deal(str, ans, list);
		}
		while(ans.empty() != true) {
			cout << ans.top().name;
			if(ans.size() > 1) cout << " ";
			else cout << endl;
			ans.pop();
		}
	}
	return 0;
}
