
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct bucket {
    int count;
    int *value;
};

int compareIntegers(const void *first, const void *second) {
    int x = *((int *) first), y = *((int *) second);
    if (x == y) {
        return 0;
    } else if (x < y) {
        return -1;
    } else {
        return 1;
    }
}

void bucketSort(int *array, int n) {
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++) {
        buckets[i].count = 0;
        buckets[i].value = (int *) malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++) {
        if (array[i] < 0) {
            buckets[0].value[buckets[0].count++] = array[i];
        } else if (array[i] > 10) {
            buckets[2].value[buckets[2].count++] = array[i];
        } else {
            buckets[1].value[buckets[1].count++] = array[i];
        }
    }

    for (k = 0, i = 0; i < 3; i++) {
        // now using quicksort to sort the elements of buckets
        qsort(buckets[i].value, buckets[i].count, sizeof(int), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++) {
            array[k + j] = buckets[i].value[j];
        }
        k += buckets[i].count;
        free(buckets[i].value);
    }
}


void init_array(int *numbers, int array_length) {
    for (int idx = 0; idx < array_length; idx++) {
        numbers[idx] = rand() % array_length;
    }
}

void print_array(int *numbers, int array_length) {
    for (int idx = 0; idx < array_length; idx++) {
        printf("%d ", numbers[idx]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    int array_length;
    int num_cores;
    int *numbers;

    if (argc != 3) {
        fprintf(stderr, "USAGE: %s Array_Length Num_cores\n", argv[0]);
        exit(1);
    }

    array_length = atoi(argv[1]);
    num_cores = atoi(argv[2]);

    numbers = malloc(array_length * sizeof(int));
    init_array(numbers, array_length);

    struct timeval begin, end;

    gettimeofday(&begin, 0);
    bucketSort(numbers, array_length);
    gettimeofday(&end, 0);

    long begin_micro_seconds = 1.0e6 * begin.tv_sec + begin.tv_usec;
    long end_micro_microseconds = 1.0e6 * end.tv_sec + end.tv_usec;
    double elapsed_time = end_micro_microseconds - begin_micro_seconds;

    printf("Array Length: %d\tNumber of Cores: %d\tTime measured: %g us\n",
           array_length, num_cores, elapsed_time);

    free(numbers);
}