
#include <stdio.h>
#pragma warning(disable:4996)

int number;
int num;
int cnt;
int a, b, c, d;

int cycle(int q);

int main(void) {
	scanf("%d", &number);
	num = number;

	cycle(number);
	printf("%d", cnt);
	return 0;
}
int cycle(int q) {
	cnt++;
	a = q / 10; // a = 2
	b = q % 10; // b = 6
	c = (a + b) % 10; // c = 8
	d = (b * 10) + c;

	if (d != num) {
		cycle(d);
	}
	else if (d == num) {
		return cnt;
	}
}
