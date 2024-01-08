/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:24:36 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/08 18:33:47 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "err_type.h"

static void	find_elem(char *str, t_count *count)
{
	if (ft_contain(str, "NO"))
		count->no++;
	else if (ft_contain(str, "SO"))
		count->so++;
	else if (ft_contain(str, "EA"))
		count->ea++;
	else if (ft_contain(str, "WE"))
		count->we++;
	else if (ft_contain(str, "C"))
		count->ceiling++;
	else if (ft_contain(str, "F"))
		count->floor++;
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
	int	i;
	t_count	count;

	i = -1;
	count.no = 0;
	count.so = 0;
	count.we = 0;
	count.ea = 0;
	count.ceiling = 0;
	count.floor = 0;
	while (file[++i] && i < (*conf)->map->map_loc)
		find_elem(file[i], &count);
	if (count.no && count.so && count.we \
		&& count.ea && count.ceiling && count.floor)
	{
		if (more_than_one(&count) == true)
			return (false);
		return (true);
	}
	return (false);
}