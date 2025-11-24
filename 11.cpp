#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Function executed by Thread 1
void* threadFunc1(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Thread 1: Iteration %d\n", i);
        sleep(1);  // simulate work
    }
    return NULL;
}

// Function executed by Thread 2
void* threadFunc2(void* arg) {
    for (int i = 0; i < 5; i++) {
        printf("Thread 2: Iteration %d\n", i);
        sleep(1);  // simulate work
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create two threads
    pthread_create(&t1, NULL, threadFunc1, NULL);
    pthread_create(&t2, NULL, threadFunc2, NULL);

    // Wait for both threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads finished execution.\n");
    return 0;
}

