#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int argc, char** argv)
{
	int o, c;
	unsigned long int n, calc;
	char buff[1024];

	if (argc != 2)
	{
		printf("please enter the file name \n");
		exit (1);
	}
	if ((o = open(argv[1], O_RDONLY)) == -1)
		exit (1);

	while (read(o, buff, 1024))
	{
		printf("inside while loop\n");
		n = atoi(buff);
		for (calc = 2;;++calc)
			if ((n % calc) == 0)
			{
				printf("%lu=%lu*%lu\n", n, calc,n/calc);
				break;
			}
	}
	if ((c = close(o)) == -1)
		exit (1);
}
