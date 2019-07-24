/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 08:06:24 by abenaiss          #+#    #+#             */
/*   Updated: 2019/07/24 09:03:51 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_julia_thread(t_fract *fract)
{
	pthread_t	thread[NUM_THREAD];
	t_fract		t[NUM_THREAD];
	int			i;

	i = 0;
	while (i < NUM_THREAD)
	{
		t[i] = *fract;
		t[i].w = (WIN_WIDTH / NUM_THREAD) * i;
		t[i].maxw = (WIN_WIDTH / NUM_THREAD) * (i + 1);
		pthread_create(&thread[i], NULL, ft_julia, &t[i]);
		i++;
	}
	while (i--)
		pthread_join(thread[i], NULL);
	ft_strcpy(fract->fractal, "Julia");
	mlx_put_image_to_window(fract->mlx.mlx_ptr,
			fract->mlx.win, fract->mlx.img.img_ptr, 0, 0);
}

void	ft_burning_julia_thread(t_fract *fract)
{
	pthread_t	thread[NUM_THREAD];
	t_fract		t[NUM_THREAD];
	int			i;

	i = 0;
	while (i < NUM_THREAD)
	{
		t[i] = *fract;
		t[i].w = (WIN_WIDTH / NUM_THREAD) * i;
		t[i].maxw = (WIN_WIDTH / NUM_THREAD) * (i + 1);
		pthread_create(&thread[i], NULL, ft_burning_julia, &t[i]);
		i++;
	}
	while (i--)
		pthread_join(thread[i], NULL);
	ft_strcpy(fract->fractal, "Burning Julia");
	mlx_put_image_to_window(fract->mlx.mlx_ptr,
			fract->mlx.win, fract->mlx.img.img_ptr, 0, 0);
}

void	ft_julia_cross_thread(t_fract *fract)
{
	pthread_t	thread[NUM_THREAD];
	t_fract		t[NUM_THREAD];
	int			i;

	i = 0;
	while (i < NUM_THREAD)
	{
		t[i] = *fract;
		t[i].w = (WIN_WIDTH / NUM_THREAD) * i;
		t[i].maxw = (WIN_WIDTH / NUM_THREAD) * (i + 1);
		pthread_create(&thread[i], NULL, ft_julia_cross, &t[i]);
		i++;
	}
	while (i--)
		pthread_join(thread[i], NULL);
	ft_strcpy(fract->fractal, "Julia Cross");
	mlx_put_image_to_window(fract->mlx.mlx_ptr,
			fract->mlx.win, fract->mlx.img.img_ptr, 0, 0);
}
