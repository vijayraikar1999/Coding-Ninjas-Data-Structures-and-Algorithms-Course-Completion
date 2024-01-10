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
bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if ((root1 == nullptr && root2 != nullptr) || (root2 == nullptr && root1 != nullptr)) {
        return false;
    }
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    queue<TreeNode<int>*> q1;
    queue<TreeNode<int>*> q2;


    q1.push(root1);
    q2.push(root2);

    while (!q1.empty() && !q2.empty()) {
        TreeNode<int>* current1 = q1.front();
        TreeNode<int>* current2 = q2.front();

        if (current1 -> data != current2 -> data) {
            return false;
        }
        q1.pop();
        q2.pop();
        int n1 = (current1 -> children).size();
        int n2 = (current2 -> children).size();
        if (n1 != n2) {
            return false;
        }
        for (int i = 0; i < n1; i++) {
            q1.push((current1 -> children)[i]);
        }
        for (int i = 0; i < n2; i++) {
            q2.push((current2 -> children)[i]);
        }
    }
    return true;
}