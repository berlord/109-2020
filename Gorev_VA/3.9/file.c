#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int INCLUDE(char *progname);
int INCLUDE(char *progname)
{
	FILE *proglen;
	FILE *progchar;
	char c = 'A';
	char *A;
	int len;
	int Eof = 0, Ind = 0;
	if ((progchar = fopen(progname, "r")) == NULL)
	{
		printf("INCLUDE(%s): Can't open file \"%s\"\n", progname, progname);
		return -1;
	}
	if ((proglen = fopen(progname, "r")) == NULL)
	{
		fclose(progchar);
		printf("INCLUDE(%s): Can't open file \"%s\"\n", progname, progname);
		return -1;
	}
	len = 0;
	while(!Eof)
	{
		if (fscanf(proglen, "%c", &c) != 1)
			Eof = 1;
		else
			if (c != '\r')
				len++;
		if ((c == '\n') || Eof)
		{
			int i = 0;
			A = (char*)malloc((len + 1) * sizeof(char));
			while (i < len)
			{
				fscanf(progchar,"%c", &c);
				if (c != '\r')
				{
					A[i] = c;
					i++;
				}
			}
			A[len] = 0;
			if (strstr(A, "#include ") == A)
			{
				if (A[len - 1] == '\n')
				{
					A[len - 1] = 0;
					Ind = 1;
				}
				else
					Ind = 0;
				if (strcmp(A + strlen("#include "), progname) == 0)
				{
					printf("INCLUDE(%s): Loop output: \"#include %s\" in the file \"%s\"\n", progname, progname, progname);
					fclose(proglen);
					fclose(progchar);
					free(A);
					return -2;
				}
				else
				{
					if (INCLUDE(A + strlen("#include ")))
						return -3;
					if (Ind)
						printf("\n");
				}
			}
			else
				printf("%s", A);
			free(A);
			len = 0;
		}
	}
	
	fclose(progchar);
	fclose(proglen);
	return 0;
}

int main(void)
{
	char *progname = "programm.txt";
	if (INCLUDE(progname))
		printf("ERROR\n");
	return 0;
}

