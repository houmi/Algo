#include <iostream>

using namespace std;

class Tree {
    private:
        struct TreeNode {
            TreeNode* left;
            TreeNode* right;
            int data;
        }

        TreeNode* root;

    public:
        Tree() { root = NULL; }

        bool isEmpty() const { return root == NULL; }
        void inorderPrint();
        void postorderPrint();
        void 

        
}