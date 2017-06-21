#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
    vector<node*> children;   
};



void insert(node* root, string str) {
    node* cur = root;
    for (char ch: str) {
        int index = ch - '0';
        if (cur->children[index] == nullptr) {
            node* newnode = new node;
            cur->children[index] = newnode;
        } 

        cur = cur->children[index];
    }

    
}




int main() {
    node* trie = new node;

    string str = "noob";
    insert(trie, str);


}