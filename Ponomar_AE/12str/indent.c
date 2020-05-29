#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "indent.h"

void indent(FILE *input, FILE *output, int max_len)
{
	char *buf;
	int ind = 0, start, calc = 0, size_buffer, check_sp; 	

	while((buf = read_string(input)) != NULL)
	{
		if ((int)(buf[0]) == '\n')
		{
			ind = 1;
			calc = 0;
		}

		else
		{
			if (ind == 1)
			{
				fprintf(output, "\n    ");
				ind = 0;
				calc = 4;
			}
			size_buffer = (int)(strlen(buf));

			for (int i = 0; i < size_buffer; i++)
			{
				calc++;
				start = i;
				check_sp = 1;

				while (buf[i] != ' ' && buf[i] != '\n' && buf[i] != 0)
				{
					i++;
					calc++;
				}

				if (calc <= max_len)
				{
					for (int j = start; j < i; j++)
					{

							fprintf(output, "%c", buf[j]);
						
					}
					fprintf(output, " ");
				}

				else 
				{
					fprintf(output, "\n");
					i = start - 1;
					calc = 0;
				}
			}	
		}
		free(buf);
	}

	if(!feof(input))
	{
		fclose(input);
		fclose(output);
		free(buf);
		printf("ERROR indenting");
	}

	fclose(input);
	fclose(output);
	free(buf);
}


char *read_string(FILE *input)
{
	char buf[1024];
	char *s = malloc(1025), *result = malloc (1);
	buf[0] = 0;
	s = fgets(buf, 1024, input);

	if(s)
	{
		int len = strlen(s);
		result = (char *)malloc((len + 1)*sizeof(char));
		strcpy(result, s);

		if (len < 1023) 
		{
			return result;
		}

		while((s) && (s[strlen(s) - 1] != '\n'))
		{
			s = fgets(buf, 1024, input);
			len += strlen(s);

			result = (char *)realloc(result, len);
			strcat(result, s);		
		}

		free(s);
		return result;
	}

	free(s);
	free(result);
	return NULL;
}