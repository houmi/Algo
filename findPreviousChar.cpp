#include <iostream>
#include <string.h>
#include <bitset>

using namespace std;

// based on a multi-byte string, if the first byte has the high bit set
// then the character is two bytes, otherwise is one byte
//
// move next is: given a char ptr, if the high bit is set, return
// ptr+2, otherwise return ptr+1
// 
// Question: if we're given inputs to a ptr to the current character in
// the string and a ptr to the beginning of string, implement move previous
//
// Note: current pointer is guaranteed to be valid
const char* findPrev(const char* start, const char* ptr) {
    
    if (ptr == start) {
        return nullptr;
    } else if (ptr-1 == start) {
        return ptr-1;
    } else if (!(*(ptr-2) & 0x80)) {
        return ptr-1;
    } 

    const char * cur = ptr-2;
    int count=0;
    while (cur > start) {
        count++;
        cur--;
        if (!(*cur & 0x80)) {
            break;
        }
    }

    if (count %2 == 0) {
        return ptr-2;
    } else {
        return ptr-1;
    }    
}

printRes(const char* start, const char* ptr, const char* res) {
     if (res) {
        printf("previous character from %c (index=%d) is %c (index = %d)\n", *ptr, ptr-start, *res, res-start);
    } else {
        printf("no previous from %c (index=%d) \n", *ptr, ptr-start);
    }
}


int main() {
    
    char str[100] = "ΦβabβΦcdΣefg";
    printf("%s\n",str);
    const char* start = str;
    while (*start != '\0') {
        if ((*start & 0x80) != 0) {
            cout << *start << " : ";
            bitset<8> x(*start);
            start++;
            bitset<8> y(*start);
            cout << x << " " << y << endl;
            start++;
        } else {
            cout << *start << " : ";
            bitset<8> x(*start);
            cout << x << endl;
            start ++;
        }
    }
    
    const char* ptr = str+5;
    const char* res = findPrev(str, ptr);
    printRes(str, ptr, res);
   
    ptr = str;
    res = findPrev(str, ptr);
    printRes(str, ptr, res);

    ptr = str+4;
    res = findPrev(str, ptr);
    printRes(str, ptr, res);

    ptr = str+2;
    res = findPrev(str, ptr);
    printRes(str, ptr, res);

    return 0;
}