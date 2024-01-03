/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:36:16 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/03 17:36:17 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "err_type.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	same_color(t_config **conf)
{
	int		i;
	t_data	*data;

	i = 0;
	data = (*conf)->data;
	if (data->c_color[0] && data->c_color[1] && data->c_color[2]
		&& data->f_color[0] && data->f_color[1] && data->f_color[2])
	{
		if (ft_strcmp(data->c_color[0], data->f_color[0]) == 0)
			i++;
		if (ft_strcmp(data->c_color[1], data->f_color[1]) == 0)
			i++;
		if (ft_strcmp(data->c_color[2], data->f_color[2]) == 0)
			i++;
		if (i != 3)
			return (SUCCESS);
		else
			return (free_table_err(conf, COLOR_ERR, DATA_ERR));
	}
	else
		return (ERROR);
}

int	valid_color(char **color)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (color[i])
	{
		c = ft_atoi(color[i]);
		if (!(c >= 0 && c <= 255))
			return (ft_putendl_fd(NB_COLOR_ERR, STDERR_FILENO));
		i++;
	}
	return (SUCCESS);
}

int	check_color(char ***color, char *str, int *data)
{
	int	i;

	i = 0;
	if (str[i + 1] != ' ')
		return (ERROR);
	i++;
	while (!ft_isdigit(str[i]))
		i++;
	color[0] = ft_split(str + i, ',');
	if (color[0] == NULL)
		return (0);
	if ((len_tab(color[0]) == 3 && valid_color(color[0]) == SUCCESS))
	{
		(*data)++;
		return (SUCCESS);
	}
	else
		return (ERROR);
}
