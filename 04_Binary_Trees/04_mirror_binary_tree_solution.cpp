/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if (root == nullptr) {
		return;
	}
	mirrorBinaryTree(root -> left);
	mirrorBinaryTree(root -> right);
	BinaryTreeNode<int>* left = root -> left;
	BinaryTreeNode<int>* right = root -> right;
	root -> left = right;
	root -> right = left;
	return;
}