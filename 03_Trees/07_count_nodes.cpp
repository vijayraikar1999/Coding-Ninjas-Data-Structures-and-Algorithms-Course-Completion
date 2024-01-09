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

int getLargeNodeCount(TreeNode<int>* root, int x) {
    if (root == nullptr) {
        return 0;
    }

    int n = (root -> children).size();
    if (n == 0 && root -> data > x) {
        return 1;
    }
    int ans = 0;
    if (root -> data > x) {
        ans = 1;
    }
    for (int i = 0; i < n; i++) {
        ans = ans + getLargeNodeCount((root -> children)[i], x);
    }
    
    return ans;
}