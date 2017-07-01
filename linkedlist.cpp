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
    }
    cout << root->val << "->";
    print(root->next);
}


int main() {
    node* list = nullptr;

    vector<int> arr = { 5,4,3,2,1};

    for (auto num : arr) {
        insert(&list, num);
    }

    print(list);

    return 0;
}