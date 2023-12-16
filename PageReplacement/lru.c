#include <stdio.h>

void main()
{
    int pn,pages[50],fn,frames[50],fpos=0,i,j,k,least[30],fcount=0,flag,pos,time[30],counter=0;
    printf("Enter the total no of pages:\n");
    scanf("%d",&pn);
    printf("Enter the string:\n");
    for(i=0;i<pn;i++)
    {
        scanf("%d",&pages[i]);
    }
    printf("Enter the frame size:\n");
    scanf("%d",&fn);
    for(i=0;i<fn;i++)
    {
        frames[i]=-1;
    }
    printf("Pages\tFrames\n");
    for(i=0;i<pn;i++)
    {
        flag = 0;
        for(j=0;j<fn;j++)
        {
            if(frames[j]==pages[i])
            {
                flag = 1;
                counter++;
                time[j]=counter;
                break;
            }
        }
        if(flag==0)
        {
            if(fpos<fn)
            {
                counter++;
                time[fpos]=counter;
                frames[fpos]=pages[i];
                fpos++;
            }
            else
            {
                counter++;
                pos = 0;
                for(j=0;j<fn;j++)
                {
                    if(time[j]<time[pos])
                    {
                        pos = j;
                    }
                }
                frames[pos] = pages[i];
                time[pos] = counter;
            }
        }
        printf("%d\t",pages[i]);
        if(flag==1)
        {
            printf("\t\tPAGE HIT\n");
        }
        else
        {
            for(j=0;j<fn;j++)
            {
                printf("%d\t",frames[j]);
            }
            fcount ++;
            printf("\n");
        }
    }
    printf("\nThe total page fault : %d",fcount);
}