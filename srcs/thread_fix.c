/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_fix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenaiss <abenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 08:06:12 by abenaiss          #+#    #+#             */
/*   Updated: 2019/07/24 09:38:10 by abenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_mandelbrot_thread(t_fract *fract)
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
		pthread_create(&thread[i], NULL, ft_mandelbrot, &t[i]);
		i++;
	}
	while (i--)
		pthread_join(thread[i], NULL);
	ft_strcpy(fract->fractal, "Mandelbrot");
	mlx_put_image_to_window(fract->mlx.mlx_ptr,
	fract->mlx.win, fract->mlx.img.img_ptr, 0, 0);
}

void	ft_burning_ship_thread(t_fract *fract)
{
	pthread_t	thread[NUM_THREAD];
	t_fract		fractal[NUM_THREAD];
	int			i;

	i = 0;
	while (i < NUM_THREAD)
	{
		fractal[i] = *fract;
		fractal[i].w = (WIN_WIDTH / NUM_THREAD) * i;
		fractal[i].maxw = (WIN_WIDTH / NUM_THREAD) * (i + 1);
		pthread_create(&thread[i], NULL, ft_burning_ship, &fractal[i]);
		i++;
	}
	while (i--)
		pthread_join(thread[i], NULL);
	ft_strcpy(fract->fractal, "Burning Ship");
	mlx_put_image_to_window(fract->mlx.mlx_ptr,
	fract->mlx.win, fract->mlx.img.img_ptr, 0, 0);
}

void	ft_tricorn_thread(t_fract *fract)
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
		pthread_create(&thread[i], NULL, ft_tricorn, &t[i]);
		i++;
	}
	while (i--)
		pthread_join(thread[i], NULL);
	ft_strcpy(fract->fractal, "Tricorn");
	mlx_put_image_to_window(fract->mlx.mlx_ptr,
	fract->mlx.win, fract->mlx.img.img_ptr, 0, 0);
}

void	ft_multibrot_thread(t_fract *fract)
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
		pthread_create(&thread[i], NULL, ft_multibrot, &t[i]);
		i++;
	}
	while (i--)
		pthread_join(thread[i], NULL);
	ft_strcpy(fract->fractal, "Multibrot");
	mlx_put_image_to_window(fract->mlx.mlx_ptr,
	fract->mlx.win, fract->mlx.img.img_ptr, 0, 0);
}
