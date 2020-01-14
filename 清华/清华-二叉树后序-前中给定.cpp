/*
* ��Ŀ����������һ�Ŷ�������ǰ����������������������������
*
* ���룺�����ַ������䳤��n��С�ڵ���26��
*       ��һ��Ϊǰ��������ڶ���Ϊ����������������еĽ�������Դ�д��ĸ��ʾ��
*
* ������������������ж��飬����ÿ��������������һ�У�Ϊ����������ַ�����
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
