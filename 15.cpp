#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_FILES 10
#define MAX_NAME 50

typedef struct {
    char files[MAX_FILES][MAX_NAME];
    int file_count;
} UserDirectory;

typedef struct {
    char username[MAX_NAME];
    UserDirectory udir;
} RootDirectory;

RootDirectory root[MAX_USERS];
int user_count = 0;

int findUser(char username[]) {
    for (int i = 0; i < user_count; i++) {
        if (strcmp(root[i].username, username) == 0)
            return i;
    }
    return -1;
}

void createUser() {
    if (user_count >= MAX_USERS) {
        printf("Root directory full!\n");
        return;
    }
    char username[MAX_NAME];
    printf("Enter username: ");
    scanf("%s", username);

    if (findUser(username) != -1) {
        printf("User already exists.\n");
        return;
    }

    strcpy(root[user_count].username, username);
    root[user_count].udir.file_count = 0;
    user_count++;
    printf("User created successfully.\n");
}

void createFile() {
    char username[MAX_NAME];
    printf("Enter username: ");
    scanf("%s", username);

    int idx = findUser(username);
    if (idx == -1) {
        printf("User not found!\n");
        return;
    }

    if (root[idx].udir.file_count >= MAX_FILES) {
        printf("User directory full!\n");
        return;
    }

    char filename[MAX_NAME];
    printf("Enter file name: ");
    scanf("%s", filename);

    strcpy(root[idx].udir.files[root[idx].udir.file_count], filename);
    root[idx].udir.file_count++;
    printf("File created successfully.\n");
}

void displayFiles() {
    for (int i = 0; i < user_count; i++) {
        printf("User: %s\n", root[i].username);
        for (int j = 0; j < root[i].udir.file_count; j++)
            printf("  %s\n", root[i].udir.files[j]);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Create User\n2. Create File\n3. Display Files\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: createUser(); break;
            case 2: createFile(); break;
            case 3: displayFiles(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

