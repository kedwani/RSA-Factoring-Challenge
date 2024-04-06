#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    unsigned long long quotient;
    unsigned long long remainder;
} DivisionResult;

DivisionResult divideLargeNumber(const char *dividend, unsigned long divisor)
{
    DivisionResult result;
    result.quotient = 0;
    result.remainder = 0;
    unsigned long long tempDividend = 0;
    for (int i = 0; dividend[i] != '\0'; i++)
    {
        tempDividend = tempDividend * 10 + (dividend[i] - '0');
        if (tempDividend >= divisor)
        {
            result.quotient = result.quotient * 10 + (tempDividend / divisor);
            tempDividend = tempDividend % divisor;
        }
        else if (result.quotient > 0)
        {
            result.quotient = result.quotient * 10;
        }
    }
    result.remainder = tempDividend;
    return result;
}
int main(int argc, char **argv)
{
    FILE *file;
    char buff[1024];
    unsigned long long int n, calc;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        perror("Error opening file");
        return 1;
    }

    while (fgets(buff, sizeof(buff), file))
    {
        if (strlen(buff) >= 20)
        {
            divideLargeNumber(buff, i);
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

    if (ferror(file))
    {
        perror("Error reading file");
        fclose(file);
        return 1;
    }

    fclose(file);
    return 0;
}
