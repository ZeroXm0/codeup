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
				sum += vec[i].javabean;//�ѻ�����JavaBean 
				m -= vec[i].catfoot;//�������ڽ�����èʳ 
			} else {//���������ֿ⻻�������� 
				sum += m * vec[i].rate;//���ܽ�����mռ����ֿ���catfood�ı��� �� ӵ��javabean�ı�����ͬ m / catfood  * JavaBean 
				break; 
			} 
		}
		printf("%.3f\n", sum);  
	}
	
	return 0;
}
