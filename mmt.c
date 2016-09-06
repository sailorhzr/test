#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<unistd.h>
#define MAXLEN 10

int get_char(char *buffer, int maxlen)
{
	char c;
	int len = 0;
	while ((c = getchar()) != '\n')
	{
		buffer[len++]=c;
		if (len >= maxlen)
		{
			break;
		}
	}
	buffer[len] = '\n';
	fflush(stdin);
	return len;
}

int main()
{
	char *i;
	int strlen;
	char buffer[MAXLEN + 1];
	printf ("Do you want malloc how many memory(k,m,g):");
	strlen = get_char(buffer,MAXLEN);
	if (strlen == 0)
		return 0;
	int last_num;
	int memsize;
	char memunit;
	for (int i = 0; i < MAXLEN ; i++)
	{
		if (buffer[i] == '\n')
		{
			last_num = i;
			break;
		}
	}
	for (int j = 0; j < (last_num - 1); j++)
	{
	//	printf ("word %d = %c \n ",j, buffer[j]);
		if ( ! isdigit(buffer[j]))
		{
			printf ("your input memory size error \n");
			return 1;
		}
	}
	char *mem_tmp;
	mem_tmp = buffer;
	memsize = atoi(mem_tmp);
	printf ("mem size= %d \n",memsize);


	memunit = buffer[last_num - 1];
	if (memunit == 'k'||memunit == 'm' || memunit == 'g')
	{
		printf ("mem unit = %c \n",memunit);
	}
	else
	{
		printf ("your input memory unit error \n");
		return 1;
	}

	int malloc_size;

	if (memunit == 'k')
	{
		malloc_size = memsize * 1024;
	}
	if (memunit == 'm')
	{
		malloc_size = memsize * 1024 * 1024;
	}
	if (memunit == 'g')
	{
		malloc_size = memsize * 1024 * 1024 * 1024;
	}
	int *p = NULL;
//	printf ("malloc_size: %d \n", malloc_size);
	p = (int *)malloc(sizeof(int)*malloc_size);
	if (p == NULL)
	{
		printf ("malloc memory error");
		return -1;
	}
	else
	{
		memset(p,0,sizeof(int) * malloc_size);
	}
	printf ("test memory malloc %d %c \n", memsize,memunit);

	printf ("Stop it with \'Enter\'");
	char c;
	while ((c=getchar()) != '\n')
	{
		sleep(5000);
	}

	free(p);
	p = NULL;

	return 0;
}






