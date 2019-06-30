/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 18:26:33 by abenaiss          #+#    #+#             */
/*   Updated: 2019/06/30 18:08:59 by abenaiss         ###   ########.fr       */
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

int		ft_exit(t_fract *fract)
{
	(void)fract;
	exit (0);
}

void	ft_fract_move(t_fract *fract, int keycode)
{
	if (keycode == LEFT)
		fract->movex += 10;
	else if (keycode == RIGHT)
		fract->movex -= 10;
	else if	(keycode == UP)
		fract->movey += 10; 
	else if	(keycode == DOWN)
		fract->movey -= 10;
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
	if(keycode == BLEND)
		fract->smooth = (fract->smooth == 1 ? 0 : 1);
	if (keycode == LOCK)
		fract->lock = (fract->lock == 1 ? 0 : 1);
	else
		ft_fract_move(fract,keycode);
	ft_draw(fract);
	ft_print_panel(*fract);
	return (0);
}
