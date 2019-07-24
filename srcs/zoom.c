/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 17:19:32 by abenaiss          #+#    #+#             */
/*   Updated: 2019/07/24 09:06:20 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	ft_zoom(t_fract *fract)
{
	double interpolation;

	interpolation = 1.0 / fract->zoom.zoom;
	fract->zoom.rmin = interpolate(fract->zoom.mousere, fract->zoom.rmin,
	interpolation);
	fract->zoom.imin = interpolate(fract->zoom.mouseim, fract->zoom.imin,
	interpolation);
	fract->zoom.rmax = interpolate(fract->zoom.mousere, fract->zoom.rmax,
	interpolation);
	fract->zoom.imax = interpolate(fract->zoom.mouseim, fract->zoom.imax,
	interpolation);
}

void	ft_pos_zoom(t_fract *fract, double x, double y)
{
	fract->zoom.mousere = ((double)x + fract->movex) / (fract->win_w /
	(fract->zoom.rmax - fract->zoom.rmin)) + fract->zoom.rmin;
	fract->zoom.mouseim = ((double)y + fract->movey) / (fract->win_h /
	(fract->zoom.imax - fract->zoom.imin)) + fract->zoom.imin;
	ft_zoom(fract);
}
