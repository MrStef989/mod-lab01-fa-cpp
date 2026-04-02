// Copyright 2024 MrStef989
#include "fun.h"
#include <cctype>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    int state = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        switch (state) {
            case 0:
                if (!isspace(c)) {
                    if (isdigit(c)) state = 2;
                    else
                        state = 1;
                }
                break;
            case 1:
                if (isspace(c)) {
                    count++;
                    state = 0;
                } else if (isdigit(c)) {
                    state = 2;
                }
                break;
            case 2:
                if (isspace(c)) state = 0;
                break;
        }
    }
    if (state == 1) count++;
    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    int state = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        switch (state) {
            case 0:
                if (!isspace(c)) {
                    if (isupper(c)) state = 1;
                    else
                        state = 3;
                }
                break;
            case 1:
                if (isspace(c)) {
                    count++;
                    state = 0;
                } else if (islower(c)) {
                    state = 2;
                } else {
                    state = 3;
                }
                break;
            case 2:
                if (isspace(c)) {
                    count++;
                    state = 0;
                } else if (!islower(c)) {
                    state = 3;
                }
                break;
            case 3:
                if (isspace(c)) state = 0;
                break;
        }
    }
    if (state == 1 || state == 2) count++;
    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int wordCount = 0;
    unsigned int totalLen = 0;
    unsigned int curLen = 0;
    int state = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        switch (state) {
            case 0:
                if (!isspace(c)) {
                    curLen = 1;
                    state = 1;
                }
                break;
            case 1:
                if (isspace(c)) {
                    wordCount++;
                    totalLen += curLen;
                    state = 0;
                } else {
                    curLen++;
                }
                break;
        }
    }
    if (state == 1) {
        wordCount++;
        totalLen += curLen;
    }
    if (wordCount == 0) return 0;
    return (totalLen + wordCount / 2) / wordCount;
}
