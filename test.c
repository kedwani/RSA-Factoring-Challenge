#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long find_factor(unsigned long long n) {
    // Optimized factor finding
    if (n % 2 == 0) return 2;
    for (unsigned long long i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return i;
    }
    return n; // n is prime
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: factors <file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    unsigned long long n;
    while (fscanf(file, "%llu", &n) != EOF) {
        unsigned long long factor = find_factor(n);
        printf("%llu=%llu*%llu\n", n, n / factor, factor);
    }

    fclose(file);
    return 0;
}
