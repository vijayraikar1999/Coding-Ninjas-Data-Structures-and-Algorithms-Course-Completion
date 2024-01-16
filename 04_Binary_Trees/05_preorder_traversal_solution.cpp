/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void preOrderRec(TreeNode<int>* root, vector<int> &v) {
    if (root == nullptr) {
        return;
    }
    v.push_back(root -> data);
    preOrderRec(root -> left, v);
    preOrderRec(root -> right, v);
}



vector<int> preOrder(TreeNode<int> * root){
    vector<int> v;
    preOrderRec(root, v);
    return v;
}