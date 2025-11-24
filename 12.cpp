#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5 // Number of philosophers

pthread_mutex_t forks[N];

void* philosopher(void* num) {
    int id = *(int*)num;

    while (1) {
        printf("Philosopher %d is thinking.\n", id);
        sleep(1);

        // Pick up forks (lower number first to prevent deadlock)
        int left = id;
        int right = (id + 1) % N;

        if (id % 2 == 0) { // Avoid circular wait
            pthread_mutex_lock(&forks[left]);
            pthread_mutex_lock(&forks[right]);
        } else {
            pthread_mutex_lock(&forks[right]);
            pthread_mutex_lock(&forks[left]);
        }

        printf("Philosopher %d is eating.\n", id);
        sleep(1);

        pthread_mutex_unlock(&forks[left]);
        pthread_mutex_unlock(&forks[right]);
    }
}

int main() {
    pthread_t ph[N];
    int ids[N];

    for (int i = 0; i < N; i++)
        pthread_mutex_init(&forks[i], NULL);

    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&ph[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(ph[i], NULL);

    for (int i = 0; i < N; i++)
        pthread_mutex_destroy(&forks[i]);

    return 0;
}

