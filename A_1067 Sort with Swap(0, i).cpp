#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int pos[maxn];

int main() {
	int n, num,ans = 0;//num ����Լ�����λ�� 
	scanf("%d", &n);
	int left = n - 1;//��ʾ��������λ���ϵ����ָ�������0�⣩ 
	for(int i = 0; i < n; i++) {
		scanf("%d", &num);
		pos[num] = i;
		if(num == i && num != 0) left--;
	}
	int k = 1;//��0�ⲻ������λ���ϵ���С���� 
	while(left > 0) {
		if(pos[0] == 0){//���0��0λ�ϣ���һ����������λ���ϵ������� 
			while(k < n) {
				if(pos[k] != k){
					swap(pos[0], pos[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		while(pos[0] != 0) {//0����0λ�ϣ�����������λ�ӵ����ֽ��� 
			swap(pos[0], pos[pos[0]]);
			ans++;
			left--;
		}
	}
	printf("%d\n", ans);
	return 0;
}
