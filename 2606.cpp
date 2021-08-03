
#include <iostream>
using namespace std;

int virus[101][101];
int visit[101];
int virus_count = 0;
int com, net;

void dfs(int start) {
	visit[start] = 1;
	for (int i = 0; i <= com; i++) {
		if (virus[start][i] == 1 && visit[i] == 0) {
			virus_count++;
			dfs(i);
		}
	}
}
int main() {
	int num, num1;
	cin >> com;
	cin >> net;
	for (int i = 0; i < net; i++) {
		cin >> num >> num1;
		virus[num][num1] = virus[num1][num] = 1;
	}
	dfs(1);
	cout << virus_count;

	return 0;
}
