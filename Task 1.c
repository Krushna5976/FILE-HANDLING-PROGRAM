#include <stdio.h>
#include <stdlib.h>

void create_file(const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for creation");
        exit(1);
    }
    fclose(fp);
}

void write_to_file(const char* filename, const char* data) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        exit(1);
    }
    fprintf(fp, "%s", data);
    fclose(fp);
}

void read_from_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file for reading");
        exit(1);
    }
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);
}

void append_to_file(const char* filename, const char* data) {
    FILE* fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Error opening file for appending");
        exit(1);
    }
    fprintf(fp, "%s", data);
    fclose(fp);
}

int main() {
    const char* filename = "my_file.txt";

    // Create a new file
    create_file(filename);

    // Write data to the file
    write_to_file(filename, "This is the first line.\n");

    // Append data to the file
    append_to_file(filename, "This is the second line.\n");

    // Read data from the file
    printf("File contents:\n");
    read_from_file(filename);

    return 0;
}
