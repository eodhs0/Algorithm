#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	char left;
	char right;
};

struct node arr[10000];

void preorder(char root) {
	if (root == '.') {
		return;
	}
	
	cout << root;
	preorder(arr[root].left);
	preorder(arr[root].right);
}

void inorder(char root) {
	if (root == '.') {
		return;
	}

	inorder(arr[root].left);
	cout << root;
	inorder(arr[root].right);
}

void postorder(char root) {
	if (root == '.') {
		return;
	}

	postorder(arr[root].left);
	postorder(arr[root].right);
	cout << root;
}

int main() {
	int numOfNode = 0;
	cin >> numOfNode;

	for (int k = 0; k < numOfNode; k++) {
		char root, l, r;
		cin >> root >> l >> r;
		arr[root].left = l;
		arr[root].right = r;
	}

	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
	cout << endl;

}