#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file1, *file2;
    char ch1, ch2;
    int areEqual = 1; // Assume files are equal initially

    // Open the first file in read mode
    file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        printf("Unable to open file1.txt.\n");
        return 1;
    }

    // Open the second file in read mode
    file2 = fopen("file2.txt", "r");
    if (file2 == NULL) {
        printf("Unable to open file2.txt.\n");
        fclose(file1);
        return 1;
    }

    // Compare contents character by character
    while ((ch1 = fgetc(file1)) != EOF && (ch2 = fgetc(file2)) != EOF) {
        if (ch1 != ch2) {
            areEqual = 0; // Files are not equal
            break;
        }
    }

    // If both files are of different lengths, they are not equal
    if (ch1 != EOF || ch2 != EOF) {
        areEqual = 0;
    }

    // Close the files
    fclose(file1);
    fclose(file2);

    // Display comparison result
    if (areEqual) {
        printf("Files are identical.\n");
    } else {
        printf("Files are not identical.\n");
    }

    return 0;
}
