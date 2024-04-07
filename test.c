#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
/**
 *main - function to find the factor of numbers stored in a file
 *line by line.
 *@argc : is the number of arguments
 *@argv : is the passed arguments
 *Return: 0 if success
 */
int main(int argc, char **argv)
{
	int o;
	ssize_t read_bytes;
	char buff[1024], *ptr;
	unsigned long long int n, calc;

	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((read_bytes = read(o, buff, sizeof(buff) - 1)) > 0)
	{
		buff[read_bytes] = '\0';
		ptr = buff;
		while (*ptr)
		{
			n = strtoull(ptr, &ptr, 10);
			if (n == 0)
				break;
			for (calc = 2; calc <= n; ++calc)
				if ((n % calc) == 0)
				{
					printf("%llu=%llu*%llu\n", n, calc, n / calc);
					break;
				}
		}
	}
	if (read_bytes == -1)
	{
		perror("Error reading file");
		close(o);
		return (1);
	}
	if (close(o) == -1)
	{
		perror("Error closing file");
		return (1);
	}
	return (0);
}
