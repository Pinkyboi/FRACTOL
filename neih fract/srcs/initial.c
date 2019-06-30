/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:46:07 by abenaiss          #+#    #+#             */
/*   Updated: 2019/06/30 14:02:03 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_rezeo(t_fract *fract)
{
	fract->max_it = 30;
	fract->zoom.rmax = 2;
	fract->zoom.imax = 2;
	fract->zoom.imin = -2;
	fract->zoom.rmin = -2;
	fract->movex = fract->movey = fract->y2 = fract->x2 = fract->lock = 0;
	fract->n = 2;
	fract->win_w= WIN_WIDTH;
	fract->win_h= WIN_HEIGHT;
}

void	ft_init_win(t_fract fract)
{
	ft_rezeo(&fract);
	fract.rgb = 2;
	fract.mlx.mlx_ptr = mlx_init();
	fract.mlx.img.img_ptr = mlx_new_image(fract.mlx.mlx_ptr,
	WIN_WIDTH, WIN_HEIGHT);
	fract.mlx.img.data = (int*)mlx_get_data_addr(fract.mlx.img.img_ptr,
	&fract.mlx.img.bpp, &fract.mlx.img.size_l, &fract.mlx.img.endian);
	fract.mlx.win = mlx_new_window(fract.mlx.mlx_ptr, WIN_WIDTH,
	WIN_HEIGHT,"Fract'ol" );
	mlx_hook(fract.mlx.win, 6, 1, (*ft_mouse_event), &fract);
	mlx_hook(fract.mlx.win, 2, 1, (*ft_key_event), &fract);
	mlx_hook(fract.mlx.win, 17, 1, (*ft_exit), &fract);
	mlx_mouse_hook(fract.mlx.win, (*ft_mouse_handel), &fract);
	ft_draw(&fract);
	ft_print_panel(fract);
	mlx_loop(fract.mlx.mlx_ptr);
}
