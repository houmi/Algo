#include <iostream>

using namespace std;

class Tree {
    private:

        struct node {
            node* left;
            node* right;
            int data;
        };

        node* _root;

    public:
        Tree() { _root = NULL; }
        ~Tree() { _root = deleteTree(_root); }
        bool isEmpty();
        void inorder(void);
        void inOrderPrint(node* root);
        void postOrderPrint(node* root);
        void preOrderPrint(node* root);
        node* deleteTree(node* root);
        void insert(int key);
        node* insert(int key, node* root);
        node* search(int key, node* root);
        node* remove(int key, node* root);

};

/////////////////////////////////////////////////////////////////

Tree::node* Tree::deleteTree(node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
    return NULL;
}

void Tree::insert(int key) {
    _root = insert(key, _root);
}

Tree::node* Tree::insert(int key, node* root) {

    if (root == NULL) {
        root = new node;
        root->left = NULL;
        root->right = NULL;
        root->data = key;
    }

    else if (key < root->data) 
        root->left = insert(key, root->left);
    else if (key > root->data)
        root->right = insert(key, root->right);

    return root;
}

void Tree::inorder(void) { inOrderPrint(_root); cout << endl; }

void Tree::inOrderPrint(node* root) {
    if (root) {
        inOrderPrint(root->left);
        cout << root->data << " ";
        inOrderPrint(root->right);
    }
}


int main()
{
    Tree bst;
    bst.insert(5);
    bst.insert(4);
    bst.insert(8);
    bst.insert(2);
    bst.insert(1);
    bst.inorder();
    

    return 0;
}






