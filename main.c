
#include "fractol.h"


int main(int argc, char **argv) {
    t_fractal *fract;
    
    if (argc < 2) {
        printf("Usage: ./fractol Mandelbrot\n");
        printf("       ./fractol Julia [c_real] [c_imag]\n");
        return (1);
    }
    
    fract = malloc(sizeof(t_fractal));
    if (!fract) {
        printf("Memory allocation failed\n");
        return (1);
    }
    
    if (strcmp(argv[1], "Mandelbrot") == 0) {
        t_complex c;
        c.real = 0;
        c.imaginary = 0;
        init_mandelbrot(fract);
        printf("%d\n", mandelbrot_iterations(&c));
    }
    else if (strcmp(argv[1], "Julia") == 0) {
        if (argc != 4) {
            printf("Julia fractal requires c_real and c_imag parameters.\n");
            printf("Usage: ./fractol Julia [c_real] [c_imag]\n");
            free(fract);
            return (1);
        }
        
        t_julia julia;
        double c_real = atof(argv[2]);
        double c_imag = atof(argv[3]);
        init_julia(&julia, c_real, c_imag);
    }
    else {
        printf("Invalid fractal type. Choose Mandelbrot or Julia.\n");
        free(fract);
        return (1);
    }
    
    return (0);
}
