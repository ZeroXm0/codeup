#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 10010;
string str[maxn];
bool cmp(string a, string b) {
	return a + b < b + a;//aƴ����b С�� bƴ����a �Ǿ�a��ǰ 
} 
int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) cin >> str[i];  //�������������ַ�����cin �� cout 
	sort(str, str + n, cmp);
	
	string ans;
	for(int i = 0; i < n; i++) ans += str[i];
	while(ans.size() != 0 && ans[0] == '0') ans.erase(ans.begin());//ȥ��ǰ���� 
	if(ans.size() == 0) printf("0"); //ȥ��ǰ�����Ϊ��
	else cout << ans;
	return 0; 
}
