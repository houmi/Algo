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

void helperprint(node* root, vector<string>& words, string word) {
    
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


void printall(node *root, string prefix="") {

    string word = "";
    vector<string> words;

    helperprint(root, words, word);

    for (auto word : words) {
        cout << prefix << word << endl;
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


node* findstring(node* root, string word) {
    
    node* cur = root;

    for (char ch : word) {
        int index = ch - 'a';
        if (cur->children[index]) {
            cur = cur->children[index];
        } else {
            return nullptr;
        }
    }

    return cur;

}

void autocomplete(node* root, string word) {
    
    node* res = findstring(root, word);
    if (res != nullptr) {
        printall(res, word);
    }
}




int main() {
    node* trie = getnode();       
    vector<string> str = {"noob", "max", "man", "mix", "grooming", "groom"};
    for (auto s:str) {
       insert(trie, s);
    }

    string key;

    cout << "all strings in dictionary:" << endl;
    printall(trie);

    cout << "autocomplete for m" << endl;
    key = "m";
    autocomplete(trie, key);

    cout << "autocomplete for gr" << endl;
    key = "gr";
    autocomplete(trie, key);

    return 0;
}