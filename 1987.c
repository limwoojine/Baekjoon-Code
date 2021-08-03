
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

int r, c;
int result = 0;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int Map[20][20];
int visit[26];

void bfs(int x, int y, int count) {

	visit[Map[x][y]] = 1;
	if (count > result) {
		result = count;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < r && ny < c && !visit[Map[nx][ny]]) {
				bfs(nx, ny, count + 1);
				visit[Map[nx][ny]] = 0;
		}
	}
}

int main() {
	char alpha[25];
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		scanf("%s", alpha);
		for (int j = 0; j < c; j++) {
			Map[i][j] = alpha[j] - 'A';
		}
	}
	bfs(0, 0, 1);
	printf("%d", result);

	return 0;
}
