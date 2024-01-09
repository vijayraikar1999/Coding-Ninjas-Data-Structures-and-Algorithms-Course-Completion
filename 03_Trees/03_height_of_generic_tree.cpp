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

int getHeight(TreeNode<int>* root) {
    if (root == nullptr) {
        return 0;
    }
    if ((root -> children).size() == 0) {
        return 1;
    }
    int n = (root -> children).size();
    int children_height = 0;
    for (int i = 0; i < n; i++) {
        int ch_height = getHeight((root -> children)[i]);
        if (ch_height > children_height) {
            children_height = ch_height;
        }
    }
    return 1 + children_height;
}