#include <cstdio>
#include <string>
#include <stdexcept>
#include <stack>

char array[30000] = {0};
int ptr = 0;

int run(const std::string& script) {
    std::stack<size_t> loopStack;

    for (size_t i = 0; i < script.length(); i++) {
        char c = script[i];

        switch (c) {
            case '>':
                ++ptr;
                break;
            case '<':
                --ptr;
                break;
            case '+':
                array[ptr]++;
                break;
            case '-':
                array[ptr]--;
                break;
            case '.':
                std::putchar(array[ptr]);
                break;
            case ',':
                array[ptr] = std::getchar();
                break;
            case '[':
                if (array[ptr] == 0) {
                    int openBrackets = 1;
                    while (openBrackets > 0)
                    {
                        ++i;
                        if (script[i] == '[') openBrackets++;
                        if (script[i] == ']') openBrackets--;
                    }
                } else {
                    loopStack.push(i);
                }
                break;
            case ']':
                if (array[ptr] != 0) {
                    if (loopStack.empty()) {
                        throw std::runtime_error("Unmatched ']' found.");
                    }
                    i = loopStack.top();
                } else {
                    loopStack.pop();
                }
                break;
            default:
                break;
        }
    }

    putchar('\n');

    return 0;
}