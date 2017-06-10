#include <iostream>
#include <queue> // use STD for now...
#include <stack>
#include <string>

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
        Tree() { _root = nullptr; }
        ~Tree() { _root = deleteTree(_root); }
        bool isEmpty() const;
        void inorder() const;
        void preorder() const;
        void postorder() const;
        void inOrderPrintRecursive(node*, string &) const;
        void inOrderPrintIterative(node*, string &) const;
        void preOrderPrintRecursive(node*, string &) const;
        //void preOrderPrintIterative(node*, string &) const;
        void postOrderPrintRecursive(node*, string &) const;
        //void postOrderPrintIterative(node*, string &) const;
        void levelorder() const; 
        void levelorder2() const;

        
        node* deleteTree(node*);
        void insert(int);
        node* insert(int,node*);
        node* search(int,node*);
        node* remove(int,node*);

};

/////////////////////////////////////////////////////////////////

Tree::node* Tree::deleteTree(node* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
    return nullptr;
}

void Tree::insert(int key) {
    _root = insert(key, _root);
}

Tree::node* Tree::insert(int key, node* root) {

    if (root == nullptr) {
        root = new node;
        root->left = nullptr;
        root->right = nullptr;
        root->data = key;
    }

    else if (key < root->data) {
        root->left = insert(key, root->left);
    }
    else if (key > root->data) {
        root->right = insert(key, root->right);
    }

    return root;
}

void Tree::inorder() const { 
    string str, str2;
    inOrderPrintRecursive(_root, str);
    inOrderPrintIterative(_root, str2);
    cout << "in order print (recursive):" << str << endl;
    cout << "in order print (iterative):" << str2 << endl;
    
}

void Tree::inOrderPrintRecursive(node* root, string &str)  const {
    if (root) {
        inOrderPrintRecursive(root->left,str);
        str += to_string(root->data) + " ";
        inOrderPrintRecursive(root->right,str);
    }
}

void Tree::inOrderPrintIterative(node* root, string &str) const {
    stack<node*> nodeStack;
    for (;;) {
        if (root) {
            nodeStack.push(root);
            root = root->left;
        } else {
            if (nodeStack.empty()) {
                break;
            }
            root = nodeStack.top();
            nodeStack.pop();
            str += to_string(root->data) + " ";
            root = root->right;
        }
    }
}


void Tree::postorder() const { 
    string str, str2;
    postOrderPrintRecursive(_root, str);
    //inOrderPrintIterative(_root, str2);
    cout << "post order print (recursive):" << str << endl;
    //cout << "in order print (iterative):" << str2 << endl;
    
}

void Tree::postOrderPrintRecursive(node* root, string &str)  const {
    if (root) {
        postOrderPrintRecursive(root->left,str);
        postOrderPrintRecursive(root->right,str);
        str += to_string(root->data) + " ";
    }
}

void Tree::preorder() const { 
    string str, str2;
    preOrderPrintRecursive(_root, str);
    //inOrderPrintIterative(_root, str2);
    cout << "pre order print (recursive):" << str << endl;
    //cout << "in order print (iterative):" << str2 << endl;
    
}

void Tree::preOrderPrintRecursive(node* root, string &str)  const {
    if (root) {
        str += to_string(root->data) + " ";
        preOrderPrintRecursive(root->left,str);
        preOrderPrintRecursive(root->right,str);
    }
}


// BFS
void Tree::levelorder() const { 
    queue<node *> nodeList;

    if (_root) {
        nodeList.push(_root);
    }

    cout << "level order print (top-bottom):";

    while(nodeList.size()) {
        node* temp = nodeList.front();
        nodeList.pop();
        cout << temp->data << " ";
        if (temp->left) {
            nodeList.push(temp->left);
        }
        if (temp->right) {
            nodeList.push(temp->right);
        }
    }
    cout << endl;
}

// BFS
void Tree::levelorder2() const { 
    queue<node *> nodeList;
    stack<node *> nodeList2;

    if (_root) {
        nodeList.push(_root);
    }

    cout << "level order print (bottom-top):";

    while(nodeList.size()) {
        node* temp = nodeList.front();
        nodeList.pop();
        nodeList2.push(temp);
        if (temp->right) {
            nodeList.push(temp->right);
        }
        if (temp->left) {
            nodeList.push(temp->left);
        }
    }

    while (nodeList2.size()) {
        cout << nodeList2.top()->data << " ";
        nodeList2.pop();
    }
    cout << endl;
}

int main()
{
    Tree bst;
    bst.insert(4);
    bst.insert(2);
    bst.insert(6);
    bst.insert(1);
    bst.insert(3);
    bst.insert(5);
    bst.insert(7);
    bst.inorder();
    bst.preorder();
    bst.postorder();
    bst.levelorder();
    bst.levelorder2();
    

    return 0;
}






