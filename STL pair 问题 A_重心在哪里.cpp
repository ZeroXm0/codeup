#include <cstdio>
#include <map>
using namespace std;
int main() {
	int n;
	while(scanf("%d", &n), n != 0) {
		for(int i = 0; i < n; i++) {
			pair<double, double> a;
			scanf("%lf %lf", &a.first, &a.second);
			pair<double, double> b;
			scanf("%lf %lf", &b.first, &b.second);
			pair<double, double> c;
			scanf("%lf %lf", &c.first, &c.second);
			double x, y;
			x = (a.first + b.first + c.first) / 3;
			y = (a.second + b.second + c.second) / 3;
			printf("%.1f %.1f\n", x, y);
		}
	}
	return 0;
} 
