#include <iostream>

using namespace std;

class Tree {
    private:

        typedef struct TreeNode {
            TreeNode* left;
            TreeNode* right;
            int data;
        } TreeNode;

        TreeNode* root;

    public:
        Tree() { root = NULL; }

        bool isEmpty() const { return root == NULL; }
        void inOrderPrint();
        void postOrderPrint();
        void preOrderPrint();
        void insert(int key, TreeNode *root);
        TreeNode* search(int key, TreeNode *root);
        TreeNode* remove(int key, TreeNode* root);

};



