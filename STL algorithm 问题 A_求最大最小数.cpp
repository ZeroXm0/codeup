#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, M, m;
	scanf("%d", &n); 
	while(scanf("%d", &n) != EOF) {
		for(int i = 0; i < n; i++){
			int num;
			scanf("%d", &num);
			if(i == 0) M = m = num;
			M = max(num, M);
			m = min(num, m);
		}
		printf("%d %d\n", M, m);
	} 
	return 0;
}
