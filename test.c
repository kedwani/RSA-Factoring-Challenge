#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* file;
    char buff[1024];
    unsigned long long int n, calc;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(buff, sizeof(buff), file))
    {
	    if (strlen(buff) >= 20)
	    {
		    continue;
	    }

	    n = strtoull(buff, NULL, 10);
	    for (calc = 2; calc <= n; ++calc)
	    {
		    if ((n % calc) == 0)
		    {
			    printf("%llu=%llu*%llu\n", n, calc, n / calc);
			    break;
		    }
	    }
    }

    if (ferror(file)) {
        perror("Error reading file");
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}
