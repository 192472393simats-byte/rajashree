#include <windows.h>
#include <stdio.h>

// Message structure
struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    struct msg_buffer message;
    int msgid = msgget(key, 0666 | IPC_CREAT);

    if (fork() == 0) {
        // -------------------------
        // Child: RECEIVER
        // -------------------------
        msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
        printf("Child received: %s\n", message.msg_text);
    }
    else {
        // -------------------------
        // Parent: SENDER
        // -------------------------
        message.msg_type = 1;
        strcpy(message.msg_text, "Hello from Message Queue!");

        msgsnd(msgid, &message, sizeof(message.msg_text), 0);
        wait(NULL);

        // Remove message queue
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}

