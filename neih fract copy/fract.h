/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:58:21 by abenaiss          #+#    #+#             */
/*   Updated: 2019/06/14 15:58:23 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACT_H
# define FRACT_H

# include <math.h>
# include <mlx.h>
#include <stdlib.h>
#include <math.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <stdio.h>


# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

typedef struct	s_coor
{
	int x;
	int	y;
	int z;
	int	rgb;
}				t_coor;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data; //Here you got an int * even though mlx_get_data_addr returns
						//a char *, i'll talk more about this in the .c file.
//Here are the 3 "useless" variables. You can find more informations about these in the man page.
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;

typedef struct	s_fract
{
	int 		it;
	float	   tab1[3];
	int			r;
	int			g;
	int			b;
	int			x;
	int			y;
    int 		choose;
	int		max_it;
	double		x1;
	double		y1;
	int			lock;
	long double c_r;
    long double c_i;
    long double z_r;
    long double z_i;
    long double zrsqr;
    long double zisqr;
	int			color;
	int			color1;
	t_mlx		mlx;
}				t_fract;

void	ft_print(t_fract *fract, int row, int col);
void	ft_choose(char *src, t_fract *fract);
void 	ft_fract_prep(t_fract *fract, int col, int row);
double	ft_sqrt2(double n);
void	ft_mandelbrot(t_fract *fract);
void	ft_print(t_fract *fract, int row, int col);
int		ft_mouse_event(int x, int y,t_fract *fract);
int		ft_key_event(int keycode,t_fract *fract);
void	ft_init_win(t_fract fract);
void	ft_julia(t_fract *fract);
int		ft_mouse_handel(int keycode,int x,int y,t_fract *fract);
int		ft_int_rgb(int r, int g, int b);
int		ft_color(t_fract *fract);
void	ft_clear_mlx(t_fract *fract);
#endif