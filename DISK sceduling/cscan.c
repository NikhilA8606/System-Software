#include <stdio.h>
#include <stdlib.h>

void sort(int[],int);
void cscan(int[],int,int);

void main()
{
    int n,diskQue[20],head,i;
    printf("Enter the size:");
    scanf("%d",&n);
    printf("Enter the head:");
    scanf("%d",&head);
    diskQue[0]=head;
    printf("Enter the Queue:");
    for(i=1;i<n;i++)
    {
        scanf("%d",&diskQue[i]);
    }
    diskQue[n++]=199;
    diskQue[n++]=0;
    sort(diskQue,n);
    cscan(diskQue,head,n);
}

void sort(int diskQue[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(diskQue[j]>diskQue[j+1])
            {
                temp = diskQue[j];
                diskQue[j]=diskQue[j+1];
                diskQue[j+1]=temp;
            }
        }
    }
}

void cscan(int diskQue[],int head,int n)
{
    int pos,i,curr,diff,seektime=0;
    for(i=0;i<n;i++)
    {
        if(diskQue[i]==head)
        {
            pos = i;
            break;
        }
    }

    for(i=pos;i<n-1;i++)
    {
        diff = abs(diskQue[i+1]-diskQue[i]);
        seektime += diff;
        printf("%d -> %d : %d\n",diskQue[i],diskQue[i+1],diff);
    }
    curr = n-1;
    for(i=0;i<pos;i++)
    {
        diff = abs(diskQue[curr]-diskQue[i]);
        seektime += diff;
        printf("%d -> %d : %d\n",diskQue[curr],diskQue[i],diff);
        curr = i;
    }
    printf("Total Seektime : %d",seektime);
}