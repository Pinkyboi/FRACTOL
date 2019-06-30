/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 18:26:33 by abenaiss          #+#    #+#             */
/*   Updated: 2019/06/30 10:33:25 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_clear_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img.img_ptr);
	mlx_clear_window(mlx->mlx_ptr, mlx->win);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img.data = (int*)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
	&mlx->img.size_l, &mlx->img.endian);
}

int		ft_mouse_event(int x, int y, t_fract *fract)
{
	ft_clear_mlx(&fract->mlx);
	if (fract->lock == 0)
	{
		fract->x1 = ft_map(x, 0, fract->win_w);
		fract->y1 = ft_map(y, fract->win_h, 0);
	}
	ft_draw(fract);
	ft_print_panel(*fract);
	return (0);
}

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	ft_zoom(t_fract *fract)
{
	double interpolation;

	interpolation = 1.0 / fract->zoom.zoom;
	fract->zoom.rmin = interpolate(fract->zoom.mousere, fract->zoom.rmin,
	interpolation);
	fract->zoom.imin = interpolate(fract->zoom.mouseim, fract->zoom.imin,
	interpolation);
	fract->zoom.rmax = interpolate(fract->zoom.mousere, fract->zoom.rmax,
	interpolation);
	fract->zoom.imax = interpolate(fract->zoom.mouseim, fract->zoom.imax,
	interpolation);
}

void	ft_pos_zoom(t_fract *fract, double x, double y)
{
	fract->zoom.mousere = (double)x / (fract->win_w / (fract->zoom.rmax - 
	fract->zoom.rmin)) + fract->zoom.rmin;
	fract->zoom.mouseim = (double)y/(fract->win_h / (fract->zoom.imax - 
	fract->zoom.imin)) + fract->zoom.imin;
	ft_zoom(fract);
}
void	ft_info_win2(t_fract fract2)
{
	mlx_string_put(fract2.mlx.mlx_ptr, fract2.mlx.win, 10, 170, 0xFFFFFF,
	"|MOVE THE FRACTAL :(DIRECTIONAL ARROWS)        |");
	mlx_string_put(fract2.mlx.mlx_ptr, fract2.mlx.win, 10, 200, 0xFFFFFF,
	"|EXIT THE PROGRAM : (THE x BUTTON)             |");
	mlx_string_put(fract2.mlx.mlx_ptr, fract2.mlx.win, 10, 230, 0xFFFFFF,
	"|CONTROL THE ZOOM :(SCROLL UP/DOWN)            |");
	mlx_string_put(fract2.mlx.mlx_ptr, fract2.mlx.win, 10, 260, 0xFFFFFF,
	"|LOCK FRACTALS VARIABLES :(L)                  |");
	mlx_string_put(fract2.mlx.mlx_ptr, fract2.mlx.win, 10, 290, 0xFFFFFF,
	"|INTERACT WITH THE INTERFACE :(LEFT CLICK)     |");
	mlx_string_put(fract2.mlx.mlx_ptr, fract2.mlx.win, -5, 320, 0xFFFFFF,
	" -------------------------------------------------");
}
void	ft_info_win1(void)
{
	t_fract fract2;

	fract2.mlx.mlx_ptr = mlx_init();
	fract2.mlx.win = mlx_new_window(fract2.mlx.mlx_ptr, 500, 350, "Man" );
	mlx_string_put(fract2.mlx.mlx_ptr, fract2.mlx.win, 10, 10, 0xFFFFFF,
	" any additional information you may need :");
	mlx_string_put(fract2.mlx.mlx_ptr, fract2.mlx.win, -5, 25, 0xFFFFFF,
	" -------------------------------------------------");
	mlx_string_put(fract2.mlx.mlx_ptr, fract2.mlx.win, 10, 50, 0xFFFFFF,
	"|ADD ITERATION :(PAGE UP/DOWN)                 |");
	mlx_string_put(fract2.mlx.mlx_ptr, fract2.mlx.win, 10, 80, 0xFFFFFF,
	"|CHANGE THE POWER OF MULTIBRIOT :(+/-)         |");
	mlx_string_put(fract2.mlx.mlx_ptr, fract2.mlx.win, 10, 110, 0xFFFFFF,
	"|RESTORE THE DEFAULT FRACTAL :(SPACE)          |");
	mlx_string_put(fract2.mlx.mlx_ptr, fract2.mlx.win, 10, 140, 0xFFFFFF,
	"|CHANGE COLORS MANUALLY :(R/G/B)               |");
	ft_info_win2(fract2);
	mlx_loop(fract2.mlx.mlx_ptr);
}

int		ft_exit(t_fract *fract)
{
	(void)fract;
	exit (0);
}

void	ft_right_event(t_fract *fract, int x, int y)
{
	if (y >= 700 && y <= 725)
	{
		if (x >= 40 && x <= 65)
			fract->rgb = 1;
		if (x >= 70 && x <= 95)
			fract->rgb = 2;
		if (x >= 100 && x <= 125)
			fract->rgb = 3;
	}
	if (y >= 400 && y <= 425)
	{
		if (x >= 15 && x <= 30 && fract->choose > 1)
			fract->choose--;
		if (x >= 760 && x <= 785 && fract->choose < 6)
			fract->choose++;
		ft_rezeo(fract);
	}
	if (y >= 0 && y <= 25 && x >= fract->win_h - 25 && x <= fract->win_h)
		ft_info_win1();
	ft_draw(fract);
	ft_print_panel(*fract);
}

int		ft_mouse_handel(int keycode, int x, int y, t_fract *fract)
{
	ft_clear_mlx(&fract->mlx);
	if (keycode == SCROLL_UP)
	{
		fract->zoom.zoom = 1/0.9;
		ft_pos_zoom(fract, x, y);
		fract->max_it++;
	}
	else if (keycode == SCROLL_DOWN)
	{
		fract->zoom.zoom = 0.9;
		ft_pos_zoom(fract, x, y);
		if(fract->max_it > 10)
			fract->max_it--;
	}
	
	if (keycode == RIGHT_CLICK)
		ft_right_event(fract, x, y);
	
	ft_draw(fract);
	ft_print_panel(*fract);
	return (0);
}
void	ft_fract_move(t_fract *fract, int keycode)
{
	if (keycode == LEFT)
		fract->movex++;
	else if (keycode == RIGHT)
		fract->movex--;
	else if	(keycode == UP)
		fract->movey++; 
	else if	(keycode == DOWN)
		fract->movey--;
	else if	(keycode == GREEN)
		fract->rgb = 1;
	else if	(keycode == BLUE)
		fract->rgb = 2;	
	else if	(keycode == RED)
		fract->rgb = 3;
}
int		ft_key_event(int keycode, t_fract *fract)
{
	ft_clear_mlx(&fract->mlx);
	if	(keycode == ESC)
		exit (0);
	else if	(keycode == PLUS)
		fract->n++;
	else if	(keycode == MINUS)
		fract->n--;
	else if	(keycode == CLEAR)
		ft_rezeo(fract);
	else if (keycode == I_UP)
		fract->max_it++;
	else if (keycode == I_DOWN)
	{
		if (fract->max_it > 15)
			fract->max_it--;
	}
	if (keycode == LOCK)
		fract->lock = (fract->lock == 1 ? 0 : 1);
	if (keycode == LEFT || keycode == RIGHT || keycode == UP
	|| keycode == DOWN || keycode == GREEN || keycode == RED
	|| keycode == BLUE)
		ft_fract_move(fract,keycode);
	ft_draw(fract);
	ft_print_panel(*fract);
	return (0);
}
