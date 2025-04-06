#include "fractol.h"

void init_julia(t_julia *julia, double c_real, double c_imag)
{
    julia->mlx = mlx_init();
    if (julia->mlx == NULL)
        print_error();

    julia->w = mlx_new_window(julia->mlx, WIDTH, HEIGHT, "Julia");
    if (julia->w == NULL)
    {
        mlx_destroy_display(julia->mlx);
        free(julia->mlx);
        print_error();
    }

    julia->data.img = mlx_new_image(julia->mlx, WIDTH, HEIGHT);
    if (julia->data.img == NULL)
    {
        mlx_destroy_window(julia->mlx, julia->w);
        mlx_destroy_display(julia->mlx);
        free(julia->mlx);
        print_error();
    }

    julia->data.addr = mlx_get_data_addr(julia->data.img,&julia->data.bits_per_pixel,&julia->data.line_length,&julia->data.endian);

    julia->c.real = c_real;
    julia->c.imaginary = c_imag;

    render_julia(julia);
    mlx_key_hook(julia->w, close_key_julia, julia); 
    mlx_loop(julia->mlx);
}
int julia_iterations(t_complex point, t_complex c) {
    t_complex z = point;  
    int iter = 0;
    
    while (iter < MAX_ITERATIONS) {
        double z_real_squared = z.real * z.real;
        double z_imag_squared = z.imaginary * z.imaginary;
        
        if (z_real_squared + z_imag_squared > 4.0)  
            break;
        
        double new_real = z_real_squared - z_imag_squared + c.real;
        double new_imaginary = 2 * z.real * z.imaginary + c.imaginary;
        
        z.real = new_real;
        z.imaginary = new_imaginary;
        
        iter++;
    }
    
    return iter;
}


void render_julia(t_julia *julia)
{
    int x, y;
    t_complex point;
    int color;
    
    t_complex c = julia->c;
    
    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            point.real = plane_x(x, WIDTH);
            point.imaginary = plane_y(y, HEIGHT);
            
            int iterations = julia_iterations(point, c);
            
            color = get_color(iterations, MAX_ITERATIONS);
            my_mlx_pixel_put(&julia->data, x, y, color);
        }
    }
    mlx_put_image_to_window(julia->mlx, julia->w, julia->data.img, 0, 0);
}