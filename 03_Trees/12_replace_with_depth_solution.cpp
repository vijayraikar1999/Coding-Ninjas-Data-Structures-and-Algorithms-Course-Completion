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

void replaceWithDepthValue(TreeNode<int>* root) {
    queue<TreeNode<int>*> q;
    root -> data = 0;
    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* current = q.front();
        q.pop();
        int n = (current -> children).size();
        for (int i = 0; i < n; i++) {
            (current -> children)[i] -> data = current -> data + 1;
            q.push((current -> children)[i]);            
        }
    }
}