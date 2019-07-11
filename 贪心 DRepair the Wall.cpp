#include <cstdio>
#include <algorithm>
using namespace std;
int a[610];
bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int l, n;
	while(scanf("%d%d", &l, &n) != EOF){
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n, cmp);
		int count = 0;  
		for(int i = 0; i < n; i++) {
				l -= a[i];
				count++;
				if(l <= 0) break;
		}
		if(l > 0) printf("impossible\n");
		else printf("%d\n", count);
	}
	return 0;
}
