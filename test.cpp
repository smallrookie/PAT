#include <iostream>
#include <queue>

using namespace std;

struct Node {
    Node *lchild;
    Node *rchild;
    int val;

    Node(int val) : val(val), lchild(NULL), rchild(NULL) {}
};

queue<Node*> q;

Node *createTree(Node *root, int rt, int a, int b) {

    if (root->val == -1)
        root->val = rt;

    if (a != 0) {
        Node *node = new Node(a);
        root->lchild = node;
        q.push(node);
    }

    if (b != 0) {
        Node *node = new Node(a);
        root->rchild = node;
        q.push(node);
    }

    if (!q.empty()) {
        Node *node = q.front();
        q.pop();
        return node;
    }

    return NULL;

}

void preOrder(Node *root) {

    if (root != NULL) {
        cout << root->val << " ";
        preOrder(root->lchild);
        preOrder(root->rchild);
    }

}

int main() {

    int n;
    while (cin >> n) {

        Node *root = new Node(-1);
        for (int i = 0; i < n; ++i) {

            int rt, a, b;
            cin >> rt >> a >> b;

            Node *node = root;
            createTree(node, rt, a, b);
        }

        preOrder(root);
        cout << endl;

    }

    return 0;
}
