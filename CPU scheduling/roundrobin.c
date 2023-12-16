#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n,i,remain,rt[20],at[20],bt[20],tq,tt=0,flag=0;
    float awt=0,atat=0;
    printf("Enter the no of process:");
    scanf("%d",&n);
    remain = n;
    printf("Enter the time quantum:");
    scanf("%d",&tq);
    printf("Enter the arrival time and bursttime:\n");
    for(i=0;i<n;i++)
    {
        printf("Arrival time:");
        scanf("%d",&at[i]);
        printf("Burst time:");
        scanf("%d",&bt[i]);
        rt[i] = bt[i];
    }

    for(i=0;remain!=0;)
    {
        if((rt[i]>0) && (rt[i]<=tq))
        {
            tt += rt[i];
            rt[i] = 0;
            flag = 1;
        }

        else if(rt[i]>0)
        {
            tt += tq;
            rt[i] -= tq;
        }

        if(flag == 1 && rt[i]==0)
        {
            remain--;
            awt += tt - at[i] - bt[i];
            atat += tt - at[i];
            flag = 0;
        }

        if(i == n-1)
        {
            i = 0;
        }
        else if(at[i+1]<=tt)
        {
            i++;
        }
        else
        {
            i = 0;
        }

    }
    printf("\nAverage waiting time:%f",awt/n);
    printf("\nAverage tt time: %f",atat/n);
}