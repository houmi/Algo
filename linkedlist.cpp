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
    temp->next = *root;
    *root = temp;
}



void insertLast(node** root, int key) {
    node *temp = new node(key);

    node* cur = *root;

    while (cur != nullptr && cur->next != nullptr) {
        cur = cur->next;
    }

    if (cur == nullptr) {
        cur = temp;
    } else {
        cur->next = temp;
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

void remove(node** root, int key) {
    cout << "Removing node with value " << key << " from the list" << endl;
    if (*root == nullptr) {
        return;
    }

    if ((*root)->val == key) {
        node* cur = *root;
        *root = (*root)->next;
        delete cur;
        return;
    }

    node* cur = *root;

    while (cur != nullptr) {
        if (cur->next->val == key) {
            node* del = cur->next;
            cur->next = del->next;
            delete del;
            return;
        }

        cur = cur->next;
    }

}

bool isPalindrome(node* root) {
    node* slow = root;
    node* fast = root;
    node* cur = root;

    // move slow to mid linked list
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse list from slow -> fast
    reverse(&slow);
    
    while (slow!=nullptr && cur!=nullptr) {
        if (slow->val != cur->val) {
            return false;
        }
        slow = slow->next;
        cur = cur->next;
    }

    return true;    
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
    remove(&list,1); print(list);
    remove(&list,5); print(list);
    remove(&list,3); print(list);

    for (int i=6; i <=20; i += 2) {
        insertLast(&list, i);
    }

    for (int i=4; i<=20; i += 2) {
        insert(&list, i);
    }
    
    print(list);

    if (isPalindrome(list)) {
        cout << "List is Palindrom" << endl;
    } else {
        cout << "List isn't Palindrom" << endl;
    }

    return 0;
}