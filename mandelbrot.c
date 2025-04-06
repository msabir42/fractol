#include "fractol.h"

int mandelbrot_iterations(t_complex* c)
{
    t_complex z = init_complex(0, 0);
    int iter = 0;
    
    while (iter < MAX_ITERATIONS)
    {
        double z_real_squared = z.real * z.real;
        double z_imag_squared = z.imaginary * z.imaginary;
        
        if (z_real_squared + z_imag_squared > 4.0)
            break; 
        
        double temp_real = z_real_squared - z_imag_squared + c->real;
        z.imaginary = 2 * z.real * z.imaginary + c->imaginary;
        z.real = temp_real;
        
        iter++;
    }
    return iter;
}
int get_color(int iterations, int max_iterations) {
    if (iterations == max_iterations)
        return 0x000000;
    double t = (double)iterations / max_iterations;
    
    int r = (int)(9 * (1 - t) * t * t * t * 255);
    int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
    
    return (r << 16) | (g << 8) | b;
}


void render_mandelbrot(t_fractal *fract)
{
    t_data img;
    int x, y;
    t_complex c;
    int color;
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            c.real = plane_x(x,WIDTH);
            c.imaginary =plane_y(y,HEIGHT);
            int iterations = mandelbrot_iterations(&c);
            if (iterations == MAX_ITERATIONS)
                color = 0x000000;
            else
                color = 0x0000FF * iterations / MAX_ITERATIONS; 
            my_mlx_pixel_put(&fract->data, x, y, get_color(iterations,MAX_ITERATIONS));
        }
    }
    mlx_put_image_to_window(fract->mlx, fract->w, fract->data.img,0, 0);
}

void init_mandelbrot(t_fractal *fract)
{
    fract->mlx = mlx_init();
    if (fract->mlx == NULL)
    {
        free(fract->mlx);
        print_error();   
    }
    fract->w = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "Mandelbrot");
    if (fract->w == NULL){
        mlx_destroy_display(fract->mlx);
        free(fract->mlx);
        print_error();
    }
    fract->data.img = mlx_new_image(fract->mlx,WIDTH,HEIGHT);
    if(fract->data.img == NULL){
        mlx_destroy_window(fract->mlx,fract->w);
        mlx_destroy_display(fract->mlx);
        free(fract->mlx);
        print_error();
    }
    fract->data.addr = mlx_get_data_addr(fract->data.img,&fract->data.bits_per_pixel,&fract->data.line_length,&fract->data.endian);
    render_mandelbrot(fract);
    mlx_key_hook(fract->w, close_key, fract);
    mlx_loop(fract->mlx);
}