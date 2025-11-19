#include <stdio.h>

int main() {
    int n;
    printf("No. of processes: ");
    scanf("%d", &n);

    int p[20], bt[20], pr[20], wt[20], tat[20];

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("BT & Priority of P%d: ", i + 1);
        scanf("%d %d", &bt[i], &pr[i]);
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (pr[j] > pr[i]) {
                int t;
                t = pr[i]; pr[i] = pr[j]; pr[j] = t;
                t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = p[i];  p[i] = p[j];  p[j] = t;
            }

    wt[0] = 0;
    for (int i = 1; i < n; i++) wt[i] = wt[i-1] + bt[i-1];
    for (int i = 0; i < n; i++) tat[i] = wt[i] + bt[i];

    printf("\nPID\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);

    return 0;
}

