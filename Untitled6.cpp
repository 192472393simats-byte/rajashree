#include <stdio.h>

int main() {
    int n;
    printf("No. of processes: ");
    scanf("%d", &n);

    int p[20], bt[20], wt[20], tat[20];

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (bt[j] < bt[i]) {
                int t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }

    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];

    for (int i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nPID\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);

    return 0;
}

