/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if (root == nullptr || (root -> children).size() == 0) {
        return root;
    }
    int n = (root -> children).size();
    TreeNode<int>* max_node = root;
    for (int i = 0; i < n; i++) {
        if ((root -> children)[i] -> data > root -> data) {
            TreeNode<int>* chilldren_max_node = maxDataNode(root -> children[i]);
            if (chilldren_max_node -> data > root -> data) {
                max_node = chilldren_max_node;
            }
        }
    }
    return max_node;
}