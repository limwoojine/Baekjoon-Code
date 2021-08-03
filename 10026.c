
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRUE = 1
#define FALSE = 0
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


int n;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int RGB[100][100];
int visit[100][100];

void dfs(int color, int x, int y) {
    visit[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && ny >= 0 && nx < n && ny < n && RGB[nx][ny] == color && !visit[nx][ny]) {
            // nx, ny >= 0, nx, ny < n, 방문하지 않은 곳
            dfs(color, nx, ny);
        }  
    }
}

int RedGreen(int x, int y) {
    visit[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < n && ny < n && (RGB[nx][ny] == 1 || RGB[nx][ny] == 2) && !visit[nx][ny]) {
            RedGreen(nx, ny);
        }
    }
    return 0;
}

void Init_visited() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			visit[i][j] = 0;
		}
	}
}
int main() {
    char c[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", c);
        for (int j = 0; j < n; j++) {
            if (c[j] == 'R')
                RGB[i][j] = 1;
            else if (c[j] == 'G')
                RGB[i][j] = 2;
            else 
                RGB[i][j] = 3;
        }
    }
    int red = 0, green = 0, blue = 0, red_green = 0;

    //빨초파 영역 개수 구하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (RGB[i][j] == 1 && !visit[i][j]) {
                dfs(1, i, j);
                red++;
            }
            if (RGB[i][j] == 2 && !visit[i][j]) {
                dfs(2, i, j);
                green++;
            }
            if (RGB[i][j] == 3 && !visit[i][j]) {
                dfs(3, i, j);
                blue++;
            }
        }
    }

    //방문기록 초기화하고 빨-초 영역 구하기
    Init_visited();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((RGB[i][j] == 1 || RGB[i][j] == 2) && !visit[i][j]) {
                RedGreen(i, j);
                red_green++;
            }
        }
    }

    //결과 
    int result1 = red + green + blue;
    int result2 = red_green + blue;
    printf("%d %d\n", result1, result2);
    return 0;
}
