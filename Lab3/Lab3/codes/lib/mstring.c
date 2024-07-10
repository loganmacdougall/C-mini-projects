#include<string.h>
#include<stdio.h>

void strrev(char* s) {
        int len = strlen(s);

        for (int i = 0; i < len - i; i++) {
            char tmp = s[i];
            s[i] = s[len-1-i];
            s[len-1-i] = tmp;
        }
}
