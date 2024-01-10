/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:24:36 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/10 11:07:10 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "err_type.h"

static bool	check_format_line(char *str, char *to_find)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(to_find);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] && !ft_isalpha(str[i]))
		return (false);
	if (!to_find && !str[i])
		return (true);
	else if (!to_find && str[i])
		return (false);
	while (str[i] && to_find[j] && str[i] == to_find[j])
	{
		i++;
		j++;
	}
	if (j == len)
		return (true);
	return (false);
}

static int	check_other(char *str)
{
	int	i;

	i = 0;
	if (str[0] && str[0] == '\n')
		return (1);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] && str[i] == '\n')
		return (1);
	return (0);
}

static int	find_elem(char *str, t_count *count)
{
	if (check_format_line(str, "NO"))
		count->no++;
	else if (check_format_line(str, "SO"))
		count->so++;
	else if (check_format_line(str, "EA"))
		count->ea++;
	else if (check_format_line(str, "WE"))
		count->we++;
	else if (check_format_line(str, "C"))
		count->ceiling++;
	else if (check_format_line(str, "F"))
		count->floor++;
	else if (!check_other(str))
		return (-1);
	return (0);
}

static bool	more_than_one(t_count *count)
{
	if (count->no > 1 || count->so > 1 || count->we > 1 \
		|| count->ea > 1 || count->ceiling > 1 || count->floor > 1)
		return (true);
	return (false);
}

bool	check_data_presence(t_config **conf, char **file)
{
	int		i;
	t_count	count;

	i = -1;
	count.no = 0;
	count.so = 0;
	count.we = 0;
	count.ea = 0;
	count.ceiling = 0;
	count.floor = 0;
	while (file[++i] && i < (*conf)->map->map_loc)
	{
		if (find_elem(file[i], &count) < 0)
			return (false);
	}
	if (count.no && count.so && count.we \
		&& count.ea && count.ceiling && count.floor)
	{
		if (more_than_one(&count) == true)
			return (false);
		return (true);
	}
	ft_putendl_fd(ELEMENT_ERR, STDERR_FILENO);
	return (false);
}
