#include <stdio.h>
#include <string.h>

char array[30000] = {0};

int run(const char* script) {
    int ptr = 0;

    for (int i = 0; i < strlen(script); i++) {
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
                putchar(array[ptr]);
                break;
            case ',':
                array[ptr] = getchar();
                break;

            default:
                break;
        }

    }
}