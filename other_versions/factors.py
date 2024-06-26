#!/usr/bin/env python3
import math

def find_factor(n):
    """Find a factor of n, preferring smaller factors."""
    if n % 2 == 0:
        return 2
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return i
    return n

def factorize_file(filename):
    """Read numbers from a file and print a factorization for each."""
    with open(filename, 'r') as file:
        for line in file:
            n = int(line.strip())
            factor = find_factor(n)
            print(f"{n}={n // factor}*{factor}")

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 2:
        print("Usage: python factors.py <file>")
        sys.exit(1)
    factorize_file(sys.argv[1])
