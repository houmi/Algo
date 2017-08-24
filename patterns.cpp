#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iterator>
#include <assert.h>

#include "log.h"

using namespace std;


// Given a pattern and a string str, find if str follows the same pattern.
// Examples:
// pattern = "abba", str = "dog cat cat dog" should return true.
// pattern = "abba", str = "dog cat cat fish" should return false.
// pattern = "aaaa", str = "dog cat cat dog" should return false.
// pattern = "abba", str = "dog dog dog dog" should return false.
bool wordPattern(string pattern, string str) {
    unordered_map<char, string> m;
    unordered_set<string> visited;
    
    istringstream buf(str);
    istream_iterator<string> beg(buf), end;
    vector<string> words(beg, end);
    
    if (words.size() != pattern.size()) {
        return false;
    }
    
    for (int i=0, len = pattern.size(); i<len;i++) {
        
        char ch = pattern[i];
        string word = words[i];
        
  
        if (m.count(ch) && m[ch]!=word) {
            return false;
        }            
        
        if (!m.count(ch) && visited.count(word)) {
            return false;
        }
        
        visited.insert(word);
        m[ch] = word;

    } 
    
    return true;
}

bool IsMatch(string pattern, int i, string str, int j, unordered_set<string> visited, unordered_map<char, string> m) {
    int p = pattern.size();
    int q = str.size();
    if (i == p && j == q) {
        FILE_LOG(logDEBUG) << "Done.";
        return true;
    }

    if (i == p || j == q) {
        FILE_LOG(logERROR) << "only one index reached end.";
        return false;
    }

    char ch = pattern[i];

    if (m.count(ch)) {
        string s = m[ch];
        FILE_LOG(logDEBUG) << "matching " << ch << " with " << s;
        string t = str.substr(j,s.size());
        if (s != t) {
            FILE_LOG(logERROR) << "matching returns false, expected: " << s << " got: " << t;
            return false;
        }
        return IsMatch(pattern, i+1, str, j+s.size(), visited, m);
    } 
    
    for (int k=j; k<str.size(); k++) {
        string s = str.substr(j, k-j+1);
        FILE_LOG(logDEBUG) << "using string " << s << " for pattern " << ch;
        if (visited.count(s)) {
            FILE_LOG(logDEBUG) << "already seen " << s << " continue!";
           continue;
        }

        m[ch] = s;
        visited.insert(s);
        FILE_LOG(logDEBUG) << "adding " << ch << "->" << s;;
        if (IsMatch(pattern, i+1, str, k+1, visited, m)) {
            return true;
        }

        FILE_LOG(logDEBUG) << "removing " << ch << "->" << s;
        m.erase(ch);
        visited.erase(s);

    }

    FILE_LOG(logERROR) << "Nada...";
    return false;
}


// Given a pattern and a string str, find if str follows the same pattern.
// Examples:
// pattern = "abba", str = "redbluebluered" should return true.
// pattern = "aaaa", str = "asdasdasdasd" should return true.
// pattern = "aabb", str = "xyzabcxzyabc" should return false. 
bool wordPattern2(string pattern, string str) {
    unordered_set<string> visited;
    unordered_map<char, string> m;
    return IsMatch(pattern, 0, str, 0, visited, m);
}

int main() {

    assert( wordPattern("abba", "dog cat cat dog") == true);
    assert( wordPattern("abba", "dog cat cat fish") == false);
    assert( wordPattern("aaaa", "dog cat cat dog") == false);
    assert( wordPattern("abba", "dog dog dog dog") == false);

    assert( wordPattern2("abba", "redbluebluered") == true);
    assert( wordPattern2("aaaa", "asdasdasdasd") == true);
    assert( wordPattern2("aba", "xyzxyzxyz") == false );

    return 0;
}