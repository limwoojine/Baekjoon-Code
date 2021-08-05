#include <stdio.h>
#pragma warning(disable:4996)
 
int main(void) {
	int n, count;
	int plastic_count = 0;
	scanf("%d", &n);
	

	while (1) {
		if (n % 5 == 0) {   // n이 5의 배수라면 plastic_count에 값을 더한다.
			count = n / 5;
			plastic_count += count;
			break;
		}
		n -= 3; // 5의 배수가 아니라면 n의 3을 빼고 plastic_count에 1을 더한다.
		plastic_count++;
	}
	if (n < 0) plastic_count = -1; // 반복문이 끝나고 n이 0보다 작으면 -1 을 반환한다.
	printf("%d", plastic_count);
	return 0;
}