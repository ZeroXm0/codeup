#include <cstdio>
#include <algorithm>
using namespace std;
int ans[92][9], p[9];//记录结果和第i行皇后放置的列
int n; 
bool hashTable[9] = {false};//第i列是否已经放置 ,注意不要用hash在一些oj会与系统冲突 
int num = 1;
void generate(int index) {
	if(index == 9) {
		for(int i = 1; i < 9; i++){
			ans[num][i] = p[i];  
		}
		num++;
		return;
	} 
	for(int i = 1; i <= 8; i++) {//第1~i行的列 
		if(hashTable[i] == false) {
			bool flag = true; //不与之前的皇后冲突
			for(int pre = 1; pre < index; pre++) {
				if(abs(index - pre) == abs(i - p[pre])) {
					flag = false;
					break;
				}
			} 
			if(flag) {
				p[index] = i;
				hashTable[i] = true;//第i行已被占用
				generate(index + 1);
				hashTable[i] = false;//处理完一个，重置 
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	generate(1);
	int k;
	for(int i = 0; i < n; i++) {
		scanf("%d",&k);
		for(int j = 1; j <= 8;j++) printf("%d", ans[k][j]);
		printf("\n");
	}
	return 0;
}
