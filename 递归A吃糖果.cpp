#include <cstdio>
int F(int n) {
	if(n == 1) return 1;
	else if(n == 2) return 2;
	else return F(n - 1) + F(n - 2);
} 
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("%d\n", F(n));
	}
	
	return 0;
}
