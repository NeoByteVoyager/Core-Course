#include<bits/stdc++.h>
using namespace std;
int a[]={0x0,0x24,
			0x8,0x32,
			0x6,0x16,0x2d,0x6b,
			0x1,0x7,0x14,0x23,0x28,0x2f,0x63,0x3e9};
struct Node{
	int val;
	Node *left;
	Node *right;
	Node(int val):val(val){
		left=right=nullptr;		
	}
};
Node* init(){
	Node *root=new Node(a[1]);
	queue<Node*>q;
	q.push(root);
	int cnt=3,now=1;
	while(cnt--){
		int n=q.size();
		for(int i=0;i<n;i++){
			Node*cur=q.front();
			q.pop();
			cur->left=new Node(a[++now]);
			cur->right=new Node(a[++now]);
			q.push(cur->left);
			q.push(cur->right);
		}
	}
	return root;
}
void preorder(Node*root){
	if(!root) return ;
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}
int fun7(Node* root,int x){
	if(!root) return 0xffffffff;
	if(x==root->val) return 0;
	if(root->val>x) return 2*fun7(root->left,x);
	if(root->val<x) return 2*fun7(root->right,x)+1;
}
int main(){
	Node*root=init();
//	preorder(root);
	cout<<fun7(root,0x7); 
	return 0;
}
