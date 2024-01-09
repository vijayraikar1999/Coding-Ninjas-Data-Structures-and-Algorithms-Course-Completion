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

void printPostOrder(TreeNode<int>* root) {
    if (root == nullptr) {
        return;
    }
    int n = (root -> children).size();
    if (n == 0) {
        cout << root -> data << ' ';
        return;
    }
    for (int i = 0; i < n; i++) {
        printPostOrder((root -> children)[i]);
    }
    cout << root -> data << ' ';
}