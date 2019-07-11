#include <cstdio>
int a[25];
int num(int v, int k) {
	if(v == 0) return 1;
	else if (k <= 0) return 0;
	else return num(v - a[k], k - 1) + num(v, k - 1);
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		int res = num(40,n); 
		printf("%d\n", res);
	}
	return 0;
} 
