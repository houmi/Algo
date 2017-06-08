#include <iostream>

using namespace std;

class Tree {
    private:

        struct TreeNode {
            TreeNode* left;
            TreeNode* right;
            int data;
        };

    public:
        Tree();

        bool isEmpty();
        void inOrderPrint();
        void postOrderPrint();
        void preOrderPrint();
        TreeNode* insert(int key, TreeNode *root);
        TreeNode* search(int key, TreeNode *root);
        TreeNode* remove(int key, TreeNode* root);

};

Tree::TreeNode* Tree::insert(int key, TreeNode* root) {

    if (root == NULL) {
        TreeNode* node = new TreeNode;
        node->left = NULL;
        node->right = NULL;
        node->data = key;
        return node;
    }

    if (key < root->data) 
        return(insert(key, root->left));
    else
        return(insert(key, root->right));

}

int main()
{
    return 0;
}






