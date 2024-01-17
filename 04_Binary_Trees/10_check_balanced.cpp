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

int height(BinaryTreeNode<int>* root) {
	if (root == nullptr) {
		return 0;
	}
	int left_height = height(root -> left);
	int right_height = height(root -> right);

	return 1 + max(left_height, right_height);
}

bool isBalanced(BinaryTreeNode<int> *root) {
	if (root == nullptr || (root -> left == nullptr && root -> right == nullptr)) {
		return true;
	}
	bool case_1 = isBalanced(root -> left) && isBalanced(root -> right);
	int left_height = height(root -> left);
	int right_height = height(root -> right);

	bool case_2 = false;
	if (abs(left_height - right_height) <= 1) {
		case_2 = true;
	}

	return (case_1 && case_2);
}