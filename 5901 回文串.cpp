#include  <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 256;
bool judge(char str[]) {
	int len = strlen(str);
	for(int i = 0; i < len / 2; i ++){
		if(str[i] != str[len - i - 1])  return false;
		
	}
	return true; 
}

int main(){
	char str1[maxn];
	cin.getline(str1,maxn);
	bool res = judge(str1);
	if(res) printf("YES\n");
	else printf("NO\n");
	
	return 0; 
}
