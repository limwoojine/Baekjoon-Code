#include <stdio.h>
#pragma warning(disable:4996)
 
int main(void) {
	int n, count;
	int plastic_count = 0;
	scanf("%d", &n);
	

	while (1) {
		if (n % 5 == 0) {   // n�� 5�� ������ plastic_count�� ���� ���Ѵ�.
			count = n / 5;
			plastic_count += count;
			break;
		}
		n -= 3; // 5�� ����� �ƴ϶�� n�� 3�� ���� plastic_count�� 1�� ���Ѵ�.
		plastic_count++;
	}
	if (n < 0) plastic_count = -1; // �ݺ����� ������ n�� 0���� ������ -1 �� ��ȯ�Ѵ�.
	printf("%d", plastic_count);
	return 0;
}