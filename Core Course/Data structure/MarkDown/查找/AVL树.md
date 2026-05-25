## AVL树
### 定义
一棵AVL树是一颗空树，或者具有以下性质的二叉搜索树：
- 左右子树的高度差的绝对值不能超过1
- 且左右子树都是AVL树

**平衡因子**：各节点的左子树的高度-右子树的高度
AVL任何一个节点的平衡因子只能为：`1`,`-1`,`0`

以上性质保证一棵AVL树如果有n个节点，它的**高度**保持在$log(n)$，故**平均搜索长度**也可保持在$O(log(n))$

### 插入
插入逻辑和BST相同，不过要在插入完成回溯时要自底向上平衡树
```c++
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
```
### 删除
删除逻辑也和BST相同，不过这里采用后继替代法可以更方便的进行回溯平衡
```c++
AVLNode *getMin(AVLNode *node)
{
    AVLNode *cur = node;
    while (cur->left)
        cur = cur->left;
    return cur;
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
```
### 平衡
通过计算平衡因子来判断是否平衡，同时根据其形状来做出相应的旋转。

> 如果树已经平衡，要及时更新节点的高度。树不平衡时，会在旋转函数里面更新树的高度
```c++
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
```
### 旋转
旋转完成之后会有两个节点的高度发生该边，要及时更新节点高度
```c++
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
```