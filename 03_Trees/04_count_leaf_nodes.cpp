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

int getLeafNodeCount(TreeNode<int>* root) {
    if (root == nullptr) {
        return 0;
    }
    int n = (root -> children).size();
    if (n == 0) {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += getLeafNodeCount((root -> children)[i]);
    }
    return ans;
}