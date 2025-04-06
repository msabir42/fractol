#include "fractol.h"

void putstr(char* s)
{
    int i = 0;
    while(s[i]){
        write(1,&s[i],1);
        i++;
    }
}

int ft_atoi(char *s){
    int i = 0;
    int sign = 1;
    int result;

    while (s[i] == ' ' || s[i] == '\t'  || s[i] == '\v' || s[i] == '\n' || s[i] == '\f' || s[i] == '\r')
        i++;
    if (s[i] == '-' || s[i] == '+'){
        if (s[i] == '-'){
            sign = sign * -1;
            i++;
        }
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9'){
        result = result * 10 + (s[i] - '0');
    }
    return result * sign;
}


void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;
    
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

t_complex init_complex(double real, double imaginary){

    t_complex new;
    new.real = real;
    new.imaginary = imaginary;
    return new;

}

void print_error(){
    putstr("Something is Wrong");
    exit(1);
}