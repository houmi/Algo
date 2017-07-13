#include <iostream>
#include <string.h>
#include <bitset>

using namespace std;

char* findPrev(const char* start, char* ptr) {
    
    if (ptr == start) {
        return nullptr;
    } else if (ptr-1 == start) {
        return(ptr-1);
    } else if (!(*(ptr-2) & 0x80)) {
        return(ptr-1);
    } 

    char * cur = ptr-2;
    int count=0;
    while (cur > start) {
        count++;
        cur--;
        if (!(*cur & 0x80)) {
            break;
        }
    }

    if (count %2 == 0) {
        return (ptr-2);
    } else {
        return (ptr-1);
    }    
}

printRes(char* start, char* ptr, char* res) {
     if (res) {
        printf("previous character from %c (index=%d) is %c (index = %d)\n", *ptr, ptr-start, *res, res-start);
    } else {
        printf("no previous from %c (index=%d) \n", *ptr, ptr-start);
    }
}


int main() {
    
    char str[100] = "ΦβabβΦcdΣefg";
    printf("%s\n",str);
    char* start = str;
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
    
    char* ptr = str+5;
    char* res = findPrev(str, ptr);
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