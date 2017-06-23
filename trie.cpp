#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node {
    bool isWord;
    node* children[26];
};

node* getnode() {
    node* newnode = nullptr;
    newnode = new node;
    if (newnode) {
        for (int i=0; i<26;i++) {
            newnode->children[i] = nullptr;
        }
        newnode->isWord = false;
    }
    return newnode;
}

void helperprint(node* root, vector<string>& words, string &word) {
    
    for (int i=0; i<26;i++) {
        if (root->children[i]) {
            word += (char)(i+'a');
            helperprint(root->children[i], words, word);
            if (root->children[i]->isWord) {
                words.push_back(word);
            }
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
    int index;
    for (char ch: str) {
        index = tolower(ch) - 'a';
        if (cur->children[index] == nullptr) {
            node* newnode = getnode();
            cur->children[index] = newnode;
        } 

        cur = cur->children[index];
    }
    cur->isWord = true;
}



int main() {
    node* trie = getnode();       
    vector<string> str = {"noob", "max", "man", "mix", "grooming", "groom"};
    for (auto s:str) {
       insert(trie, s);
    }


    printall(trie);
    return 0;
}