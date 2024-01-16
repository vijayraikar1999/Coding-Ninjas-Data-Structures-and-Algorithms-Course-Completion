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

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    if (root == nullptr) {
        return root;
    }
    int min_num = 100000000;
    int flag = false;
    TreeNode<int>* ans_node = root;
    queue<TreeNode<int>*> q;

    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* current = q.front();
        q.pop();
        int current_num = current -> data;
        if (current_num > x && current_num < min_num) {
            flag = true;
            min_num = current_num;
            ans_node = current;
        }
        int n = (current -> children).size();
        for (int i = 0; i < n; i++) {
            q.push((current -> children)[i]);            
        }
    }

    if (flag == true) {
        return ans_node;
    }
    return nullptr;
}