#include <bits/stdc++.h>
using namespace std;

typedef char Elemtype;

struct TreeNode
{
    Elemtype data;
    TreeNode *left;
    TreeNode *right;
};

typedef TreeNode *BiTree;

string s = "ABDH#K###E##CFI###G#J##";

void createTree(BiTree &root, int &index)
{
    Elemtype ch = s[index++];
    if (ch == '#')
    {
        root = nullptr;
        return;
    }
    else
    {
        root = new TreeNode;
        root->data = ch;
        createTree(root->left, index);
        createTree(root->right, index);
    }
}
void preOrder(const BiTree &root)
{
    if (!root)
        return;
    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(const BiTree &root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
}
void postOrder(const BiTree &root)
{
    if (!root)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
}
int main()
{
    BiTree tree;
    int index = 0;
    createTree(tree, index);

    preOrder(tree);
    cout << endl;

    inOrder(tree);
    cout << endl;

    postOrder(tree);
    cout << endl;
    return 0;
}