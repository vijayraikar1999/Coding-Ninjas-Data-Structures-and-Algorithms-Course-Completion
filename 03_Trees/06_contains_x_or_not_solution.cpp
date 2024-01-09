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

bool isPresent(TreeNode<int>* root, int x) {
    if (root == nullptr) {
        return false;
    }
    int n = (root -> children).size();
    bool ans = false;
    if (root -> data == x) {
        ans = true;
        return ans;
    }
    for (int i = 0; i < n; i++) {
        ans = ans || isPresent((root -> children)[i], x);
        if (ans == true) {
            return ans;
        }
    }
    return ans;
}