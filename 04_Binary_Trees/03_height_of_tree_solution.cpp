/***********************************************************
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

int height(BinaryTreeNode<int>* root) {
    if (root == nullptr) {
		return 0;
	}
	int left_height = height(root -> left);
	int right_height = height(root -> right);
	int max_height = max(left_height, right_height);
	return 1 + max_height;
}