/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magoumi <magoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:16:13 by abenaiss          #+#    #+#             */
/*   Updated: 2019/07/01 05:04:01 by magoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

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

void	ft_right_event(t_fract *fract, int x, int y)
{
	if (y >= 600 && y <= 625)
	{
		if (x >= 40 && x <= 65)
			fract->rgb = 1;
		if (x >= 70 && x <= 95)
			fract->rgb = 2;
		if (x >= 100 && x <= 125)
			fract->rgb = 3;
	}
	if (y >= 350 && y <= 375)
	{
		if (x >= 15 && x <= 30 && fract->choose > 1)
			fract->choose--;
		if (x >= 660 && x <= 685 && fract->choose < 7)
			fract->choose++;
		ft_rezeo(fract);
	}
	ft_draw(fract);
	ft_print_panel(*fract);
}

int		ft_mouse_handel(int keycode, int x, int y, t_fract *fract)
{
	ft_clear_mlx(&fract->mlx);
	if (keycode == SCROLL_UP)
	{
		fract->zoom.zoom = 1.1;
		ft_pos_zoom(fract, x, y);
		fract->max_it++;
	}
	else if (keycode == SCROLL_DOWN)
	{
		fract->zoom.zoom = 0.9;
		ft_pos_zoom(fract, x, y);
		fract->max_it--;
	}
	if (keycode == RIGHT_CLICK)
	{
		if (y >= 0 && y <= 25 && x >= fract->win_h - 25 && x <= fract->win_h)
			ft_info_win1();
		ft_right_event(fract, x, y);
	}
	ft_draw(fract);
	ft_print_panel(*fract);
	return (0);
}
