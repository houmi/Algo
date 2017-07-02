#include <iostream>
#include <vector>

using namespace std;

struct node {
    int val;
    node *next;
    node(int x): val(x), next(nullptr) {}
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

void insert(node** root, int key) {
    node* temp = new node(key);

    if (*root == nullptr) {
        *root = temp;
    } else {
        temp->next = *root;
        *root = temp;
    }
}

void print(node* root) {
    if (root == nullptr) {
        cout << "nullptr";
        cout << endl;
        return;
    }
    cout << root->val << "->";
    print(root->next);
}

void reverse(node ** root) {
    cout << "Reverse linked list (iterative)" << endl;
    if (root == nullptr) {
        return;
    }

    node* rev = nullptr;

    while (*root != nullptr) {
        node* next  = (*root)->next;
        (*root)->next = rev;
        rev = *root;
        *root = next;        
    }

    *root = rev;

}

node* reverseRecurse(node *root) {
    if (root == nullptr || root->next == nullptr) {
        return root;
    }

    node* p = reverseRecurse(root->next);
    root->next->next = root;
    root->next = nullptr;

    return p;

}


int main() {
    node* list = nullptr;

    vector<int> arr = { 5,4,3,2,1};

    for (auto num : arr) {
        insert(&list, num);
    }

    print(list);
    reverse(&list);
    print(list);
    cout << "Reverse linked list (recursive)" << endl;
    list = reverseRecurse(list);
    print(list);

    return 0;
}