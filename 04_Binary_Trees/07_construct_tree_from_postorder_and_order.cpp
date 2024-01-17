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

BinaryTreeNode<int>* build_tree(int* preorder, int start_pre, int end_pre, int* inorder, int start_in, int end_in) {
	if (start_pre > end_pre) {
		return nullptr;
	}
	if (start_pre == end_pre && start_in == end_in) {
		BinaryTreeNode<int>* node = new BinaryTreeNode<int>(preorder[start_pre]);
		return node;
	}

	int root_index_pre = start_pre;
	int root_element = preorder[start_pre];
	
	int root_index_in = -1;

	for (int i = start_in; i <= end_in; i++) {
		if (inorder[i] == root_element) {
			root_index_in = i;
		}
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(root_element);


	int left_start_in = start_in;
	int left_end_in = root_index_in - 1;

	int left_length = left_end_in - start_in + 1;


	int left_start_pre = root_index_pre + 1;
	int left_end_pre = left_start_pre + left_length - 1;

	int right_start_in = root_index_in + 1;
	int right_end_in = end_in;

	int right_start_pre = left_end_pre + 1;
	int right_end_pre = end_pre;

	root -> left = build_tree(preorder, left_start_pre, left_end_pre, inorder, left_start_in, left_end_in);
	root -> right = build_tree(preorder, right_start_pre, right_end_pre, inorder, right_start_in, right_end_in);

	return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
	return build_tree(preorder, 0, preLength - 1, inorder, 0, inLength - 1);
}