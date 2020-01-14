/*
* ��Ŀ������һ����������������Ŀ��С��100��ֵ������Ҷ������100��ֵΪ��֧�㣬�����Ĺ�����ˮƽ��������
*
* ���������������n��������n�����ݣ�������n�У�����4��������һ����������ڵ㣬�������ֱ���������ӽڵ㣬-1�����ӽڵ㲻���ڣ������˳���ղ�α����Ĵ���
*       ��������Ҫ��Ѱ��Ҷ�ӽڵ�����·�������·����ָ�������ظ��ıߡ����뷽ʽ����������һ��ֵm������m�У�������m������m��Ҷ�ӽڵ�Ͷ�Ӧ�����ȼ���Ҫ��
*       �����ȼ�������ϴε����λ�õ��ýڵ�����·����ÿ��·�������һ���ڵ�Ҫ�����Ŀ��Ҷ�ӽڵ㣬���Ҫ��ص����ڵ㡣
* ʾ����
        ���룺
              10
              100 101 108 107
              101 1 102 2
              108 103 104 105
              107 17 109 18
              102 3 4 5
              103 7 8 9
              104 10 106 11
              105 15 16 -1
              109 19 20 21
              106 12 13 14
              5
              8 1
              14 3
              16 2
              5 0
              19 4
        �����
              100 101 102 5
              102 101 100 108 103 8
              103 108 105 16
              105 108 104 106 14
              106 104 108 100 107 109 19
              109 107 100
*
**/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

struct Tree {

    struct Tree *lchild;
    struct Tree *mchild;
    struct Tree *rchild;
    struct Tree *parent;

    int val;

    Tree() : lchild(NULL), mchild(NULL), rchild(NULL), parent(NULL) {}
    Tree(int val) : val(val), lchild(NULL), mchild(NULL), rchild(NULL), parent(NULL) {}
};

struct target {

    int target;
    int priority;

    bool operator < (const struct target &t) const {
        return priority < t.priority;
    }
};

queue<Tree*> q;
vector<int> res;

Tree* preOrder(Tree *root, int x) {
    if (root == NULL || root->val == x)
        return root;

    // cout << "preOrder push: " << root->val << endl;
    res.push_back(root->val);

    if (root->lchild != NULL) {
        Tree *node = preOrder(root->lchild, x);
        if (node == NULL || node->val != x) {
            // cout << "preOrder pop: " << res.back() << endl;
            res.pop_back();
        }
        else return node;
    }

    if (root->mchild != NULL) {
        Tree *node = preOrder(root->mchild, x);
        if (node == NULL || node->val != x) {
            // cout << "preOrder pop: " << res.back() << endl;
            res.pop_back();
        }
        else return node;
    }

    if (root->rchild != NULL) {
        Tree *node = preOrder(root->rchild, x);
        if (node == NULL || node->val != x) {
            // cout << "preOrder pop: " << res.back() << endl;
            res.pop_back();
        }
        else return node;
    }
    return NULL;
}

Tree* getNearestRoot(Tree *root, Tree *curNode, Tree *targetNode) {
    if (root == NULL || root == curNode || root == targetNode)
        return root;

    Tree *left = getNearestRoot(root->lchild, curNode, targetNode);
    Tree *middle = getNearestRoot(root->mchild, curNode, targetNode);
    Tree *right = getNearestRoot(root->rchild, curNode, targetNode);

    if (left != NULL && middle != NULL)
        return root;
    if (left != NULL && right != NULL)
        return root;
    if (middle != NULL && right != NULL)
        return root;

    if (left != NULL)
        return left;
    if (middle != NULL)
        return middle;
    if (right != NULL)
        return right;

    return NULL;
}

Tree* searchNode(Tree *root, int x) {
    if (root == NULL || root->val == x)
        return root;

    Tree* node = searchNode(root->lchild, x);
    if (node != NULL)
        return node;

    node = searchNode(root->mchild, x);
    if (node != NULL)
        return node;

    node = searchNode(root->rchild, x);
    if (node != NULL)
        return node;

    return NULL;
}

Tree* createTree(Tree *root, int p, int l, int m, int r) {
    if (root->parent == NULL) {
        root->val = p;
    }

    if (l != -1) {
        Tree *node = new Tree(l);
        root->lchild = node;
        node->parent = root;
        if (node->val >= 100) {
            q.push(node);
        }
    }

    if (m != -1) {
        Tree *node = new Tree(m);
        root->mchild = node;
        node->parent = root;
        if (node->val >= 100) {
            q.push(node);
        }
    }

    if (r != -1) {
        Tree *node = new Tree(r);
        root->rchild = node;
        node->parent = root;
        if (node->val >= 100) {
            q.push(node);
        }
    }

    if (!q.empty()) {
        Tree *node = q.front();
        q.pop();
        return node;
    }
    return NULL;
}

int main() {

    int n, m;
    Tree *root = new Tree();
    while (cin >> n) {

        int rt, a, b, c;
        Tree *node = root;
        for (int i = 0; i < n; ++i) {
            cin >> rt >> a >> b >> c;
            node = createTree(node, rt, a, b, c);
            // cout << node->val << endl;
        }

        cin >> m;
        target t[m];
        for (int i = 0; i < m; ++i) {
            cin >> t[i].target >> t[i].priority;
        }
        sort(t, t + m);

        Tree *curNode = root;
        Tree *targetNode;
        Tree *sameRoot;
        Tree *last = root;
        for (int i = 0; i < m; ++i) {
            res.clear();

            // ����Ŀ����
            targetNode = searchNode(root, t[i].target);
            // cout << "Root: " << root->val << " " << "targetNode: " << targetNode->val << endl;

            // ����curNode��targetNode�乲ͬ�ĸ����
            sameRoot = getNearestRoot(root, curNode, targetNode);
            // cout << "Root: " << root->val << " " << "curNode: " << curNode->val << " " << "sameRoot: " << sameRoot->val << endl;

            // cout << "last: " << last->val << endl;
            while (last != sameRoot) {
                // cout << "last: " << last->val << endl;
                res.push_back(last->val);
                last = last->parent;
            }
            // cout << "after last push, res size: " << res.size() << endl;
            // cout << "last: " << last->val << endl;

            // ���sameRoot��targetNode��·��
            preOrder(sameRoot, t[i].target);
            // cout << "preOrder sameRoot: " << sameRoot->val << endl;

            // cout << "after preOrder, res size: " << res.size() << endl;
            for (int j = 0; j < res.size(); ++j)
                cout << res[j] << " ";
            cout << targetNode->val << " " << endl;

            curNode = targetNode;
            // last���ΪtargetNode�ĸ����
            last = searchNode(root, res.back());
        }

        while (last != NULL) {
            cout << last->val << " ";
            last = last->parent;
        }
        cout << endl;
    }
    return 0;
}
