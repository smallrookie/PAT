/*
* 题目描述：给定一颗二叉树的前序遍历和中序遍历，求其后序遍历。
*
* 输入：两个字符串，其长度n均小于等于26。
*       第一行为前序遍历，第二行为中序遍历。二叉树中的结点名称以大写字母表示。
*
* 输出：输入样例可能有多组，对于每组测试样例，输出一行，为后序遍历的字符串。
*
**/


#include <iostream>
#include <string>

using namespace std;

struct Node {

    Node *left;
    Node *right;
    char val;

    Node(int val) : val(val), left(NULL), right(NULL) {}
};

void createTree(Node *&root, string preOrder, string inOrder, int preBegin, int inBegin, int inEnd) {

    root = new Node(preOrder[preBegin]);

    int index = 0;
    for (int i = inBegin; i <= inEnd; ++i) {
        if (inOrder[i] == root->val) {
            index = i;
            break;
        }
    }

    if (index != inBegin)
        createTree(root->left, preOrder, inOrder, preBegin + 1, inBegin, index - 1);
    if (index != inEnd)
        createTree(root->right, preOrder, inOrder, preBegin + 1 + (index - inBegin), index + 1, inEnd);
}

void postOrder(Node *root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->val;
    }
    return;
}

int main() {

    string preOrder, inOrder;
    while (cin >> preOrder >> inOrder) {
        Node *root = NULL;
        createTree(root, preOrder, inOrder, 0, 0, preOrder.length() - 1);
        postOrder(root);
        cout << endl;
    }

    return 0;
}
