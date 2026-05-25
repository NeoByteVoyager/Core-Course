#include <bits/stdc++.h>
using namespace std;

template <typename T>
class AVLTree
{
private:
    struct AVLNode
    {
        T val;
        int height;
        AVLNode *left, *right;
        AVLNode(T val) : val(val), height(1), left(nullptr), right(nullptr) {}
    };
    AVLNode *root = nullptr;
    int getHeight(AVLNode *node)
    {
        return node ? node->height : 0;
    }
    void updateHeight(AVLNode *node)
    {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }
    AVLNode *getMin(AVLNode *node)
    {
        AVLNode *cur = node;
        while (cur->left)
            cur = cur->left;
        return cur;
    }
    AVLNode *rotateLeft(AVLNode *node);
    AVLNode *rotateRight(AVLNode *node);
    AVLNode *balance(AVLNode *node); // 核心：判断自旋
    AVLNode *insert(AVLNode *node, T val);
    AVLNode *remove(AVLNode *node, T val);
    // 内部递归打印：使用中序遍历的变种（右 -> 根 -> 左）
    void display(AVLNode *node, int space)
    {
        if (!node)
            return;

        // 每次递归增加缩进距离
        space += 8;

        // 先打印右子树（在屏幕上方）
        display(node->right, space);

        // 打印当前节点（带上它的高度和平衡因子，方便你调试 AVL 的状态！）
        cout << endl;
        for (int i = 8; i < space; i++)
            cout << " ";

        int bf = getHeight(node->left) - getHeight(node->right);
        cout << node->val << "(h:" << node->height << ",bf:" << bf << ")" << "\n";

        // 再打印左子树（在屏幕下方）
        display(node->left, space);
    }

public:
    void insert(T val)
    {
        root = AVLTree<T>::insert(root, val);
    }
    void remove(T val)
    {
        root = AVLTree<T>::remove(root, val);
    }
    // 对外公开的打印接口
    void display()
    {
        cout << "--- 当前 AVL 树结构 (头向左歪90度看) ---" << endl;
        display(root, 0);
        cout << "----------------------------------------" << endl;
    }
};
template <typename T>
typename AVLTree<T>::AVLNode *AVLTree<T>::rotateLeft(AVLNode *node)
{
    AVLNode *new_node = node->right;
    node->right = new_node->left;
    new_node->left = node;
    // 旋转之后要及时修改高度,不然拿到的是旧的高度
    updateHeight(node);
    updateHeight(new_node);
    return new_node;
}
template <typename T>
typename AVLTree<T>::AVLNode *AVLTree<T>::rotateRight(AVLNode *node)
{
    AVLNode *new_node = node->left;
    node->left = new_node->right;
    new_node->right = node;
    // 旋转之后要及时修改高度
    updateHeight(node);
    updateHeight(new_node);
    return new_node;
}
template <typename T>
typename AVLTree<T>::AVLNode *AVLTree<T>::balance(AVLNode *node)
{
    if (!node)
        return nullptr;
    updateHeight(node);
    // 计算平衡因子
    int bf = getHeight(node->left) - getHeight(node->right);
    if (bf > 1)
    { // LL或者LR
        if (getHeight(node->left->left) >= getHeight(node->left->right))
        { // LL型
            return rotateRight(node);
        }
        else
        { // LR型
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }
    else if (bf < -1)
    { // RR或者RL
        if (getHeight(node->right->right) >= getHeight(node->right->left))
        { // RR型
            return rotateLeft(node);
        }
        else
        { // RL型
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }
    else
    { // 平衡的
        return node;
    }
}
// 插入逻辑和BST一样，不过要在回溯时平衡树
template <typename T>
typename AVLTree<T>::AVLNode *AVLTree<T>::insert(AVLNode *node, T val)
{
    if (!node)
        return new AVLNode(val);
    if (val < node->val)
    { // 在左子树插入
        node->left = insert(node->left, val);
    }
    else if (val > node->val)
    { // 在右子树插入
        node->right = insert(node->right, val);
    }
    else
        return node; // 不允许插入重复值
    return balance(node);
}
template <typename T>
typename AVLTree<T>::AVLNode *AVLTree<T>::remove(AVLNode *node, T val)
{
    if (!node)
        return nullptr;
    if (val < node->val)
    {
        node->left = remove(node->left, val);
    }
    else if (val > node->val)
    {
        node->right = remove(node->right, val);
    }
    else // 找到删除节点
    {
        if (!node->left || !node->right) // 叶子节点或者只有一个子树的节点
        {
            AVLNode *temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        }
        else
        { // 如果该节点左右子树都存在
            AVLNode *temp = getMin(node->right);
            node->val = temp->val;
            node->right = remove(node->right, temp->val); // bug:指向删除后的树
        }
    }
    return balance(node);
}

int main()
{
    AVLTree<int> tree;

    // 故意按照递增顺序插入，逼迫它疯狂进行 RR 旋转和 RL 旋转
    vector<int> nums = {10, 20, 30, 40, 50, 25};
    for (int x : nums)
    {
        cout << "\n插入 " << x << " 后的树状态：";
        tree.insert(x);
        tree.display();
    }

    // 测试删除
    cout << "\n删除 30 后的树状态：";
    tree.remove(30);
    tree.display();
    cout << "\n删除 50后的树状态：";
    tree.remove(50);
    tree.display();
    return 0;
}