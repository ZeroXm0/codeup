#include <cstdio>
#include <algorithm>
using namespace std;
int money[5] = {50, 20, 10, 5, 1} ;
int main() {
	int n, flag;
	while(scanf("%d", &n) != EOF) {
		int hashTable[5] = {0};
		for(int i = 0; i < 5; i++) {
			while(n >= money[i]) {
				n -= money[i];
				hashTable[i]++;
			}
			if(n == 0){
				flag = i;
				break;
			}
		}
		for(int i = 0; i <= flag; i++) {
			if(hashTable[i]) {
				printf("%d*%d", money[i], hashTable[i]);
				if(i != flag) printf("+");
				else printf("\n");
			}
		}
	}
	return 0;
}
