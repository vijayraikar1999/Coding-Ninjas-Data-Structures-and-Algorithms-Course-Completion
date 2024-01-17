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

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	int max_element = root -> data;
	int min_element = root -> data;
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while (!q.empty()) {
		BinaryTreeNode<int>* current = q.front();
		int current_data = current -> data;
		q.pop();
		if (current_data < min_element) {
			min_element = current_data;
		}
		if (current_data > max_element) {
			max_element = current_data;
		}
		if (current -> left != nullptr) {
			q.push(current -> left);
		}
		if (current -> right != nullptr) {
			q.push(current -> right);
		}
	}
	return make_pair(min_element, max_element);
}