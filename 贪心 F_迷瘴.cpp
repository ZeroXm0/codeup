#include <cstdio>
#include <algorithm>
using namespace std;
struct Tab {
	int v;
	double w;
	double p[110];
}temp[110];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int k;
		scanf("%d%d%lf",&k, &temp[i].v, &temp[i].w);
		for(int j = 0; j < k; j++) {
			scanf("%lf", &temp[i].p[j]);
		}
		sort(temp[i].p, temp[i].p + k);
		double nong = 0;
		int v = 0;
		for(int j = 0; j < k; j++) {
			double x = (nong * v + temp[i].p[j] * temp[i].v) / (v + temp[i].v);
			if(x <= temp[i].w) {
				nong = x;
				v += temp[i].v;
			} else {
				break;
			}
		}
		printf("%d %.2f\n", v, nong / 100);//算出是百分比要除去100 
	}
	return 0;
}
