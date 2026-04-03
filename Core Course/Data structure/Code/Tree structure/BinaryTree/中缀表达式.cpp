#include <stdio.h>

// 题目给定的二叉树节点定义
typedef struct node {
    char data[10];
    struct node *left, *right;
} BTree;

// 辅助递归函数，depth 记录当前节点所处的层数（根节点为第 1 层）
void BtreeToExpHelper(BTree *root) {
    if (root == NULL) {
        return; 
    }

    // 1. 若为叶子节点（操作数），直接输出，不加括号
    if (root->left == NULL && root->right == NULL) {
        printf("%s", root->data);
        return ;
    } 
    // 2. 若为内部节点（操作符），需要中序遍历并视情况加括号
    else {
        if(root->left) {
        	printf("(");
        	BtreeToExpHelper(root->left);
        	printf(")");
		} 
		printf("%s",root->data);
		if(root->right){
			printf("(");
        	BtreeToExpHelper(root->right);
        	printf(")");
		}
    }
}

// 主调用算法函数
void BtreeToExp(BTree *root) {
    // 从根节点开始遍历，初始深度设为 1
    BtreeToExpHelper(root);
}
