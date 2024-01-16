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

void printLevelWise(BinaryTreeNode<int> *root) {
	if (root == nullptr) {
		return;
	}
	if (root -> left == nullptr && root -> right == nullptr) {
		return;
	}
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	while (!q.empty()) {
		BinaryTreeNode<int>* current = q.front();
		q.pop();
		cout << current -> data << ':';
		if (current -> left != nullptr) {
			q.push(current -> left);
			cout << "L:" << current -> left -> data << ','; 
		} else {
			cout << "L:" << -1 << ',';
		}
		if (current -> right != nullptr) {
			q.push(current -> right);
			cout << "R:" << current -> right -> data << endl;
		} else {
			cout << "R:" << -1<< endl;
		}
	}
}