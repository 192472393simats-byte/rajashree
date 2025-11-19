#include <stdio.h>

int main() {
    int n, time = 0, completed = 0, minp, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[20], bt[20], pr[20], rt[20], p[20];

    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("AT BT Priority of P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    printf("\nGantt Chart:\n");

    while (completed < n) {
        int hp = -1, idx = -1;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (pr[i] > hp) {
                    hp = pr[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) { time++; continue; }

        printf("P%d ", p[idx]);
        rt[idx]--;

        if (rt[idx] == 0) completed++;

        time++;
    }

    return 0;
}

