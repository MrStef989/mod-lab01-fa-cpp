#include <iostream>
#include "fun.h"

int main() {
    const char* test1 = "hello world 123test abc";
    const char* test2 = "Hello World hello Bad1 Ok";
    const char* test3 = "one two three four";

    std::cout << "faStr1: " << faStr1(test1) << std::endl; // слова без цифр
    std::cout << "faStr2: " << faStr2(test2) << std::endl; // слова с заглавной + строчные
    std::cout << "faStr3: " << faStr3(test3) << std::endl; // средняя длина слова

    return 0;
}
