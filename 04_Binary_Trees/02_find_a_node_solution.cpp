/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if (root == nullptr) {
        return false;
    }
    if (root -> data == x) {
        return true;
    }
    bool left_ans = isNodePresent(root -> left, x);
    bool right_ans = isNodePresent(root -> right, x);
    return left_ans || right_ans;
}