#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int num1;
	int num2;
	int mi;
	int result;
	scanf("%d %d", &num1, &num2);
	for (int i = 1; i <= num1 && i <= num2; i++) {
		if (num1 % i == 0 && num2 % i == 0) {
			mi = i;
		}
	}
	result = (num1 * num2) / mi;
	printf("%d\n", mi);
	printf("%d", result);

	return 0;
}