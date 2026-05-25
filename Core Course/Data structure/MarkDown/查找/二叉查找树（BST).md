## 二叉查找树
### 定义

**二叉搜索树**要么为空树，要么满足:
所有节点左子树的所有节点的值小于根节点值
所有节点右子树的所有节点的值大于根节点值

### 性质和判定
**中序遍历**结果为有序递增序列

### 二叉树的判定
- **判定一**(中序遍历有序性质)：
```c++
class Solution {
public:
    long long last = LLONG_MIN;
    bool inorder(TreeNode* root) {
        if (!root)
            return true;
        ;
        if (!inorder(root->left))
            return false;
        if (root->val <= last) {
            return false;
        }
        last = root->val;
        return inorder(root->right);
    }
    bool isValidBST(TreeNode* root) { return inorder(root); }
};
```
- **判定二**(根据定义):
通过传递参数限定当前子树的取值范围，判断整棵树是否满足BST的定义
```c++
class Solution {
public:
    bool dfs(TreeNode* root, long long lower, long long upper) {
        if (!root)
            return true;
        if (root->val <= lower || root->val >= upper)
            return false;
        return dfs(root->left, lower, root->val) &&
               dfs(root->right, root->val, upper);
    }
    bool isValidBST(TreeNode* root) { return dfs(root, LLONG_MIN, LLONG_MAX); }
};
```

### 查找
如果根节点值等于查找值，直接返回根节点
如果根节点值小于查找值，直接返回在右子树的查找结果
如果根节点值大于查找值，直接返回在左子树的查找结果

```c++
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)
            return root;
        if (val == root->val)
            return root;
        else if (val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};
```

### 插入
先查找该插入的值在BST的位置：
如果查找到该节点应该在的位置(空节点)，新建节点，让该位置指向该节点
如果插入值小于根节点值，让根节点的左指针指向插入该值后的左子树，并返回根节点
如果插入值大于根节点值，让根节点的右指针指向插入该值后的右子树，并返回根节点
```c++
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        if (val < root->val)
            root->left = insertIntoBST(root->left, val);

        else
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};
```
### 删除
先找到要删除的位置：
- 如果要删除的节点是叶子节点，直接删除，返回空
- 如果要删除的节点只有左子树或者右子树，直接返回不为空的那个子树
- 如果要删除的节点左右子树都存在，找到根节点的前驱，把根节点的值改为前驱节点的值，然后删除前驱节点(前驱节点不可能左右子树都存在，否则就不是它的前驱)


```c++
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {                               // 当前节点是要删除的节点
            if (!root->left && !root->right) // 如果是叶子节点
                root = nullptr;
            else if (!root->left) // 如果左子树为空
                root = root->right;
            else if (!root->right) // 如果右子树为空
                root = root->left;
            else { // 如果左右子树都不是空
                TreeNode* cur = root->left;
                if (!cur->right) { // 如果左子树的根即是前驱
                    root->val = cur->val;
                    root->left = cur->left;
                } else { // 否则,找到前驱的前驱
                    while (cur->right->right) {
                        cur = cur->right;
                    }
                    root->val = cur->right->val;
                    cur->right = cur->right->left;
                }
            }
        }
        return root;
    }
};
```
**更为简单的删除逻辑**:
直接把要删除节点的右子树挂在左子树的最优端节点的右子树上(该右子树为空)
```c++
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (root->val == key) {
            if (!root->right)
                root = root->left;
            else {
                TreeNode* cur = root->right;
                while (cur->left)
                    cur = cur->left;
                cur->left = root->left;
                root = root->right;
            }
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
```