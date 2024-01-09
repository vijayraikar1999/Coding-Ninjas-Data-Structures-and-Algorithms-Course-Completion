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
#include<queue>
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    if (root == nullptr) {
        return nullptr;
    }
    int n = (root -> children).size();
    if (n == 0) {
        return root;
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    int max_sum = root -> data;
    TreeNode<int>* ans_node = root;
    while (!q.empty()) {
        TreeNode<int>* current = q.front();
        q.pop();
        int current_sum = current -> data;
        int length = (current -> children).size();
        for (int i = 0; i < length; i++) {
            current_sum += (current -> children)[i] -> data;
            q.push((current -> children)[i]);
        }
        if (current_sum > max_sum) {
            max_sum = current_sum;
            ans_node = current;
        }
    }
    return ans_node;
}