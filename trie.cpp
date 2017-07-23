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

void haswords_gen(node* root, string str, int begin, int len, string word, vector<string> list, vector<vector<string>>& lists) {
    if (begin == len) {
        lists.push_back(list);
        return;
    }

    for (int i=begin; i<len;i++) {
        for (int j=1; j<=len-i;j++) {    
            word = str.substr(i,j);
            if (isWord(root, word)) {
                list.push_back(word);
                haswords_gen(root, str,i+j, len, word, list, lists);
                list.pop_back();
            } else if (isPrefix(root, word)) {
                continue;
            } else {
                return;
            }
        }
    }
}


bool hasWords(node* root, string str, vector<vector<string>>& lists) {
    string word;
    vector<string> list;
    haswords_gen(root, str, 0, str.size(), word, list, lists);
    return (!lists.empty());

}


int main() {
    node* trie = getnode();       
    vector<string> str = {"at", "be", "bed", "bat", "than", "bath", "and", "hand", "beyond", "no", "noob", "max", "man", "mix", "grooming", "groom"};
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
    cout << "Find Words in " << key << ": " << endl;
    vector<vector<string>> lists;
    bool ret = hasWords(trie, key, lists);
    if (ret) {
        for (auto list : lists) {
            for (auto words: list) {
                cout << words << " ";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        cout << "N/A" << endl;
    }


    return 0;
}