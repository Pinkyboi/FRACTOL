/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 02:32:15 by abenaiss          #+#    #+#             */
/*   Updated: 2019/06/29 18:33:38 by abenaiss         ###   ########.fr       */
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
