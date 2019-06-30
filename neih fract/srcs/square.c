/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 02:32:15 by abenaiss          #+#    #+#             */
/*   Updated: 2019/06/30 18:40:39 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_drawsquare(t_fract *fract, int col, int row, int rgb)
{
	int	i;
	int	j;

	i = col - 1;
	while (++ i < 25 + col)
	{
		j = row - 1;
		while (++j < 25 + row)
			fract->mlx.img.data[j * WIN_WIDTH + i] = rgb;
	}
}

void	ft_print_sqrt(t_fract fract)
{
	int col;

	col = ((fract.lock == 1) ? 0x00FF00:0xFF0000);
	fract.choose == 1 ? ft_drawsquare(&fract, 14, (fract.win_h / 2) - 1,
	0xFF0000) : ft_drawsquare(&fract, 14, (fract.win_h / 2) - 1, 0x00FF00);
	fract.choose == 7 ? ft_drawsquare(&fract, fract.win_w - 41,
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
	while (++i <= 7)
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
	5, 5, 0xFFFFFF, "Iterations:");
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win, 120,
	5, 0xFFFFFF, ft_itoa(fract.max_it));
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win, 5,
	40, 0xFFFFFF,"Blend colors (P)");
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win, fract.win_w/4,
	5, 0xFFFFFF, " ____________________________ ");
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win, fract.win_w/4,
	-5, 0xFFFFFF, "|                            |");
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win, 170,
	0, 0xFFFFFF, ft_itoa(fract.choose));
	mlx_string_put(fract.mlx.mlx_ptr, fract.mlx.win, 190,
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

