#include <iostream>
#include <queue>

using namespace std;

struct Node {

    Node *left;
    Node *right;

    int val;

    Node(int val) : val(val), left(NULL), right(NULL) {}
};

Node *add(Node *node, int x) {

    if (node == NULL) {
        node = new Node(x);
        return node;
    }

    else if (x < node->val)
        node->left = add(node->left, x);
    else if (x > node->val)
        node->right = add(node->right, x);

    return node;
}

void levelOrder(Node *root) {

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {

        Node *cur = q.front();
        q.pop();
        cout << cur->val << " ";

        if (cur->left != NULL)
            q.push(cur->left);
        if (cur->right != NULL)
            q.push(cur->right);
    }
}

int maxDepth(Node *root, int n) {

    if (root == NULL)
        return n;

    int leftNum = maxDepth(root->left, n + 1);
    int rightNum = maxDepth(root->right, n + 1);

    return leftNum > rightNum ? leftNum : rightNum;
}

Node *lowestAncestor(Node *root, Node *o1, Node *o2) {

    if (root == NULL || root == o1 || root == o2)
        return root;

    Node *left = lowestAncestor(root->left, o1, o2);
    Node *right = lowestAncestor(root->right, o1, o2);

    if (left != NULL && right != NULL)
        return root;

    return left != NULL ? left : right;
}

Node *findNode(Node *node, int x) {

    if (node == NULL)
        return NULL;

    if (x == node->val)
        return node;
    else if (x < node->val)
        return findNode(node->left, x);
    else
        return findNode(node->right, x);
}


int main() {

    int n;
    Node *root = NULL;
    while (cin >> n) {

        for (int i = 0; i < n; ++i) {

            int x;
            cin >> x;
            root = add(root, x);
        }

        levelOrder(root);
        cout << endl;

        int depth = maxDepth(root, 0);
        cout << depth << endl;

        Node *o1 = findNode(root, 5);
        Node *o2 = findNode(root, 8);
        cout << "findNode: " << o1->val << " " << o2->val << endl;

        Node *ancestor = lowestAncestor(root, o1, o2);
        cout << "lowestAncestor: " << ancestor->val << endl;
    }

    return 0;
}
