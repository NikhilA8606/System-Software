#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n,diskQue[50],diff,seektime,i;
    printf("Enter the size:");
    scanf("%d",&n);
    printf("Enter the head:");
    scanf("%d",&diskQue[0]);
    printf("Enter the Queue:");
    for(i=1;i<n;i++)
    {
        scanf("%d",&diskQue[i]);
    }
    for(i=0;i<n-1;i++)
    {
        diff = abs(diskQue[i+1]-diskQue[i]);
        seektime += diff;
        printf("%d -> %d : %d\n",diskQue[i],diskQue[i+1],diff);
    }

    printf("\nTotal Seektime:%d",seektime);

}