#include <stdlib.h>
#include <stdio.h>


int main(void)
{
	int i,j,n,m,len = 32;
    char ***a;
    char buf[len];
    FILE *fp;
    scanf("%d %d", &m, &n);
    fp = fopen("input.txt", "r");
    if (!fp)
    {
    	return -1;
    }
    //make memory
    a = (char ***)malloc(m*sizeof(char **));
    if (!a)
    {
    	fclose(fp);
    	return -1;
    }
    for (i = 0; i < m; i++)
    {
    	a[i] = (char **)malloc(n*sizeof(char *));
    	if (!a[i])
    	{
    		fclose (fp);
    		for (j = 0; j < i; j++)
    			free(a[j]);
    		free(a);
    		return -1;
    	}
    }
    //input
    for (i = 0; i < m; i++)
    {
    	for (j = 0; j < n; j++)
    	{
    	    int q,p;
    	    if (!fgets(buf,len,fp))
            {
				//error
                return -1;
            }
            for (q = 0; buf[q]; q++)
            {
                if (buf[q] == '\n')
                {
                    buf[q] = '\0';
                    break;
                }
            }
            a[i][j] = (char *)malloc(q+1);
            if (!a[i][j])
            {
				//error
                return -1;
            }
            for (p = 0; p <= q; p++)
                a[i][j][p] = buf[p];
    	}
    }
	
	//здесь кончаетя считывание
	
	for(i = 0;i < m; i++)
	{
		for(j = 0;j < n;j++)
		{
			if(slen(a[i][j]) == 0)
			{
				check = 1;
				break;
			}
			//str = cop(pol(a[i][j]), str);
			for(int k = j + 1;k < m - 1;k++)
			{
				if(eq(pol(a[i][j]), a[i][k]))
				{
					ii = i;
					jj = j;
					check = 1;
					break;
				}
			}
			if(check)
				break;
		}
	}
	for(i = 0;i < m;i++)
	{
		for(j = 0; j < n; j++)
		{
			if(ii != i && j == jj && strlen(a[ii][jj]) != 0)
			{
				fprintf(outp, "%s%s\n", a[i][j], a[ii][jj]);
			}
			else
				fprintf(outp, "%s\n", a[i][j]);
		}
	}
    //cleaning of memory

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            free(a[i][j]);
        }
    	free(a[i]);
    }
    free(a);
    fclose(fp);


    return 0;
}
