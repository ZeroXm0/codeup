#include <cstdio>
#include <algorithm>
using namespace std;
int ans[92][9], p[9];//��¼����͵�i�лʺ���õ���
int n; 
bool hashTable[9] = {false};//��i���Ƿ��Ѿ����� ,ע�ⲻҪ��hash��һЩoj����ϵͳ��ͻ 
int num = 1;
void generate(int index) {
	if(index == 9) {
		for(int i = 1; i < 9; i++){
			ans[num][i] = p[i];  
		}
		num++;
		return;
	} 
	for(int i = 1; i <= 8; i++) {//��1~i�е��� 
		if(hashTable[i] == false) {
			bool flag = true; //����֮ǰ�Ļʺ��ͻ
			for(int pre = 1; pre < index; pre++) {
				if(abs(index - pre) == abs(i - p[pre])) {
					flag = false;
					break;
				}
			} 
			if(flag) {
				p[index] = i;
				hashTable[i] = true;//��i���ѱ�ռ��
				generate(index + 1);
				hashTable[i] = false;//������һ�������� 
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
