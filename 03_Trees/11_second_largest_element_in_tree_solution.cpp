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

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if (root == nullptr) {
        return root;
    }
    TreeNode<int>* largest_node = root;
    TreeNode<int>* ans_node = root;
    queue<TreeNode<int>*> q;

    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* current = q.front();
        q.pop();
        if (current -> data > largest_node -> data) {
            largest_node = current;
        }
        int n = (current -> children).size();
        for (int i = 0; i < n; i++) {
            q.push((current -> children)[i]);            
        }
    }
    q.push(root);
    int second_largest = -1000000007;
    TreeNode<int>* second_largest_node = nullptr;
    while (!q.empty()) {
        TreeNode<int>* current = q.front();
        q.pop();
        if (current -> data > second_largest && current -> data < largest_node -> data) {
            second_largest_node = current;
            second_largest = current -> data;
        }
        int n = (current -> children).size();
        for (int i = 0; i < n; i++) {
            q.push((current -> children)[i]);            
        }
    }


    return second_largest_node;
}