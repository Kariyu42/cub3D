/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:22:21 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/03 17:22:22 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "err_type.h"

char	**get_wall_texture(t_config **conf)
{
	char	**table;

	table = malloc(sizeof(char *) * 5);
	if (!table)
		return (NULL);
	table[0] = (*conf)->data->no_text;
	table[1] = (*conf)->data->so_text;
	table[2] = (*conf)->data->ea_text;
	table[3] = (*conf)->data->we_text;
	table[4] = NULL;
	return (table);
}

int	stock_image(t_config **conf)
{
	int		i;
	int		width;
	int		height;
	char	**wall_text;
	t_mlx	*mlx;

	i = -1;
	mlx = (*conf)->mlx;
	width = TEXTURE_W;
	height = TEXTURE_H;
	wall_text = get_wall_texture(conf);
	while (++i < 4)
	{
		(*conf)->text[i].img = mlx_xpm_file_to_image(mlx->mlx, \
			wall_text[i], &width, &height);
		if (!(*conf)->text[i].img)
			return (-1);
		(*conf)->text[i].addr = mlx_get_data_addr((*conf)->text[i].img, \
			&(*conf)->text[i].bpp, &(*conf)->text[i].line_len, \
			&(*conf)->text[i].endian);
		if (!(*conf)->text[i].addr)
			return (-1);
	}
	free(wall_text);
	return (SUCCESS);
}
