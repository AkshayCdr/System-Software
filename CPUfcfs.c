#include <stdio.h>
#define max 100
void swap(int *x, int *y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}

int main()
{
    int p[max], bt[max], at[max], temp[max], n, sum = 0;
    int tt[max] = {0}, wt[max] = {0}, ct[max] = {0};
    float ttt = 0, twt = 0;
    printf("Enter number of process ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("Enter burst time %d ", i + 1);
        scanf("%d", &bt[i]);
        printf("Enter arrival time %d ", i + 1);
        scanf("%d", &at[i]);
    }
    // sort based on arrival time
    for (int j = 1; j < n; j++)
    {
        for (int k = 0; k < n - j; k++)
        {
            if (at[k] > at[k + 1] || (at[k] == at[k + 1] && p[k] > p[k + 1]))
            {
                swap(&at[k], &at[k + 1]);
                swap(&bt[k], &bt[k + 1]);
                swap(&p[k], &p[k + 1]);
            }
        }
    }
    printf("p\tct t\twt t\ttt\n");
    for (int i = 0; i < n; i++)
    {
        sum += bt[i];
        ct[i] += sum;
        tt[i] = ct[i] - at[i];
        wt[i] = tt[i] - bt[i];
        ttt += tt[i];
        twt += wt[i];
        printf("%d\t%d\t%d\t%d\n", p[i], ct[i], wt[i], tt[i]);
    }
    printf("\nAverage wt tt is = %d %d ", (float)twt / n, (float)ttt / n);
}