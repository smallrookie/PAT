/*
 * 题目描述：二叉树的前序、中序、后序遍历的定义： 前序遍历：对任一子树，先访问跟，然后遍历其左子树，最后遍历其右子树； 
            中序遍历：对任一子树，先遍历其左子树，然后访问根，最后遍历其右子树； 后序遍历：对任一子树，先遍历其左子树，
            然后遍历其右子树，最后访问根。给定一棵二叉树的前序遍历和中序遍历，求其后序遍历
            （提示：给定前序遍历与中序遍历能够唯一确定后序遍历）。
 *
 * 输入描述：两个字符串，其长度n均小于等于26。
            第一行为前序遍历，第二行为中序遍历。
            二叉树中的结点名称以大写字母表示：A，B，C....最多26个结点。
 *
 * 输出描述：输入样例可能有多组，对于每组测试样例，
            输出一行，为后序遍历的字符串。
 * 
 */

#include <iostream>
#include <string>

using namespace std;

struct Node {
    char val;
    Node* left;
    Node* right;
    Node(char val) : val(val), left(NULL), right(NULL) {}
};

void rebuildTree(Node *&root, string &s_PreOrder, string &s_InOrder, int preBeginIndex, int inBeginIndex, int inEndIndex) {
    root = new Node(s_PreOrder[preBeginIndex]);
    // 获取中序遍历中根结点索引
    int index;
    for (int i = inBeginIndex; i <= inEndIndex; ++i) {
        if (s_InOrder[i] == s_PreOrder[preBeginIndex]) {
            index = i;
            break;
        }
    }
    // 重建左子树
    if (index != inBeginIndex)
        rebuildTree(root->left, s_PreOrder, s_InOrder, preBeginIndex + 1, inBeginIndex, index - 1);
    // 重建右子树
    if (index != inEndIndex)
        rebuildTree(root->right, s_PreOrder, s_InOrder, preBeginIndex + (index - inBeginIndex) + 1, index + 1, inEndIndex);
}

void PostOrder(Node *root) {
    if (root == NULL)
        return;
    
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val;
}

int main() {
    string s_PreOrder, s_InOrder;
    while (cin >> s_PreOrder >> s_InOrder) {
        Node *root = NULL;
        rebuildTree(root, s_PreOrder, s_InOrder, 0, 0, s_PreOrder.length() - 1);
        PostOrder(root);
        cout << endl;
    }
    return 0;
}