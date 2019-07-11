#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn];

int main() {
	int n, num,ans = 0;//num 标记0所在位子 
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &pos[i]);
		if(pos[i] == 0) num = i;
	}
	int k = 0;//记录未归为的最小数 
	while(k < n){
		if(num != 0){
			int m;//记录i的位子 
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
