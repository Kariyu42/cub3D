/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:22:28 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/03 17:55:58 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "err_type_bonus.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_mlx *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	return (*(unsigned int *)dst);
}

int	initialize_mlx_win(t_config **conf)
{
	(*conf)->mlx = malloc(sizeof(t_mlx));
	if (!(*conf)->mlx)
		return (ft_putendl_fd(MALLOC_ERR, STDERR_FILENO));
	(*conf)->mlx->mlx = mlx_init();
	if (!(*conf)->mlx->mlx)
		return (ft_putendl_fd(INIT_ERR, STDERR_FILENO));
	(*conf)->mlx->win = mlx_new_window((*conf)->mlx->mlx, \
		WIDTH, HEIGHT, "Cub3D");
	if (!(*conf)->mlx->win)
		return (-1);
	(*conf)->mlx->img = mlx_new_image((*conf)->mlx->mlx, WIDTH, HEIGHT);
	if (!(*conf)->mlx->img)
		return (-1);
	(*conf)->mlx->addr = mlx_get_data_addr((*conf)->mlx->img, \
		&(*conf)->mlx->bpp, &(*conf)->mlx->line_len, &(*conf)->mlx->endian);
	if (!(*conf)->mlx->addr)
		return (-1);
	return (SUCCESS);
}
