#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
    int level;
    node* children[26];
};

node* getnode(int level) {
    node* newnode = nullptr;
    newnode = new node;
    if (newnode) {
        newnode->level = level;
        for (int i=0; i<26;i++) {
            newnode->children[i] = nullptr;
        }
    }
    return newnode;
}

void helperprint(node* root, vector<string>& words, string &word) {
    
    for (int i=0; i<26;i++) {
        if (root->children[i]) {
            word += (char)(i+'a');
            helperprint(root->children[i], words, word);
            words.push_back(word);
            word.pop_back();          
        }
    }
}

void printall(node *root) {

    string word = "";
    vector<string> words;

    helperprint(root, words, word);

    for (auto word : words) {
        cout << word << endl;
    }

    
}

void insert(node* root, string str) {
    node* cur = root;
    int level = 1;
    for (char ch: str) {
        int index = tolower(ch) - 'a';
        if (cur->children[index] == nullptr) {
            node* newnode = getnode(level);
            level++;
            cur->children[index] = newnode;
        } 

        cur = cur->children[index];
    }
  
}



int main() {
    node* trie = getnode(0);       
    vector<string> str = {"noob", "max", "man", "mix", "groom"};
    for (auto s:str) {
       insert(trie, s);
    }


    printall(trie);
    return 0;
}