
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {

    // Determine matrix size (3D cube: (max_iters * row_size * col_size))
    int row_size, col_size, max_iters;
    row_size = atoi(argv[2]);
    max_iters = col_size = row_size;

    // Verify command line arguments are valid
    if (argc != 2) {
        fprintf(stderr, "USAGE: %s Dimension Size\n", argv[0]);
        exit(1);
    } else if (argv[1] <= 0) {
        fprintf(stderr, "USAGE: Please specify a dimension size larger than 0\n", argv[0]);
        exit(1);
    }

    // Initialize Diffusivity, Step Value (delta_step), and Gamma Value
    // Diffusivity is somewhat arbitrary but Step Value is not
    // Diffusivity and Step Value determine gamma
    double diff_value, gamma_value, delta_time;
    int delta_step;
    diff_value = 2.0;
    delta_step = 1;

    // These formulas are not arbitrary, see python implementation link in discord group chat
    delta_time = pow(delta_step, 2) / (diff_value * 4);
    gamma_value = (diff_value * delta_time) / pow(delta_step, 2);

    // Define boundary temps
    double left_border_temp, right_border_temp, top_border_temp, bottom_border_temp;
    left_border_temp = right_border_temp = top_border_temp = bottom_border_temp = 0.0;

    // TODO: Define initial temp at each index "0"
    // TODO: Initialize 3d array (on heap)
    // TODO: Calculate final "U" value


//    int max_iters;
//
//    max_iters = atoi(argv[1])
//

//
//



}