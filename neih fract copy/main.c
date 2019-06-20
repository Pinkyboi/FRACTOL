/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:58:33 by abenaiss          #+#    #+#             */
/*   Updated: 2019/06/14 15:58:35 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fract.h"
void ft_choose(char *src, t_fract *fract)
{
    if(ft_strcmp(src,"Julia"))
        fract->choose = 1;
    if(ft_strcmp(src,"Mandelbrot"))
        fract->choose = 2;
}
double map(double x, double in_min, double in_max, double out_min, double out_max)
{
    double scope = 1.0 *(out_max - out_min) / (in_max - in_min);
    return (out_min + scope * (x - in_min) );
}
void ft_fract_prep(t_fract *fract, int col, int row)
{
    fract->c_r = (col - WIN_WIDTH/2.0)/200;
    fract->c_i = (row - WIN_HEIGHT/2.0)/200;
    fract->z_r = fract->c_r;
    fract->z_i = fract->c_i;
    fract->it = 0;
    fract->zrsqr = fract->z_r * fract->z_r;
    fract->zisqr = fract->z_i * fract->z_i;
}

double  ft_sqrt2(double n)
{
    return(n*n);
}

void    ft_draw(t_fract *fract)
{
    if(fract->choose == 1)
        ft_mandelbrot(fract);
    else if(fract->choose == 2)
        ft_julia(fract);
    mlx_put_image_to_window(fract->mlx.mlx_ptr, fract->mlx.win, fract->mlx.img.img_ptr, 0, 0);
}
int ft_int_rgb(int r, int g, int b)
{
  int c = r;
  c = (c << 8) | g;
  c = (c << 8) | b;
  return c;
}
void	ft_julia(t_fract *fract)
{
    int row = 0;
    int col = 0;

    while (row < WIN_WIDTH)
    {
        col = 0;
        while(col < WIN_HEIGHT)
        {	ft_fract_prep(fract,col,row);
            while (fract->zrsqr + fract->zisqr<= 4 && fract->it < fract->max_it)
            {
                fract->z_i = fract->z_r*fract->z_i;
                fract->z_i += fract->y1 + fract->z_i;
                fract->z_r = fract->zrsqr - fract->zisqr + fract->x1;
                fract->zrsqr = ft_sqrt2(fract->z_r);
                fract->zisqr = ft_sqrt2(fract->z_i);
                fract->it++;
            }
            if (fract->it != fract->max_it)
                    ft_print(fract,row,col);
            col++;
        }
        row++;
    }

}
void ft_rgb(t_fract *fract)
{
    fract->tab1[0] = abs((fract->color/(256^2) - fract->color1/(256^2)))/50;
    fract->tab1[1] = abs((fract->color/(256) - fract->color1/(256)))/50;
    fract->tab1[2] = abs(fract->color - fract->color1)/50;
}
int    ft_calRGB(t_fract *fract)
{
    ft_rgb(fract);
    int color;
    int tab[50];
    int i = -1;
    while(++i < 50)
        tab[i] = ft_int_rgb(fract->color/(256^2) + (fract->tab1[0]*i),fract->color/256 + (fract->tab1[1]*i),fract->color + (fract->tab1[2]*i));
    color = tab[(50*fract->it%fract->max_it)];
    // ft_putnbr(color);
    return (color);
}
void	ft_mandelbrot(t_fract *fract)
{
    int row = 0;
    int col = 0;

    while (row < WIN_WIDTH)
    {
        col = 0;
        while(col < WIN_HEIGHT)
        {	ft_fract_prep(fract,col,row);
            while (fract->zrsqr + fract->zisqr<= 4 && fract->it < fract->max_it)
            {
                fract->z_i = fract->z_r*fract->z_i;
                fract->z_i += fract->c_i + fract->z_i;
                fract->z_r = fract->zrsqr - fract->zisqr + fract->c_r;
                fract->zrsqr = ft_sqrt2(fract->z_r);
                fract->zisqr = ft_sqrt2(fract->z_i);
                fract->it++;
            }
            // 
            
            if (fract->it != fract->max_it)
                ft_print(fract,row,col);
            col++;
        }
        row++;
    }

}
// int ft_color(t_fract *fract)
// {
//     int color = fract->color;
//     // int color3 = color * color * color;
//     // double t = fract->it*color/fract->max_it;
//     // t = (t * color3);
//     // int b = (t/(color*color));
//     // int nn = t - b * color * color;
//     // int r = nn/color;
//     // int g = nn - r*color;

//     //printf("%f",t);
//     return(ft_rgb(r,g,b));
// }
void ft_print(t_fract *fract, int row, int col)
{
    fract->mlx.img.data[row * WIN_WIDTH+ col] = ft_calRGB(fract);
}
void ft_clear_mlx(t_fract *fract)
{
    int i = -1;

    while(++i < WIN_WIDTH*WIN_HEIGHT)
        fract->mlx.img.data[i] = 0;
}
int ft_mouse_event(int x, int y,t_fract *fract)
{
    ft_clear_mlx(fract);
    if(fract->lock == 0)
    {
        fract->x1 = map(x,100,900,-2,2);
        fract->y1 = map(y,900,100,-2,2);
    }
    ft_draw(fract);
    return(0);
}
int ft_mouse_handel(int keycode,int x,int y,t_fract *fract)
{
    ft_clear_mlx(fract);
    if(keycode == 1)
    {
        if(fract->lock == 1)
            fract->lock = 0;
        else
            fract->lock = 1;
    }
    ft_draw(fract);
    return(0);
}
int ft_key_event(int keycode,t_fract *fract)
{
    ft_clear_mlx(fract);
    if(keycode == 34)
        fract->max_it += 100;
    else if(keycode == 53)
        exit(0);
    ft_draw(fract);
    return(0);
}

void ft_init_win(t_fract fract)
{
    
    fract.max_it = 30;
    fract.x1 =  0.3;
    fract.y1 =  0.5;
    fract.lock = 0;
    fract.mlx.mlx_ptr = mlx_init();
    fract.color = 0xFF0000;
    fract.color1 = 0X0FF000;
    fract.mlx.img.img_ptr = mlx_new_image(fract.mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    fract.mlx.img.data = (int*)mlx_get_data_addr(fract.mlx.img.img_ptr, &fract.mlx.img.bpp, &fract.mlx.img.size_l, &fract.mlx.img.endian);
    fract.mlx.win = mlx_new_window(fract.mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "WOLF" );
    mlx_put_image_to_window(fract.mlx.mlx_ptr, fract.mlx.win, fract.mlx.img.img_ptr, 0, 0);
    mlx_hook(fract.mlx.win, 6, 1, (*ft_mouse_event), &fract);
    mlx_hook(fract.mlx.win,2,1,(*ft_key_event), &fract);
    mlx_mouse_hook(fract.mlx.win,(*ft_mouse_handel), &fract);
    ft_draw(&fract);
    // line(WIN_WIDTH/2, 0, WIN_WIDTH/2, WIN_HEIGHT,fract);
    // line(300, 0, 300, WIN_HEIGHT,fract);
    // line( 0,WIN_HEIGHT/2,WIN_WIDTH,WIN_HEIGHT/2,fract);
    mlx_loop(fract.mlx.mlx_ptr);
}

int main(int argc, char **argv)
{
    t_fract fract;
    if(argc > 1)
        ft_choose(argv[1],&fract);
    if(!fract.choose)
    {
        ft_putendl("usage : \"./Fract'ol \"\nchoose an available Fractal:\n-Julia\n-Mandelbrot");
            exit(0);
    }
    
    else
        ft_init_win(fract);
    return(0);
}