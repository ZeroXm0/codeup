#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn];

int main() {
	int n, num,ans = 0;//num ���0����λ�� 
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &pos[i]);
		if(pos[i] == 0) num = i;
	}
	int k = 0;//��¼δ��Ϊ����С�� 
	while(k < n){
		if(num != 0){
			int m;//��¼i��λ�� 
			for(int i = 0; i < n; i++) {
				if(pos[i] = num) m = i;
			}
			swap(pos[num], pos[m]);
			num = m;
		} else {
			for(int i = 0; i < n; i++) {
				if(pos[i] != 0 && pos[i] != i) k = i;
			}
			swap(pos[num], pos[k]);
			num = k;
		}
		ans++;
	} 
	printf("%d\n", ans);
	return 0;
	
}
