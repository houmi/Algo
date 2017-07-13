#include <iostream>
#include <string.h>

char* findPrev(const char* start, char* ptr) {
    
    char* res;

    if (ptr == start) {
        res = nullptr;
    } else if (ptr-1 == start) {
        res = ptr;
    } else if (!(*(ptr-2) & 0x80)) {
        res = ptr-1;
    } else {
        res = ptr-2;
    }

    return res;
    
}


int main() {
    
    char str[100] = "βabΦΦcdΣefg";
    char* start = str;
    while (*start != '\0') {
        if (*start & 0x80) {
            printf("%c: ", *start);
            printf("0x%xh 0x%xh\n", *start, *start+1);
            start +=2;
        } else {
            printf("%c: ", *start);
            printf("0x%xh\n", *start);
            start++;
        }
    }
    
    char* ptr = str+4;
    char* res = findPrev(str, ptr);

    printf("%c\n", *ptr);

    return 0;
}