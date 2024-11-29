#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "brainfuck.c"

char* readFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Move the file pointer to the end of the file to determine its size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET); // Move back to the beginning of the file

    // Allocate memory for the string (+1 for the null terminator)
    char* buffer = (char*)malloc(fileSize + 1);
    if (buffer == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    // Read the file into the buffer
    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0'; // Null-terminate the string

    fclose(file);
    return buffer;
}

int main() {
    char* fileContent = readFile("example.bf");

    if (fileContent != NULL) {

        run(fileContent);

        free(fileContent); 
    }

    return 0;
}