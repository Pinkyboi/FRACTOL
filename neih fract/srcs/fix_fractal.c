/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_fractal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 18:37:10 by abenaiss          #+#    #+#             */
/*   Updated: 2019/06/30 18:38:49 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_mandelbrot(t_fract *fract)
{
	ft_strcpy(fract->fractal, "Mandelbrot");
	fract->row = 0;
	while (fract->row < fract->win_h)
	{
		fract->col = 0;
		while (fract->col < fract->win_w)
		{	ft_fract_prep(fract);
			while (fract->zrsqr + fract->zisqr < 4 && fract->it < fract->max_it)
			{   
				fract->zrsqr = fract->z_r *fract->z_r;
				fract->zisqr = fract->z_i * fract->z_i;
				fract->z_i = fract->z_r * fract->z_i;
				fract->z_i += fract->c_i + fract->z_i;
				fract->z_r = fract->zrsqr - fract->zisqr + fract->c_r;
				fract->it++;
			}
			ft_print(fract);
			fract->col++;
		}
		fract->row++;
	}

}

void	ft_tricorn(t_fract *fract)
{
	ft_strcpy(fract->fractal, "Tricorn");
	fract->row = 0;
	while (fract->row < fract->win_h)
	{
		fract->col = 0;
		while (fract->col < fract->win_w)
		{	ft_fract_prep(fract);
			while (fract->zrsqr + fract->zisqr < 4 && fract->it < fract->max_it)
			{   
				fract->zrsqr = fract->z_r *fract->z_r;
				fract->zisqr = fract->z_i * fract->z_i;
				fract->z_i = -2 * fract->z_r * fract->z_i;
				fract->z_i += fract->c_i;
				fract->z_r = fract->zrsqr - fract->zisqr + fract->c_r;
				fract->it++;
			}
			ft_print(fract);
			fract->col++;
		}
		fract->row++;
	}
}

void	ft_burning_ship(t_fract *fract)
{
	ft_strcpy(fract->fractal, "Burning Ship");
	fract->row = 0;
	while (fract->row < fract->win_h)
	{
		fract->col = 0;
		while (fract->col < fract->win_w)
		{	ft_fract_prep(fract);
			while (fract->zrsqr + fract->zisqr < 4 && fract->it < fract->max_it)
			{   
				fract->zrsqr =fract->z_r * fract->z_r;
				fract->zisqr =fract->z_i * fract->z_i;
				fract->z_i = 2 * fabsl(fract->z_r * fract->z_i);
				fract->z_i += fract->c_i;
				fract->z_r = fabsl(fract->zrsqr - fract->zisqr + fract->c_r);
				fract->it++;
			}
			ft_print(fract);
			fract->col++;
		}
		fract->row++;
	}

}

void	ft_multibrot(t_fract *fract)
{
	ft_strcpy(fract->fractal, "Multibrot");
	fract->row = 0;
	while (fract->row < fract->win_h)
	{
		fract->col = 0;
		while (fract->col < fract->win_w)
		{	ft_fract_prep(fract);
			while ( fract->zrsqr + fract->zisqr < 4 && fract->it < fract->max_it)
			{   
				fract->zrsqr = fract->z_r * fract->z_r;
				fract->zisqr = fract->z_i * fract->z_i;
				double t = fract->z_r;
				fract->z_r=pow((fract->zrsqr + fract->zisqr),(fract->n / 2)) *
				cos(fract->n * atan2(fract->z_i,fract->z_r)) + fract->c_r;
				fract->z_i=pow((fract->zrsqr + fract->zisqr),(fract->n / 2)) *
				sin(fract->n * atan2(fract->z_i,t)) + fract->c_i;
				fract->it++;
			}
			ft_print(fract);
			fract->col++;
		}
		fract->row++;
	}

}