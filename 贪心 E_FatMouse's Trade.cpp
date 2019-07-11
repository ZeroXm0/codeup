#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Vector{
	double javabean;
	double catfoot;
	double rate;
}vec[1010];

bool cmp(Vector a, Vector b) {
	return a.rate > b.rate;
}

int main() {
	int n, m;
	while(scanf("%d%d", &m, &n), n != -1 && m != -1) {
		double sum = 0;
		for(int i = 0; i < n; i++) {
			scanf("%lf%lf", &vec[i].javabean, &vec[i].catfoot);
			vec[i].rate = vec[i].javabean / vec[i].catfoot;
		}
		sort(vec, vec + n, cmp);
		for(int i = 0; i < n; i++) {
			if(m >= vec[i].catfoot) {
				sum += vec[i].javabean;//已换到的JavaBean 
				m -= vec[i].catfoot;//还能用于交换的猫食 
			} else {//不能整个仓库换，按比例 
				sum += m * vec[i].rate;//还能交换的m占这个仓库里catfood的比例 和 拥有javabean的比例相同 m / catfood  * JavaBean 
				break; 
			} 
		}
		printf("%.3f\n", sum);  
	}
	
	return 0;
}
