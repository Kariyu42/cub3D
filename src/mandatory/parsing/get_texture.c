/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:36:12 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/06 19:18:26 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "err_type.h"

int	ft_contain(char *str, char *find)
{
	int	i;
	int	j;
	int	k;
	int	len_find;

	i = 0;
	len_find = ft_strlen(find);
	while (str[i])
	{
		j = 0;
		k = i;
		while (str[k] == find[j])
		{
			j++;
			k++;
		}
		if (j == len_find)
			return (1);
		i++;
	}
	return (0);
}

int	check_path(char *arg)
{
	int	fd;
	int	len;

	format_path_texture(arg);
	len = ft_strlen(arg);
	if (is_dir(arg))
		return (ft_putendl_fd(DIR_ERR, STDERR_FILENO));
	if (arg[len - 4] != '.' || arg[len - 3] != 'x' || \
	arg[len - 2] != 'p' || arg[len - 1] != 'm')
		return (ft_putendl_fd(XPM_ERR, STDERR_FILENO));
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd(OPEN_ERR, STDERR_FILENO));
	close(fd);
	return (SUCCESS);
}

int	get_path(char *str, char **store_data, int *data)
{
	if (ft_contain(str, ".xpm") == 0)
		return (-1);
	else
	{
		*store_data = str + 3;
		(*data)++;
	}
	return (check_path(*store_data));
}

int	get_textures(char **file, t_data *data, int i)
{
	if (ft_contain(file[i], "NO"))
	{
		if (get_path(file[i], &data->no_text, &data->count_data) == -1)
			return (ft_putendl_fd(PATH_ERR, STDERR_FILENO));
	}
	else if (ft_contain(file[i], "SO"))
	{
		if (get_path(file[i], &data->so_text, &data->count_data) == -1)
			return (ft_putendl_fd(PATH_ERR, STDERR_FILENO));
	}
	else if (ft_contain(file[i], "WE"))
	{
		if (get_path(file[i], &data->we_text, &data->count_data) == -1)
			return (ft_putendl_fd(PATH_ERR, STDERR_FILENO));
	}
	else if (ft_contain(file[i], "EA"))
	{
		if (get_path(file[i], &data->ea_text, &data->count_data) == -1)
			return (ft_putendl_fd(PATH_ERR, STDERR_FILENO));
	}
	return (SUCCESS);
}

int	get_colors(t_config **conf, char **file, int i)
{
	t_data	*data;

	data = (*conf)->data;
	if (ft_strchr(file[i], 'F'))
	{
		if (check_color(&data->f_color, file[i], &data->count_data) == ERROR)
			return (-1);
	}
	else if (ft_strchr(file[i], 'C'))
	{
		if (check_color(&data->c_color, file[i], &data->count_data) == ERROR)
			return (-1);
	}
	return (SUCCESS);
}
