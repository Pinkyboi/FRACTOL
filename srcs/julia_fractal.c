/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 21:00:11 by abenaiss          #+#    #+#             */
/*   Updated: 2019/07/24 09:01:45 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_fract_prep(t_fract *fract)
{
	fract->c_r = fract->zoom.rmin + (fract->zoom.rmax - fract->zoom.rmin)
	/ fract->win_w * (fract->col + fract->movex);
	fract->c_i = fract->zoom.imin + (fract->zoom.imax - fract->zoom.imin)
	/ fract->win_h * (fract->row + fract->movey);
	fract->z_r = fract->c_r;
	fract->z_i = fract->c_i;
	fract->it = 0;
	fract->zrsqr = fract->z_r * fract->z_r;
	fract->zisqr = fract->z_i * fract->z_i;
}

void	*ft_julia(void *data)
{
	t_fract	*fract;

	fract = data;
	fract->row = fract->w - 1;
	while (++fract->row < fract->win_h)
	{
		fract->col = fract->w - 1;
		while (++fract->col < fract->win_w)
		{
			ft_fract_prep(fract);
			while (fract->zrsqr + fract->zisqr < 4 && fract->it < fract->max_it)
			{
				fract->zrsqr = fract->z_r * fract->z_r;
				fract->zisqr = fract->z_i * fract->z_i;
				fract->z_i = fract->z_r * fract->z_i;
				fract->z_i += fract->y1 + fract->z_i;
				fract->z_r = fract->zrsqr - fract->zisqr + fract->x1;
				fract->it++;
			}
			ft_print(fract);
		}
	}
	return (NULL);
}

void	*ft_julia_cross(void *data)
{
	t_fract	*fract;

	fract = data;
	fract->row = -1;
	while (++fract->row < fract->win_h)
	{
		fract->col = fract->w - 1;
		while (++fract->col < fract->win_w)
		{
			ft_fract_prep(fract);
			while (fract->zrsqr + fract->zisqr < 4 && fract->it < fract->max_it)
			{
				fract->zrsqr = fract->z_r * fract->z_r;
				fract->zisqr = fract->z_i * fract->z_i;
				fract->z_i = fract->z_r * fract->z_i;
				fract->z_i += fract->y1 + fract->z_i;
				fract->z_r = fabsl(fract->zrsqr - fract->zisqr) + fract->x1;
				fract->it++;
			}
			ft_print(fract);
		}
	}
	return (NULL);
}

void	*ft_burning_julia(void *data)
{
	t_fract *fract;

	fract = data;
	fract->row = -1;
	while (++fract->row < fract->win_h)
	{
		fract->col = fract->w - 1;
		while (++fract->col < fract->win_w)
		{
			ft_fract_prep(fract);
			while (fract->zrsqr + fract->zisqr < 4 && fract->it < fract->max_it)
			{
				fract->zrsqr = fract->z_r * fract->z_r;
				fract->zisqr = fract->z_i * fract->z_i;
				fract->z_i = 2 * fabsl(fract->z_r * fract->z_i);
				fract->z_i += fract->y1;
				fract->z_r = fract->zrsqr - fract->zisqr + fract->x1;
				fract->it++;
			}
			ft_print(fract);
		}
	}
	return (NULL);
}
