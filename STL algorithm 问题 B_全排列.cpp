#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	char a[210];
	while(cin.getline(a, 210)){
		reverse(a, a + strlen(a) );
		printf("%s\n", a);
	}
	return 0;
} 
