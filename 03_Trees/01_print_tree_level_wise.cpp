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

void printLevelWise(TreeNode<int>* root) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode<int>*> q;

    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* current = q.front();
        cout << current -> data << ':';
        q.pop();
        int n = (current -> children).size();
        for (int i = 0; i < n; i++) {
            q.push((current -> children)[i]);
            cout << ((current -> children)[i]) -> data;
            if (i < n - 1) {
                cout << ',';
            } 
        }
        cout << endl;
    }
}