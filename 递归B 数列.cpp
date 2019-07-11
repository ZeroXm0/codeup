#include <cstdio>
int F(int n) {
	if(n == 0) return 0;
	else if(n == 1) return 1;
	else return F(n - 1) + F(n - 2);
} 

int main() {
	int n,m;
	scanf("%d", &m);
	while(m--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			for(int j = 0; j < (n - i) * 2; j++) {
				printf(" ");
			}
			for(int k = 0; k < 2 * i - 1; k++) {
				printf("%d", F(k));
				if(k != 2 * i - 1) printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
