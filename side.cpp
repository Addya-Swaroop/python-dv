#include <stdio.h>
int main()
{
    int n, i;
    float avgWT = 0, avgTAT = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int AT[n], BT[n], FT[n], TAT[n], WT[n];
    for (i = 0; i < n; i++)
    {
        printf("AT & BT of P%d: ", i + 1);
        scanf("%d %d", &AT[i], &BT[i]);
    }
 FT[0] = AT[0] + BT[0];
    for (i = 1; i < n; i++)
        FT[i] = FT[i - 1] + BT[i];
    for (i = 0; i < n; i++)
    {
        TAT[i] = FT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        avgWT += WT[i];
        avgTAT += TAT[i];	
    }

    printf("\nP\tAT\tBT\tFT\tTAT\tWT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, AT[i], BT[i], FT[i], TAT[i], WT[i]);
    printf("\nAvg WT = %.2f", avgWT / n);
    printf("\nAvg TAT = %.2f", avgTAT / n);
    return 0;
}