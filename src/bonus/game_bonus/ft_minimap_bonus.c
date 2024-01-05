/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:36:58 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/05 14:37:04 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "err_type_bonus.h"

static void	put_img_to_window(t_mlx *mlx, t_mlx image, int x, int y)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win,
		image.img, x, y);
}

static void	put_img_minimap(t_data *data, t_config **conf, int i, int j)
{
	if ((data->pos_mmap_y >= 0 && data->pos_mmap_x < (*conf)->map->map_len)
		&& (data->pos_mmap_x >= 0 && data->pos_mmap_y < \
			(int)ft_strlen((*conf)->map->sketch[(int)data->pos_mmap_x])))
	{
		if ((*conf)->map->sketch[(int)data->pos_mmap_x]
			[(int)data->pos_mmap_y] == '1')
			put_img_to_window((*conf)->mlx, data->wall, i * 12, j * 12);
		else if ((*conf)->map->sketch[(int)data->pos_mmap_x]
			[(int)data->pos_mmap_y] == '0')
			put_img_to_window((*conf)->mlx, data->floor, i * 12, j * 12);
		else if ((*conf)->map->sketch[(int)data->pos_mmap_x]
			[(int)data->pos_mmap_y] == '2')
			put_img_to_window((*conf)->mlx, data->door_c, i * 12, j * 12);
		else if ((*conf)->map->sketch[(int)data->pos_mmap_x] \
			[(int)data->pos_mmap_y] == '3')
			put_img_to_window((*conf)->mlx, data->door_o, i * 12, j * 12);
		else if (ft_strchr("NSWE", (*conf)->map->sketch[(int)data->pos_mmap_x] \
			[(int)data->pos_mmap_y]))
			put_img_to_window((*conf)->mlx, data->floor, i * 12, j * 12);
		else if ((*conf)->map->sketch[(int)data->pos_mmap_x] \
			[(int)data->pos_mmap_y] == ' ')
			put_img_to_window((*conf)->mlx, data->empty, i * 12, j * 12);
	}
	else
		put_img_to_window((*conf)->mlx, data->empty, i * 12, j * 12);
}

int	ft_load_minimap(t_config **conf, t_mlx *mlx)
{
	int			i;
	int			j;
	t_player	*p;

	p = (*conf)->usr;
	(*conf)->data->pos_mmap_y = p->pos_y - (MID_MINIMAP - 1);
	i = -1;
	while (++i < SIZE_MINIMAP)
	{
		j = -1;
		(*conf)->data->pos_mmap_x = p->pos_x - (MID_MINIMAP - 1);
		while (++j < SIZE_MINIMAP)
		{
			put_img_minimap((*conf)->data, conf, i, j);
			(*conf)->data->pos_mmap_x++;
		}
		(*conf)->data->pos_mmap_y++;
	}
	put_img_to_window(mlx, (*conf)->data->tex_player, \
		(MID_MINIMAP - 1) * 12, (MID_MINIMAP - 1) * 12);
	return (SUCCESS);
}
