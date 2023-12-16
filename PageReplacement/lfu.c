#include <stdio.h>

void main()
{
    int pn,pages[50],fn,frames[50],fpos=0,i,j,k,least[30],fcount=0,flag,pos,count[20];
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
                count[j]++;
                break;
            }
        }
        if(flag==0)
        {
            if(fpos<fn)
            {
                frames[fpos]=pages[i];
                count[frames[fpos]]++;
                fpos++;
            }
            else
            {
                pos = 0;
                for(j=1;j<fn;j++)
                {
                    if(count[j]<count[pos])
                    {
                        pos = j;
                    }
                }
                frames[pos] = pages[i];
                count[pos] = 1;
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