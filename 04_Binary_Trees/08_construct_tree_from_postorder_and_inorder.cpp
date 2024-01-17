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
BinaryTreeNode<int>* build_tree(int* postorder, int post_start, int post_end, int* inorder, int in_start, int in_end) {
	if (post_start > post_end) {
		return nullptr;
	}
	if (post_start == post_end && in_start == in_end) {
		BinaryTreeNode<int>* node = new BinaryTreeNode<int>(postorder[post_start]);
		return node;
	}
	int root_element = postorder[post_end];
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(root_element);

	int inorder_root_index = -1;
	for (int i = in_start; i <= in_end; i++) {
		if (inorder[i] == root_element) {
			inorder_root_index = i;
		}
	}

	int in_left_start = in_start;
	int in_left_end = inorder_root_index - 1;

	int in_right_start = inorder_root_index + 1;
	int in_right_end = in_end;

	int left_subtree_length = inorder_root_index - in_start;

	int post_left_start = post_start;
	int post_left_end = post_start + left_subtree_length - 1;

    int post_right_start = post_start + left_subtree_length;
	int post_right_end = post_end - 1;

	root -> left = build_tree(postorder, post_left_start, post_left_end, inorder, in_left_start, in_left_end);
	root -> right = build_tree(postorder, post_right_start, post_right_end, inorder, in_right_start, in_right_end);
	return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    return build_tree(postorder, 0, postLength - 1, inorder, 0, inLength - 1);
}