#include <stdio.h>
void main()
{
    int i,j,pages[100],frames[100],pn,fn,flag,fpos=0,fcount=0;
    printf("Enter the no of pages:");
    scanf("%d",&pn);
    printf("\nEnter the pages:");
    for(i=0;i<pn;i++)
    {
        scanf("%d",&pages[i]);
    }
    printf("\nEnter the no of frames:");
    scanf("%d",&fn);

    for(j=0;j<fn;j++)
    {
        frames[j]=-1;
    }
    printf("\nPages\t\tFrames\n");
    for(i=0;i<pn;i++)
    {
        flag = 0;
        for(j=0;j<fn;j++)
        {
            if(frames[j]==pages[i])
            {
                flag = 1;
                break;
            }
        }

        if(!flag)
        {
            frames[fpos]=pages[i];
            fpos=(fpos+1)%fn;
            fcount++;
        }
        if(flag)
        {
            printf("Page hit\n");
        }
        else
        {
            for(j=0;j<fn;j++)
            {
                printf("%d\t",frames[j]);
                
            }
            printf("\n");
        }
    }
    printf("Page fault:%d",fcount);
}