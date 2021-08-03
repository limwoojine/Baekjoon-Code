
#include <iostream>
using namespace std;


typedef struct Tree {
	char left;
	char right;
}Tree;

char T[27][2];
void preorder(char root) {
	if (root == '.') {
		return;
	}
	else {
		cout << root;
		preorder(T[root - 'A'][0]);
		preorder(T[root - 'A'][1]);
	}
}
void inorder(char root) {
	if (root == '.') {
		return;
	}
	else {
		inorder(T[root - 'A'][0]);
		cout << root;
		inorder(T[root - 'A'][1]);
	}
}
void postorder(char root) {
	if (root == '.') {
		return;
	}
	else {
		postorder(T[root - 'A'][0]);
		postorder(T[root - 'A'][1]);
		cout << root;
	}
}

int main() {
	int n, i;
	char a, b, c;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a >> b >> c;
		T[a - 'A'][0] = b;
		T[a - 'A'][1] = c;
	}

	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
	cout << '\n';

	return 0;
}
