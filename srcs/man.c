/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:28:37 by abenaiss          #+#    #+#             */
/*   Updated: 2019/07/02 22:48:58 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

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

int		ft_exit_man(t_fract *fract)
{
	(void)fract;
	mlx_destroy_window(fract->mlx.mlx_ptr, fract->mlx.win);
	return (0);
}

void	ft_info_win1(void)
{
	t_fract fract2;

	fract2.mlx.mlx_ptr = mlx_init();
	fract2.mlx.win = mlx_new_window(fract2.mlx.mlx_ptr, 500, 350, "Man");
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
	mlx_hook(fract2.mlx.win, 17, 1, (*ft_exit_man), &fract2);
	ft_info_win2(fract2);
	mlx_loop(fract2.mlx.mlx_ptr);
}
