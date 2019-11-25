#include <iostream>
#include <string>

using namespace std;

int i;

struct TreeNode {
	char val;
	struct TreeNode *lchild, *rchild;
	TreeNode(char c) : lchild(NULL), rchild(NULL), val(c) {}
};

TreeNode* createTree(string str) {
	char c = str[i++];
	if (c == '#')
		return NULL;
	TreeNode *root = new TreeNode(c);
	root->lchild = createTree(str);
	root->rchild = createTree(str);
	return root;
}

void InOrder(TreeNode *root) {
	if (root != NULL) {
		InOrder(root->lchild);
		cout << root->val << " ";
		InOrder(root->rchild);
	}
}

int main() {

	string str;
	while (cin >> str) {
		i = 0;
		TreeNode *root = createTree(str);
		InOrder(root);
		cout << endl;
	}
	
	return 0;
}