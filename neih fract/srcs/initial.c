/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 17:46:07 by abenaiss          #+#    #+#             */
/*   Updated: 2019/06/29 19:18:04 by abenaiss         ###   ########.fr       */
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

void	ft_print_sqrt(t_fract fract)
{
	int col;

	if (fract.lock == 1)
		col = 0x00FF00;
	else
		col = 0xFF0000;
	fract.choose == 1 ? ft_drawsquare(&fract, 14, (fract.win_h / 2) - 1,
	0xFF0000) : ft_drawsquare(&fract, 14, (fract.win_h / 2) - 1, 0x00FF00);
	fract.choose == 6 ? ft_drawsquare(&fract, fract.win_w - 41,
	(fract.win_h / 2) - 1,0xFF0000) : ft_drawsquare(&fract, fract.win_w - 41,
	(fract.win_h / 2) - 1, 0x00FF00);
	ft_drawsquare(&fract, 40, fract.win_h - 100, 0x7fff00);
	ft_drawsquare(&fract, 70, fract.win_h - 100, 0x14A8F3);
	ft_drawsquare(&fract, 100, fract.win_h - 100, 0xFF8C00);
	ft_drawsquare(&fract, fract.win_w - 25, fract.win_h - 25, col);
	ft_drawsquare(&fract, fract.win_w - 50, fract.win_h - 25, col);
	ft_drawsquare(&fract, fract.win_w - 25, 0, 0);
	mlx_put_image_to_window(fract.mlx.mlx_ptr, fract.mlx.win,
	fract.mlx.img.img_ptr, 0, 0);
}

void	ft_effet(t_fract fract)
{    
	int i ;

	i = 0;
	while (++i <= 3)
	{
		if(i == fract.rgb)
			mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win,7.5 + i * 30,
			fract.win_h - 100, 0xFFFFFF, " o ");
	}
	i = 0;
	while (++i <= 6)
	{
		if (i == fract.choose)
			mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win,
			fract.win_w/ 2 - 40 + i * 10, fract.win_h - 37, 0xFFFFFF, "o");
		else
			mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win,
			fract.win_w/2 - 40 + i * 10, fract.win_h - 40, 0xFFFFFF, ".");
	}    
}

void	ft_print_panel(t_fract fract)
{
    ft_print_sqrt(fract);
	ft_effet(fract);
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win,
	10, 5, 0xFFFFFF, "Itération :");
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win, 110,
	5, 0xFFFFFF, ft_itoa(fract.max_it));
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win, fract.win_w/4,
	5, 0xFFFFFF, " _____________________________________ ");
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win, fract.win_w/4,
	-5, 0xFFFFFF, "|                                     |");
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win, 230,
	0, 0xFFFFFF, ft_itoa(fract.choose));
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win, 250,
	0, 0xFFFFFF, fract.fractal);
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win, 10,
	fract.win_h / 2, 0xFFFFFF, " < ");
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win,fract.win_w - 45,
	fract.win_h / 2, 0xFFFFFF, " > ");
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win,fract.win_w - 45,
	fract.win_h - 25, 0xFFFFFF, "lock");
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win,fract.win_w - 18,0,
	0xFFFFFF, "?");
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
