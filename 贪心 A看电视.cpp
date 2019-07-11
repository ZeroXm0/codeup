#include <cstdio>
#include <algorithm>
using namespace std;
struct TV {
	int si,ei;
}tv[110];
bool cmp(TV a,TV b) {
	if(a.ei != b.ei) return a.ei > b.ei;
	else return a.si < b.si;
}

int main() {
	int n = -1;
	while(n != 0) {
		scanf("%d", &n);
		if(n == 0) break;
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &tv[i].si, &tv[i].ei);
		}
		sort(tv + 1, tv + 1 + n, cmp);
		int count = 1, lastsi = tv[1].si; 
		for(int i = 1; i <= n; i++) {
			if(tv[i].ei <= lastsi) {
				lastsi = tv[i].si;
				count++;
			}
		} 
		printf("%d\n",count);
	}
	
	return 0;
}
