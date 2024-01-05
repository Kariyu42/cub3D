/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:36:09 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/05 18:40:42 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "err_type_bonus.h"

bool	is_dir(char *arg)
{
	int		fd;
	bool	res;

	res = false;
	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		res = true;
	}
	return (res);
}

char	*format_path_texture(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			j = -1;
			while (str[++j])
				str[j] = str[j + 1];
			i = -1;
		}
		else
			break ;
	}
	i = ft_strlen(str);
	i--;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

int	init_map_data(t_config **conf)
{
	int		i;
	char	**file;
	t_data	*data;

	i = -1;
	data = (*conf)->data;
	file = (*conf)->map->file;
	while (++i < (*conf)->map->map_loc)
		if (get_textures(file, data, i) < 0 || get_colors(conf, file, i) < 0)
			return (DATA_ERR);
	if (data->count_data != 6)
	{
		ft_putendl_fd(ELEMENT_ERR, STDERR_FILENO);
		return (DATA_ERR);
	}
	if (same_color(conf) == DATA_ERR)
		return (DATA_ERR);
	return (SUCCESS);
}
