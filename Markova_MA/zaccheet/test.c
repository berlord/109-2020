#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "f.h"
char pol (char *str);
int eq (char *a, char *b);


int main() {
	char *str, ***a;
	int len, i, j, check = -1, ii = -1, jj = -1, res = SUCCESS;
	FILE *inp, *outp;
    if ((inp = fopen("input.txt", "r")) == NULL) {
        printf("ERROR\n");
        return 0;
    }
    if ((outp = fopen("result.txt", "w")) == NULL) {
        printf("ERROR\n");
        fclose(inp);
        return 0;
    }
	if (fscanf(inp, "%d", n) != 1 || fscanf(inp, "%d", m) != 1)
        {
            fclose(inp);
			fclose(outp);
			
            return 0;
        }
	a_read(inp, a);
	//здесь кончается считывание
	
	for(i = 0;i < n; i++)
	{
		for(j = 0;j < m;j++)
		{
			if(a[i][j] == '\n')
			{
				check = 1;
			}
			str = pol(a[i][j]);
			for(int k = j + 1;k < m - 1;k++)
			{
				if(eq(str, a[i][k]))
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
	for(i = 0;i < n;i++)
	{
		for(j = 0; j < m; j++)
		{
			if(ii != i && j == jj && a[ii][jj] != '\n')
			{
				printf(outp, "%s%s\n", a[i][j], a[ii][jj])
			}
			else
				printf(outp, "%s\n", a[i][j]);
		}
	}
	fclose(outp);
	for (i = 0; i < n;i++)
        {
          for (int j = 0; j < m; j++)
          {
            free(a[i][j]);
          }
          free(a[i]);
        }
    free (a);
	return 0;
}