#include <stdio.h>

void main()
{
    int n,at[20],bt[20],wt[20],st[20],tat[20],i;
    float ttat,twt;
    printf("Enter the array size:");
    scanf("%d",&n);
    printf("Enter the arrival time and bursttime:");
    for(i=0;i<n;i++)
    {
        printf("\nArrival time:");
        scanf("%d",&at[i]);
        printf("\nBurst time:");
        scanf("%d",&bt[i]);
    }
    wt[0]=0;
    st[0]=0;
    tat[0]=bt[0];
    ttat += tat[0];
    for(i=1;i<n;i++)
    {
        st[i] = st[i-1] + bt[i-1];
        wt[i] = st[i] - at[i];
        tat[i] = wt[i] + bt[i];
        ttat += tat[i];
        twt += wt[i];
    }
    printf("Average waiting time is %f",twt/n);
    printf("Average turn around time is %f",ttat/n);
}