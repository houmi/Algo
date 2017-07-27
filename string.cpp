#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void reverseString(string &str, int start, int end, int writeTo, bool copy = false) {
    int src = start;
    int dst = end;

    while (start < end) {
        char temp = str[end];
        str[end--] = str[start];
        str[start++] = temp;
    }

    if (copy) {
        while (src <= dst) {
            str[writeTo++] = str[src++];     
        }
    }
}
    
void reverseWords(string &s) {
    cout << "Reverse words (remove extra spaces): "<< s << endl;

    int start = 0;
    int end = s.size()-1;
    int writeTo = 0;
    
    while (start < end) {

        while (start < end && s[start] == ' ') {
            start++;
        }

        while (start < end && s[end] == ' ') {
            end--;;
        }

        // start of word
        int wordStartIndex = start;
        while (start <= end && s[start] != ' ') {
            start++;
        }

        // end of word TBD end of string
        reverseString(s, wordStartIndex, start-1, writeTo, true); // -1 because of space
        writeTo += (start-wordStartIndex);
        if (start < end) {
            s[writeTo++] = ' ';
        }

    }

    s.resize(writeTo);
    reverseString(s, 0, s.size()-1, false, writeTo);


    
}

void parenHelper(int left, int right, const string& result, vector<string>& solution) {
    if (!left && !right) {
        solution.push_back(result);
        return;
    }
  

    if (left > 0) {
        parenHelper(left-1, right, result + '(', solution);
    } 
    
    if (right > left) {
        parenHelper(left, right-1, result + ')', solution);
    }


}

// generate all matched parenthesis for n
// i.e for 2 return ()() and (())
void parenthesis(int n) {
    cout << "Generate strings of matched parens for n=" << n << endl;
    vector<string> solution;
    parenHelper(n, n, "", solution);
    for (auto s : solution) {
      cout << s << endl;
    }
}

bool isValidString(string str) {

    int leftCount=0;

    for (char ch : str) {
        if (ch == '(') {
            leftCount++;
        } else if (ch == ')') {
            leftCount--;
            if (leftCount < 0) {
                return false;
            }
        }
    }

    return (leftCount == 0);

}

// given a string with parenthesis and letters/number, return the correct
// parenthesis format (don't go any lower in #s)
// i.e : ())a)() could return  ()a() and (a)()
void balanceParenthesis(string str) {
    queue<string> strList;
    set<string> visitedStr;
    vector<string> res;

    strList.push(str);
    visitedStr.insert(str);
    bool level = false;

    while (!strList.empty()) {
        string temp = strList.front();
        strList.pop();

        if (isValidString(temp)) {
            res.push_back(temp);
            level = true;
        }

        if (level) {
            continue;
        }
            
        for (size_t i=0, len = temp.length(); i<len; ++i) {
            if (!(temp[i] == ')' || temp[i] == '(')) {
                continue;
            }
            string s = temp.substr(0,i) + temp.substr(i+1);
            if (visitedStr.find(s) == visitedStr.end()) {
                strList.push(s);
                visitedStr.insert(s);
            }
        }
        
    }

    cout << "Balance Parenthesis for " << str << ":" << endl;
    for (auto s : res) {
        cout << s << " ";
    }
    cout << endl;
    
}

string zigzag(string s, int numRows) {
    if (numRows >= s.size()) {
        return s;
    }

    if (numRows <= 1) {
        return s;
    }

    int start = 0;
    int end = s.size();
    vector<string> v(numRows+1,"");
    
    int index = 0;
    bool up = true;
    
    while (start < end) {
        v[index].push_back(s[start++]);

        if (up && index== numRows-1) {
            index--;
            up = false;
        } else if (!up && index == 0) {
            index++;
            up = true;
        } else if (up) {
            index++;
        } else {
            index--;
        }
    }

    string res;
    for (auto s : v) {
        res += s;
    }
    
    return res;
    
}

int main() {

    string s = "         THis is a test        blablabla                crap";
    reverseWords(s);
    cout << s << endl;
    
    parenthesis(2);
    parenthesis(3);
    parenthesis(4);

    balanceParenthesis("v");
    balanceParenthesis("(v)v");
    balanceParenthesis(")");
    balanceParenthesis("()(v)())v");
    balanceParenthesis("(");
    balanceParenthesis(")(");
    balanceParenthesis("(v()()()");
    balanceParenthesis("(()(()(()(");
    balanceParenthesis("))))))))))))))()()");
    balanceParenthesis("())a)()");

    s = "PAYPALISHIRING";
    cout << "Zigzag of " << s << " in 3 rows is: " << zigzag(s, 3) << endl;

    return 0;
}
	