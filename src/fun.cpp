#include "fun.h"
#include <cctype>

// faStr1: считает слова, не содержащие цифр
// Состояния: 0=пробел/начало, 1=идём по слову без цифр, 2=слово с цифрой
unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    int state = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        switch (state) {
            case 0: // вне слова
                if (!isspace(c)) {
                    if (isdigit(c)) state = 2;
                    else            state = 1;
                }
                break;
            case 1: // внутри слова без цифр
                if (isspace(c)) {
                    count++;
                    state = 0;
                } else if (isdigit(c)) {
                    state = 2;
                }
                break;
            case 2: // внутри слова с цифрой
                if (isspace(c)) state = 0;
                break;
        }
    }
    if (state == 1) count++; // последнее слово без пробела в конце
    return count;
}

// faStr2: слова, начинающиеся с заглавной, остальные символы — строчные латинские
// Состояния: 0=вне слова, 1=первый символ заглавный, 2=продолжение ок, 3=слово не подходит
unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    int state = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        switch (state) {
            case 0: // вне слова
                if (!isspace(c)) {
                    if (isupper(c)) state = 1;
                    else            state = 3;
                }
                break;
            case 1: // первый символ был заглавным
                if (isspace(c)) {
                    count++;
                    state = 0;
                } else if (islower(c)) {
                    state = 2;
                } else {
                    state = 3;
                }
                break;
            case 2: // продолжение слова (строчные латинские)
                if (isspace(c)) {
                    count++;
                    state = 0;
                } else if (!islower(c)) {
                    state = 3;
                }
                break;
            case 3: // слово не подходит
                if (isspace(c)) state = 0;
                break;
        }
    }
    if (state == 1 || state == 2) count++;
    return count;
}

// faStr3: средняя длина слова, округлённая
// Состояния: 0=вне слова, 1=внутри слова
unsigned int faStr3(const char *str) {
    unsigned int wordCount = 0;
    unsigned int totalLen  = 0;
    unsigned int curLen    = 0;
    int state = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        switch (state) {
            case 0: // вне слова
                if (!isspace(c)) {
                    curLen = 1;
                    state  = 1;
                }
                break;
            case 1: // внутри слова
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
    // Округление: (total + wordCount/2) / wordCount
    return (totalLen + wordCount / 2) / wordCount;
}
