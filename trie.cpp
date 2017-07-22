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
        cout << prefix << word << " ";
    }
    cout << endl;

    
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

bool isPrefix(node* root, string word) {
    node * res = findstring(root, word);
    if (res == nullptr) {
        return false;
    }
    if (!res->isWord) {
        return true;
    } else {
        return false;
    }

}

bool isWord(node* root, string word) {
    node * res = findstring(root, word);
    if (res == nullptr) {
        return false;
    }

    if (res->isWord) {
        return true;
    } else {
        return false;
    }
}

bool haswords_gen(node* root, string str, int i, int j, int len, string word, vector<string> &list) {
    if (j == len) {
        list.push_back(word);
        return true;
    }

    for (int i=j; i<len;i++) {
        word = str.substr(i,j);
        if (isWord(root, word)) {
            list.push_back(word);
            return(haswords_gen(root, str,i+1,j+2,len, word, list));
            list.pop_back();
        }
        if (isPrefix(root, word)) {
            continue;
        }

        return false;
    }

    return false;
}


bool hasWords(node* root, string str, vector<string> &list) {
    string word;
    haswords_gen(root, str, 0, 1, str.size()-1, word, list);
    return (!list.empty());

}


int main() {
    node* trie = getnode();       
    vector<string> str = {"be", "bed", "bath", "and", "hand", "beyond", "no", "noob", "max", "man", "mix", "grooming", "groom"};
    for (auto s:str) {
       insert(trie, s);
    }

    string key;

    cout << "all strings in dictionary:" << endl;
    printall(trie);

    cout << "autocomplete for no" << endl;
    key = "no";
    autocomplete(trie, key);

    cout << "autocomplete for m" << endl;
    key = "m";
    autocomplete(trie, key);

    cout << "autocomplete for gr" << endl;
    key = "gr";
    autocomplete(trie, key);

    key = "bedbathandbeyond";
    vector<string> list;
    hasWords(trie, key, list);


    return 0;
}