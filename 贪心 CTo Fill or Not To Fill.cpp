#include <cstdio>
#include <algorithm>
using namespace std;
struct station {
	double price, dis;
}sta[510];
double  cmax, d, davg;
int n;
bool cmp (station a, station b) {
	return a.dis < b.dis;
}

int main() {
	scanf("%lf %lf %lf %d", &cmax, &d, &davg,&n);
	for(int i = 0; i < n; i++) {
		scanf("%lf %lf", &sta[i].price, &sta[i].dis);
	}
	sta[n].price = 0;
	sta[n].dis = d;//�յ� 
	sort(sta, sta + n,cmp);
	if(sta[0].dis != 0) printf("The maximum travel distance = 0.00\n");
	else {
		int now = 0;//��ǰ���ڼ���վ
		double cost = 0, nowtank = 0, max = cmax * davg;
		while(now < n) {
			int k = -1;	//����ͼ۵ļ���վ���
			double minprice = 1000000000;
			for(int i = now + 1; i <= n && sta[i].dis - sta[now].dis <= max; i++){//����һ��վ�㿪ʼ�ң�������վ��۸�͵�վ������ܵ����ʣ����м۸���͵ĵ� 
				if(sta[i].price < minprice) {
					minprice = sta[i].price;//�Ѿ��ҹ�������˵�վ�� 
					k = i;
					if(minprice < sta[now].price) break;//�ҵ���һ���ȵ�ǰվ����˵�վ�� 
				} 
			} 
			if(k == -1) break;//����״̬���Ҳ�������վ 
			double need = (sta[k].dis - sta[now].dis) / davg;//�ڵ�ǰվ����͵��㹻����k��վ�������
			if(minprice < sta[now].price) {//k �ļ۸���ڵ�ǰ����ֻ����͵��㹻��k�Ϳ����� 
				if(nowtank < need) {
					cost += (need - nowtank) * sta[now].price;
					nowtank = 0; //����k������Ϊ0 
				}else {
					nowtank -= need;
				} 
			} else {//k���ͼ۸��ڵ�ǰ 
				cost += (cmax - nowtank) * sta[now].price;
				nowtank = cmax - need;
			}
			now = k;
		}
		if(now == n) {
			printf("%.2f\n", cost);
		} else {
			printf("The maximum travel distance = %.2f\n", sta[now].dis + max);
		}
	}
	return 0;
}
