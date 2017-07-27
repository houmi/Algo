#include <iostream>
#include <string>
#include <vector>

using namespace std;

class HashTable {


public:
        HashTable() { initialize_hashtable();}
        ~HashTable() { delete_hashtable(); }
        void delete_hashtable();
        void initialize_hashtable();
        
        long long hashfunc(string);
        string get(HashTable*, string);
        void put(HashTable*, string, string);

private:

        struct hashentry {
            string _key;
            string _value;
            hashentry *next;
            hashentry(string key, string value): _key(key), _value(value), next(nullptr) {}
            string getKey() { return _key;}
            string getValue() { return _value;};
        };

        hashentry *table[1000];


};


void HashTable::initialize_hashtable() {

    for (int i=0; i<1000;i++) {
        table[i] = nullptr;
    }
}


void HashTable::delete_hashtable() {

    for (int i=0; i<1000;i++) {
        if (table[i] != nullptr) {
            hashentry *entry = table[i];
            while (entry != nullptr) {
                hashentry *temp = entry;
                entry = entry->next;
                delete temp;
            }
        }
    }
}

long long HashTable::hashfunc(string key) {
    vector<int> arr = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    long long hash = 1;
    for (int i=0, len=key.size();i<len;i++) {
        int index = (tolower(key[i]) -'0') % arr.size();
        hash *= arr[index];
    }
    return hash;

}


string HashTable::get(HashTable *ht, string key) {
    long long hash = hashfunc(key);
    int index = (hash % 1000);
    string value = "";
    hashentry *entry = ht->table[index];
    while (entry !=nullptr) {
        if (entry->getKey() != key) {
            entry = entry->next;
        } else {
            value = entry->getValue();
            break;
        }
    }
    
    return value;
}

void HashTable::put(HashTable* ht, string key, string value) {
    long long hash = hashfunc(key);
    int index = (hash % 1000);
    hashentry *entry = new hashentry(key, value);
    entry->next = ht->table[index];
    ht->table[index] = entry;
    //TBD case where key value already there i.e. duplicates
}

int main() {
    HashTable *ht = new HashTable;
    vector<pair<string,string>> names = { {"USA", "Washington DC"},{"France", "Paris" }, {"UK", "London"}};
    for (auto name : names) {
        ht->put(ht, name.first, name.second);
    }

    string name = "France";
    cout << name << ": " << ht->get(ht, name) << endl;


    name = "Germany";
    cout << name << ": " << ht->get(ht, name) << endl;


    name = "UK";
    cout << name << ": " << ht->get(ht, name) << endl;

    return 0;
}