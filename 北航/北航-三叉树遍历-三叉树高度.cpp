/*
*
* 题目描述：按要求输入倒立三叉树，求层次最高且分叉最多的节点的编号和其在后序遍历中的次序。
*
**/

#include <iostream>
#include <algorithm>

using namespace std;

struct Tree {
    Tree *lchild;
    Tree *mchild;
    Tree *rchild;

    int id;        // 编号
    int order;     // 后序遍历次序
    int height;    // 结点层次

    Tree(int id) : id(id), lchild(NULL), mchild(NULL), rchild(NULL) {}
} *t[500];

struct mrr {
    int id;
    int order;
    int height;
} ans[500];

// 收集结点id
int oneChild[500];
int twoChild[500];
int threeChild[500];

// 最大分支数统计
int oneNum = 0;
int twoNum = 0;
int threeNum = 0;

int order = 1;
int index = 0;

bool cmp(mrr a, mrr b) {
    return a.height > b.height;
}

void getDepth(Tree *node, int id, int height) {
    if (node == NULL) {
        return;
    }

    if (node->id == id) {
        ans[index].id = node->id;
        ans[index].order = node->order;
        ans[index].height = height;
        index++;
        return;
    }

    getDepth(node->lchild, id, height + 1);
    getDepth(node->mchild, id, height + 1);
    getDepth(node->rchild, id, height + 1);
}

void postOrder(Tree *root) {
    if (root != NULL) {
        postOrder(root->lchild);
        postOrder(root->mchild);
        postOrder(root->rchild);
        root->order = order++;
    }
}

Tree* add(int id) {
    t[id] = new Tree(id);
    return t[id];
}

Tree* createTree(int n) {
    Tree *root;
    int a, b, c, d;
    bool flag = true;

    while (n--) {
        cin >> a >> b >> c >> d;
        if (b && c && d) {
            threeChild[threeNum++] = a;
        }
        else if ((b && c) || (b && d) || (c && d)) {
            twoChild[twoNum++] = a;
        }
        else {
            oneChild[oneNum++] = a;
        }

        if (flag) {
            t[a] = new Tree(a);
            if (b != 0) {
                t[a]->lchild = add(b);
            }
            if (c != 0) {
                t[a]->mchild = add(c);
            }
            if (d != 0) {
                t[a]->rchild = add(d);
            }

            root = t[a];
            flag = false;
        }
        else {
            if (b != 0) {
                t[a]->lchild = add(b);
            }
            if (c != 0) {
                t[a]->mchild = add(c);
            }
            if (d != 0) {
                t[a]->rchild = add(d);
            }
        }
    }
    return root;
}

int main() {

    int n;
    while (cin >> n) {

        Tree *root = createTree(n);

        postOrder(root);

        if (threeNum > 0) {
            for (int i = 0; i < threeNum; ++i) {
                getDepth(root, threeChild[i], 1);
            }
            sort(ans, ans + index, cmp);
            cout << ans[0].id << " " << ans[0].order << endl;
        }
        else if (twoNum > 0) {
            for (int i = 0; i < threeNum; ++i) {
                getDepth(root, twoChild[i], 1);
            }
            sort(ans, ans + index, cmp);
            cout << ans[0].id << " " << ans[0].order << endl;
        }
        else {
            for (int i = 0; i < oneNum; ++i) {
                getDepth(root, oneChild[i], 1);
            }
            sort(ans, ans + index, cmp);
            cout << ans[0].id << " " << ans[0].order << endl;
        }
    }
    return 0;
}
