#include <iostream>
#include <string.h>
#include <bitset>

using namespace std;

char* findPrev(const char* start, char* ptr) {
    
    char* res = nullptr;
    if (ptr == start) {
        res = nullptr;
    } else if (ptr-1 == start) {
        res = ptr-1;
    } else if (!(*ptr & 0x80)) {
        res = ptr-1;
    } else {
        res = ptr-2;
    }
    
    return res;
    
}


int main() {
    
    char str[100] = "ΦβabβΦcdΣefg";
    printf("%s\n",str);
    char* start = str;
    while (*start != '\0') {
        if (*start & 0x80) {
            printf("%c: ", *start);
            bitset<8> x(*start);
            bitset<8> y(*start+1);
            cout << x << " " << y << endl;
            start +=2;
        } else {
            printf("%c: ", *start);
            bitset<8> x(*start);
            cout << x << endl;
            start++;
        }
    }
    
    char* ptr = str+5;
    char* res = findPrev(str, ptr);
    if (res) {
        printf("previous character from %c is %c\n", *ptr, *res);
    } else {
        printf("no previous\n");
    }

    ptr = str;
    res = findPrev(str, ptr);
    if (res) {
        printf("previous character from %c is %c\n", *ptr, *res);
    } else {
        printf("no previous \n");
    }

    ptr = str+4;
    res = findPrev(str, ptr);
    if (res) {
        printf("previous character from %c is %c\n", *ptr, *res);
    } else {
        printf("no previous \n");
    }

    ptr = str+1;
    res = findPrev(str, ptr);
    if (res) {
        printf("previous character from %c is %c\n", *ptr, *res);
    } else {
        printf("no previous \n");
    }

    return 0;
}