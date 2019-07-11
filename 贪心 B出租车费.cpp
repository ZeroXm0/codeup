#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while( scanf("%d", &n), n != 0) {
		if(n <= 4) printf("10\n");
		else if(n % 8 == 0) printf("%d\n", n / 8 * 18);
		else if(n % 8 <= 4) printf("%.1f\n", (double) (n / 8 * 18 + n % 8 * 2.4));
		else printf("%d\n", n / 8 * 18 + 10 + (n % 8 - 4) * 2); 
	}
	return 0;
}
