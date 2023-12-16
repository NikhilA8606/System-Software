#include <stdio.h>
void main()
{
    int n,at[20],bt[20],wt[20],st[20],tat[20],i,temp;
    float ttat,twt;
    printf("Enter the no of process:");
    scanf("%d",&n);
    printf("Enter the arrival time and bursttime:\n");
    for(i=0;i<n;i++)
    {
        printf("Arrival time:");
        scanf("%d",&at[i]);
        printf("Burst time:");
        scanf("%d",&bt[i]);
    }

    for(i=0;i<n;i++)
    {
        if(bt[i+1]<bt[i])
        {
            temp = bt[i];
            bt[i] = bt[i+1];
            bt[i+1] = temp;
        }
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

    printf("\nAverage waiting time:%f",twt/n);
    printf("\nAverage turnaround time:%f\n",ttat/n);
}