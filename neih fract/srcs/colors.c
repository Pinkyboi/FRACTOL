/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 20:55:17 by abenaiss          #+#    #+#             */
/*   Updated: 2019/06/30 18:47:13 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		ft_int_rgb(int r, int g, int b)
{
	int c;

	c = r;
	c = (c << 8) | g;
	c = (c << 8) | b;
	return (c);
}

int		ft_color_re(t_fract *fract, double t)
{
	int	r;
	int	g;
	int	b;

	if	(fract->rgb == 2)
	{
		r = (int)(8 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else
	{
		b = (int)(8 * (1 - t) * t * t * t * 255);
		g = (int)(15 * (1 - t) * (1 -  t) * t * t * 255);
		r = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	return (ft_int_rgb(r, g, b));
}

int		ft_color(t_fract *fract)
{
	double t;
	int r;
	int g;
	int b;

	t = fract->it/fract->max_it;
	if (fract->rgb == 1)
	{
		r = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (int)(8 * (1 - t) * t * t * t * 255);
		g = (int)(9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
			return (ft_int_rgb(r, g, b)); 
	}
	else
		r = ft_color_re(fract, t);
	return (r);
}

void	ft_print(t_fract *fract)
{
	float mod;
	float mu;
	if(fract->smooth)
	{
		mod = (fract->zisqr + fract->zrsqr) * (fract->zisqr 
		+ fract->zrsqr);
		fract->it = fract->it - log(log(mod)) + 4;		
	}
	if (fract->it !=  fract->max_it && fract->row >= 0 && fract->row
        <= WIN_HEIGHT && fract->col >= 0 && fract->col <= WIN_WIDTH)
		fract->mlx.img.data[fract->row * WIN_WIDTH + fract->col] 
            = ft_color(fract);
}