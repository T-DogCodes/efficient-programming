/* Ramanujan numbers are numbers that can be formed by adding two
   cubes of integer numbers in two (or more) different ways, i.e.
   i^3+j^3 = k^3+l^3
   See <http://www.durangobill.com/Ramanujan.html>

   This program counts the Ramanujan numbers up to a given
*/

#include <assert.h>
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry {
    long value;
};

int comp_entry(const void *p1, const void *p2) {
    const struct entry *e1 = p1;
    const struct entry *e2 = p2;
    if (e1->value < e2->value)
        return -1;
    else
        return e1->value > e2->value;
}

long cube(long n) {
    return n * n * n;
}

size_t size_table(long n)
/* compute a table size that is large enough to keep all I^3+J^3<n */
{
    return exp(log((double)n) * (2.0 / 3.0)) / 2 + 100;
}

int main(int argc, char **argv) {
    long maximum_number;
    char *endptr;

    long i, j;
    long m = 0;

    // cubes array
    struct entry *slice_table;
    size_t slice_table_size;
    size_t table_size = 0;

    // result variables
    long count = 0;
    long checksum = 0;

    // USAGE & Argument Parsing
    if (argc != 2) {
        goto usage;
    }
    maximum_number = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0') {
        goto usage;
    }

    // Program Start

    long slice_min, slice_max;
    for (slice_min = 0; slice_min < maximum_number; slice_min = slice_max) {
        slice_max = slice_min + 100000;

        m = 0;
        slice_table_size = size_table(slice_max) - size_table(slice_min) + 100;
        slice_table = calloc(slice_table_size, sizeof(struct entry));

        if (slice_table_size > table_size) {
            table_size = slice_table_size;
        }

        for (i = 0; cube(i) <= slice_max; i++) {
            for (j = i + 1; cube(i) + cube(j) <= slice_max; j++) {
                if (cube(i) + cube(j) > slice_min) {
                    slice_table[m++] = (struct entry){cube(i) + cube(j)};
                }
            }
        }

        assert(m <= slice_table_size);
        qsort(slice_table, m, sizeof(struct entry), comp_entry);
        for (i = 1; i < m; i++) {
            if (slice_table[i - 1].value == slice_table[i].value) {
                count++;
                checksum += slice_table[i].value;
                while (i < m - 1 && slice_table[i].value == slice_table[i + 1].value) {
                    i++;
                }
            }
        }
        free(slice_table);
    }
    // Printing
    printf("%ld Ramanujan numbers up to %ld, checksum=%ld\noccupation=%ld, size=%ld\n", count, maximum_number, checksum, m, table_size);
    printf("Memory usage: >=%ld\n", table_size * sizeof(struct entry));
    return 0;

usage:
    fprintf(stderr, "usage: %s <n>\n", argv[0]);
    exit(1);
}
