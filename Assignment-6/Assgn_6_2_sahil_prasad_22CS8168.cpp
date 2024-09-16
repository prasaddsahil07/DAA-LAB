/*
%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  Name: Sahil Prasad     %
%  Roll: 22CS8168   	  %
%  Question: BST (q no: 2)%
%%%%%%%%%%%%%%%%%%%%%%%%%%%
*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	int height;
	
	TreeNode(int v): val(v), left(nullptr), right(nullptr), height(0){}
};

TreeNode* insert(TreeNode* root, int k){
	if(!root){
		return new TreeNode(k);
	}
	else if(root->val > k){
		root->left = insert(root->left, k);
	}
	else if(root->val < k){
		root->right = insert(root->right, k);
	}
	return root;
}

void preOrder(TreeNode* root){
	if(!root)	return;
	cout<<root->val<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(TreeNode* root){
	if(!root)	return;
	inOrder(root->left);
	cout<<root->val<<" ";
	inOrder(root->right);
}

void print_tree(TreeNode* root){
	cout<<"The Preorder traversal of the Tree is:"<<endl;
	preOrder(root);
	cout<<endl;
	cout<<"The Inorder traversal of the Tree is:"<<endl;
	inOrder(root);
	cout<<endl;
}

int getHeight(TreeNode* root){
	if(!root)	return -1;
	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);
	root->height = 1+max(leftHeight, rightHeight);
	return root->height;
}

void print_hrange(TreeNode* root, int k, int l){
	if(!root)	return;
	print_hrange(root->left, k, l);
	if(root->height >= k && root->height <= l){
		cout<<"("<<root->val<<", "<<root->height<<")"<<endl;
	}
	print_hrange(root->right, k, l);
}

int main(){
	TreeNode* root = nullptr;
	int n;
	cout<<"Enter the number of keys in tree: ";
	cin>>n;
	cout<<"Enter the tree nodes:"<<endl;
	for(int i=0; i<n; i++){
		int v;
		cout<<"Enter the node value: ";
		cin>>v;
		root = insert(root, v);  
	}
	cout<<"Printing the entire tree:"<<endl;
	print_tree(root);
	cout<<"The maximum height of the tree is: ";
	cout<<getHeight(root)<<endl;
	cout<<"Enter the range parameter k: ";
	int k;
	cin>>k;
	cout<<"Enter the range parameter l: ";
	int l;
	cin>>l;
	cout<<"Height for nodes in the given range is:"<<endl;
	print_hrange(root, k, l);
}

