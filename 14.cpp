#include <stdio.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME 50

char directory[MAX_FILES][MAX_FILENAME];
int file_count = 0;

void createFile() {
    if (file_count >= MAX_FILES) {
        printf("Directory full!\n");
        return;
    }
    char filename[MAX_FILENAME];
    printf("Enter file name: ");
    scanf("%s", filename);

    // Check if file already exists
    for (int i = 0; i < file_count; i++) {
        if (strcmp(directory[i], filename) == 0) {
            printf("File already exists.\n");
            return;
        }
    }

    strcpy(directory[file_count], filename);
    file_count++;
    printf("File created successfully.\n");
}

void displayFiles() {
    printf("Files in directory:\n");
    for (int i = 0; i < file_count; i++)
        printf("%s\n", directory[i]);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Create File\n2. Display Files\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createFile(); break;
            case 2: displayFiles(); break;
            case 3: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

