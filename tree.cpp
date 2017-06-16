#include <iostream>
#include <queue> // use STD for now...
#include <stack>
#include <string>
#include <climits>

using namespace std;

struct Tree_Node;

class Tree {
    private:

        using node = Tree_Node;
        node* _root;
        Tree(const Tree &obj);
        Tree& operator=( const Tree& other);

    public:
        Tree() { _root = nullptr; }
        ~Tree() { _root = deleteTree(); }
        

        bool isEmpty() const;
        void inorder() const;
        void preorder() const;
        void postorder() const;
        void inOrderPrintRecursive(string &) const;
        void inOrderPrintIterative(string &) const ;
        void preOrderPrintRecursive(string &) const;
        void postOrderPrintRecursive(string &) const;
        void levelorder() const; 
        void levelorder2() const;
        void reverse();
        void reverseTree();
        bool isBSTUtil(int , int );
        void isBST();
        int getHeight();

        
        node* deleteTree();
        void insert(int);
};

struct Tree_Node {
        Tree left;
        Tree right;
        int data;
};

/////////////////////////////////////////////////////////////////

Tree::node* Tree::deleteTree() {
    if (_root) {
        _root->left.deleteTree();
        _root->right.deleteTree();
        delete _root;
        _root = nullptr;
    }
    return _root;
}

void Tree::insert(int key) {

    if (_root == nullptr) {
        _root = new node;
        _root->data = key;
    }
    else if (key < _root->data) {
        _root->left.insert(key);
    }
    else if (key > _root->data) {
        _root->right.insert(key);
    }
}

void Tree::inorder() const { 
    string str, str2;
    inOrderPrintRecursive(str);
    inOrderPrintIterative(str2);
    cout << "in order print (recursive):" << str << endl;
    cout << "in order print (iterative):" << str2 << endl;
    
}

void Tree::inOrderPrintRecursive(string &str)  const {
    if (_root) {
        _root->left.inOrderPrintRecursive(str);
        str += to_string(_root->data) + " ";
        _root->right.inOrderPrintRecursive(str);
    }
}

void Tree::inOrderPrintIterative(string &str) const {
    stack<node*> nodeStack;
    node* root = _root;
    for (;;) {
        if (root) {
            nodeStack.push(root);
            root = root->left._root;
        } else {
            if (nodeStack.empty()) {
                break;
            }
            root = nodeStack.top();
            nodeStack.pop();
            str += to_string(root->data) + " ";
            root = root->right._root;
        }
    }
}


void Tree::postorder() const { 
    string str;
    postOrderPrintRecursive(str);
    cout << "post order print (recursive):" << str << endl;
}

void Tree::postOrderPrintRecursive(string &str)  const {
    if (_root) {
        _root->left.postOrderPrintRecursive(str);
        _root->right.postOrderPrintRecursive(str);       
        str += to_string(_root->data) + " ";
    }
}

void Tree::preorder() const { 
    string str;
    preOrderPrintRecursive(str);
    cout << "pre order print (recursive):" << str << endl;   
}

void Tree::preOrderPrintRecursive(string &str)  const {
    if (_root) {
        str += to_string(_root->data) + " ";
        _root->left.preOrderPrintRecursive(str);
        _root->right.preOrderPrintRecursive(str);
    }
}

// BFS
void Tree::levelorder() const { 
    queue<node *> nodeList;

    node* root = _root;

    if (root) {
        nodeList.push(root);
    }

    cout << "level order print (top-bottom):";

    while(nodeList.size()) {
        node* temp = nodeList.front();
        nodeList.pop();
        cout << temp->data << " ";
        if (temp->left._root) {
            nodeList.push(temp->left._root);
        }
        if (temp->right._root) {
            nodeList.push(temp->right._root);
        }
    }
    cout << endl;
}

// BFS
void Tree::levelorder2() const { 
    queue<node *> nodeList;
    stack<node *> nodeList2;
    node* root = _root;

    if (root) {
        nodeList.push(root);
    }

    cout << "level order print (bottom-top):";

    while(nodeList.size()) {
        node* temp = nodeList.front();
        nodeList.pop();
        nodeList2.push(temp);
        if (temp->right._root) {
            nodeList.push(temp->right._root);
        }
        if (temp->left._root) {
            nodeList.push(temp->left._root);
        }
    }

    while (nodeList2.size()) {
        cout << nodeList2.top()->data << " ";
        nodeList2.pop();
    }
    cout << endl;
}

void Tree::reverse() {
    cout << "Reversing Tree" << endl;
    reverseTree();
}

void Tree::reverseTree() {
    if (_root) {
        _root->left.reverseTree();
        _root->right.reverseTree();
       std:swap(_root->left._root, _root->right._root);
    }
}

void Tree::isBST() {
    bool isBST = isBSTUtil(INT_MIN, INT_MAX);
    if (isBST) {
        cout << "Tree is a BST" << endl;
    } else {
        cout << "Tree is NOT BST" << endl;
    }
}

int Tree::getHeight() {
    if (_root == nullptr) {
        return 0;
    }

    return max(_root->left.getHeight(), _root->right.getHeight())+1;

}

bool Tree::isBSTUtil(int min, int max) {
    if (_root == nullptr) {
        return true;
    } else if (_root->data < min || _root->data > max) {
        return false;
    }
    
    return (_root->left.isBSTUtil(min, _root->data)) && (_root->right.isBSTUtil(min, _root->data));
    
}

int main()
{
    Tree bst;
    
    // fill tree
    bst.insert(4);
    bst.insert(2);
    bst.insert(6);
    bst.insert(1);
    bst.insert(3);
    bst.insert(5);
    bst.insert(7);

    // print
    bst.inorder();
    bst.preorder();
    bst.postorder();

    // BFS
    bst.levelorder();
    bst.levelorder2();

    // reverse & isBST
    bst.reverse();
    bst.isBST();
    bst.levelorder();

    // reverse back
    bst.reverse();
    bst.isBST();
    bst.levelorder();
    cout << "Height of Tree: " << bst.getHeight() << endl;
    
    

    return 0;
}






