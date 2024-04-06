#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>

int main(int argc, char **argv) {
    FILE *fp;
    unsigned long long int n;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(fp, "%llu\n", &n) != EOF) {
        unsigned long long int divisor = n % 2 == 0 ? 2 : 3;
        for (; divisor * divisor <= n; divisor += 2) {
            if (n % divisor == 0) {
                printf("%llu=%llu*%llu\n", n, n / divisor, divisor);
                break;
            }
        }
        // If no divisor was found, the number is prime and we print it multiplied by 1
        if (divisor * divisor > n) {
            printf("%llu=%llu*1\n", n, n);
        }
    }

    fclose(fp);
    return 0;
}
