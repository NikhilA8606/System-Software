#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    FILE *fp;
    int i,j,stadd1;
    char line[50],name1[50],stadd[200];

    fp = fopen("absolute.txt","r");
    fscanf(fp,"%s",line);

    for(i=2,j=0;line[i]!='^';i++,j++)
    {
        name1[j] = line[i];
    }

    name1[j] = '\0';
    
    printf("\nName from Object code is %s\n\n",name1);

    while(!feof(fp))
    {
        fscanf(fp,"%s",line);

        while(line[0]=='T')
        {
            for(i=2,j=0;line[i]!='^';i++,j++)
            {
                stadd[j]=line[i];
            }
            stadd[j] = '\0';
            stadd1 = atoi(stadd);

            i = 12;
            
            while(line[i]!='$')
            {
                if(line[i]!='^')
                {
                    printf("00%d\t%c%c\n",stadd1,line[i],line[i+1]);
                    stadd1++;
                    i += 2;
                }
                else
                {
                    i++;
                }   
            }
            
            fscanf(fp,"%s",line);
        }
        
        if(line[0]=='E')
        {
            fclose(fp);
        }
    }
    
}
