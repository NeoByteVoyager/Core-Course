#include <bits/stdc++.h>
using namespace std;
typedef char Elemtype;
struct TreeNode
{
    Elemtype val;
    TreeNode *left;
    TreeNode *right;
};

typedef TreeNode *BiTree;
string s = "ABDH###E#I##CF##GJ##K##";

// 创建二叉树
void createTree(BiTree &root, int &index)
{
    char c = s[index++];
    if (c == '#')
    {
        root = nullptr;
        return;
    }
    root = new TreeNode;
    root->val = c;
    createTree(root->left, index);
    createTree(root->right, index);
}
// 前序遍历(非递归版本)
void preOrder(BiTree &root)
{
    stack<BiTree> st;
    st.push(root);
    while (!st.empty())
    {
        BiTree node = st.top();
        st.pop();
        cout << node->val << " ";
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }
}

// 中序遍历(非递归版本)
void inOrder(BiTree root)
{
    stack<BiTree> st;
    BiTree node = root;
    while (node || !st.empty())
    {
        while (node)
        {
            st.push(node);
            node = node->left;
        }
        node = st.top();
        st.pop();
        cout << node->val << " ";
        node = node->right;
    }
}

// 后序遍历(最简单的双栈版本)
void postOrder(BiTree root)
{
    stack<BiTree> st1, st2;
    st1.push(root);
    while (!st1.empty())
    {
        BiTree node = st1.top();
        st1.pop();
        st2.push(node);

        if (node->left)
            st1.push(node->left);
        if (node->right)
            st1.push(node->right);
    }
    vector<Elemtype> res;
    while (!st2.empty())
    {
        res.push_back(st2.top()->val);
        st2.pop();
    }
    for (Elemtype i : res)
        cout << i << " ";
}

int main()
{
    BiTree root;
    int index = 0;
    createTree(root, index);
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    return 0;
}