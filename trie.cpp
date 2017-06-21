#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
    node* children[26];
};

node* getnode() {
    node* newnode = nullptr;
    newnode = new node;
    if (newnode) {
        for (int i=0; i<26;i++) {
            newnode->children[i] = nullptr;
        }
    }
    return newnode;
}

void printall(node *root) {

    for (int i=0; i<26;i++) {
        if (root->children[i]) {
            printall(root->children[i]);
            cout << (char)(i+'a') << endl;
        }
    }
}

void insert(node* root, string str) {
    node* cur = root;
    for (char ch: str) {
        int index = tolower(ch) - 'a';
        if (cur->children[index] == nullptr) {
            node* newnode = getnode();
            cur->children[index] = newnode;
        } 

        cur = cur->children[index];
    }
  
}



int main() {
    node* trie = getnode();       
    vector<string> str = {"noob", "max", "man", "mix", "groom"};
    for (auto s:str) {
       insert(trie, s);
    }

    printall(trie);
}