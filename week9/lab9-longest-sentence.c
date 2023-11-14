#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to find the longest string(s)
void findLongestStrings(int n, char **strings) {
    int maxLength = 0;

    // Find the maximum length among the strings
    for (int i = 0; i < n; ++i) {
        int currentLength = strlen(strings[i]);
        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    // Print the longest string(s)
    for (int i = 0; i < n; ++i) {
        if (strlen(strings[i]) == maxLength) {
            printf("%s\n", strings[i]);
        }
    }
}

// Function to free allocated memory
void freeMemory(int n, char **strings) {
    for (int i = 0; i < n; ++i) {
        free(strings[i]);
    }
    free(strings);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <string1> <string2> ... <stringN>\n", argv[0]);
        return 1;
    }

    // Allocate memory for an array of strings
    char **strings = (char **)malloc((argc - 1) * sizeof(char *));
    if (strings == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Allocate memory for each string and copy it
    for (int i = 0; i < argc - 1; ++i) {
        strings[i] = (char *)malloc((strlen(argv[i + 1]) + 1) * sizeof(char));
        if (strings[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            // Free already allocated memory before exiting
            freeMemory(i, strings);
            return 1;
        }
        strcpy(strings[i], argv[i + 1]);
    }

    // Find and print the longest string(s)
    findLongestStrings(argc - 1, strings);

    // Free allocated memory
    freeMemory(argc - 1, strings);

    return 0;
}