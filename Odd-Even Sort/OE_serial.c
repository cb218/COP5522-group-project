
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

void oe_sort_seq(int *numbers, int array_length) {
    int phase, idx, tmp;
    for (phase = 0; phase < array_length; phase++) {
        if (phase % 2 == 0) {
            for (idx = 1; idx < array_length; idx += 2) {
                if (numbers[idx - 1] > numbers[idx]) {
                    tmp = numbers[idx - 1];
                    numbers[idx - 1] = numbers[idx];
                    numbers[idx] = tmp;
                }
            }
        } else {
            for (idx = 1; idx < array_length - 1; idx += 2) {
                if (numbers[idx] > numbers[idx + 1]) {
                    tmp = numbers[idx + 1];
                    numbers[idx + 1] = numbers[idx];
                    numbers[idx] = tmp;
                }
            }
        }
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
    oe_sort_seq(numbers, array_length);
    gettimeofday(&end, 0);

    long begin_micro_seconds = 1.0e6 * begin.tv_sec + begin.tv_usec;
    long end_micro_microseconds = 1.0e6 * end.tv_sec + end.tv_usec;
    double elapsed_time = end_micro_microseconds - begin_micro_seconds;

    printf("Array Length: %d\tNumber of Cores: %d\tTime measured: %g us\n",
           array_length, num_cores, elapsed_time);

    free(numbers);
}