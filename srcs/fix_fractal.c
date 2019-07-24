/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 18:37:10 by abenaiss          #+#    #+#             */
/*   Updated: 2019/07/24 09:06:50 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	*ft_mandelbrot(void *data)
{
	t_fract *fract;

	fract = data;
	fract->row = -1;
	while (++fract->row < fract->win_h)
	{
		fract->col = fract->w - 1;
		while (++fract->col < fract->maxw)
		{
			ft_fract_prep(fract);
			while (fract->zrsqr + fract->zisqr < 4 && fract->it < fract->max_it)
			{
				fract->zrsqr = fract->z_r * fract->z_r;
				fract->zisqr = fract->z_i * fract->z_i;
				fract->z_i = fract->z_r * fract->z_i;
				fract->z_i += fract->c_i + fract->z_i;
				fract->z_r = fract->zrsqr - fract->zisqr + fract->c_r;
				fract->it++;
			}
			ft_print(fract);
		}
	}
	return (NULL);
}

void	*ft_tricorn(void *data)
{
	t_fract		*fract;

	fract = data;
	fract->row = -1;
	while (++fract->row < fract->win_h)
	{
		fract->col = fract->w - 1;
		while (++fract->col < fract->maxw)
		{
			ft_fract_prep(fract);
			while (fract->zrsqr + fract->zisqr < 4 && fract->it < fract->max_it)
			{
				fract->zrsqr = fract->z_r * fract->z_r;
				fract->zisqr = fract->z_i * fract->z_i;
				fract->z_i = -2 * fract->z_r * fract->z_i;
				fract->z_i += fract->c_i;
				fract->z_r = fract->zrsqr - fract->zisqr + fract->c_r;
				fract->it++;
			}
			ft_print(fract);
		}
	}
	return (NULL);
}

void	*ft_burning_ship(void *data)
{
	t_fract *fract;

	fract = data;
	fract->row = -1;
	while (++fract->row < fract->win_h)
	{
		fract->col = fract->w - 1;
		while (++fract->col < fract->maxw)
		{
			ft_fract_prep(fract);
			while (fract->zrsqr + fract->zisqr < 4 && fract->it < fract->max_it)
			{
				fract->zrsqr = fract->z_r * fract->z_r;
				fract->zisqr = fract->z_i * fract->z_i;
				fract->z_i = 2 * fabsl(fract->z_r * fract->z_i);
				fract->z_i += fract->c_i;
				fract->z_r = fabsl(fract->zrsqr - fract->zisqr + fract->c_r);
				fract->it++;
			}
			ft_print(fract);
		}
	}
	return (NULL);
}

void	*ft_multibrot(void *data)
{
	t_fract *fract;

	fract = data;
	fract->row = -1;
	while (++fract->row < fract->win_h)
	{
		fract->col = fract->w - 1;
		while (++fract->col < fract->maxw)
		{
			ft_fract_prep(fract);
			while (fract->zrsqr + fract->zisqr < 4 && fract->it < fract->max_it)
			{
				fract->stockz = fract->z_r;
				fract->zrsqr = fract->z_r * fract->z_r;
				fract->zisqr = fract->z_i * fract->z_i;
				fract->z_r = pow((fract->zrsqr + fract->zisqr), (fract->n / 2))
				* cos(fract->n * atan2(fract->z_i, fract->z_r)) + fract->c_r;
				fract->z_i = pow((fract->zrsqr + fract->zisqr), (fract->n / 2))
				* sin(fract->n * atan2(fract->z_i, fract->stockz)) + fract->c_i;
				fract->it++;
			}
			ft_print(fract);
		}
	}
	return (NULL);
}
