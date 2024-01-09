/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:24:28 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/09 14:58:03 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "err_type.h"

double	ft_abs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	fill_colors(char **color_table, int *to_fill)
{
	int	i;

	i = 0;
	while (color_table[i] && i < 3)
	{
		to_fill[i] = ft_atoi(color_table[i]);
		i++;
	}
}

int	increase_counter(char *str, int *i, int *comma_count, int *rgb_count)
{
	if (str[*i] == ',' && !rgb_count)
		return (ERROR);
	while (str[*i] && ft_isdigit(str[*i]))
	{
		(*i)++;
		if (!ft_isdigit(str[*i]))
			(*rgb_count)++;
		while (str[*i] && str[*i] == ',')
		{
			(*comma_count)++;
			(*i)++;
		}
		if (*comma_count > 2)
			return (ERROR);
	}
	return (SUCCESS);
}

int	valid_color_checker(char *str, int *i)
{
	int	comma_count;
	int	rgb_count;

	rgb_count = 0;
	comma_count = 0;
	while (str[*i])
	{
		if (!ft_isdigit(str[*i]) && str[*i] != ' ' && str[*i] != '\t' \
			&& str[*i] != ',')
			return (ERROR);
		if (increase_counter(str, i, &comma_count, &rgb_count) == ERROR)
			return (ERROR);
		(*i)++;
	}
	if (rgb_count != 3 && comma_count != 2)
		return (ERROR);
	*i = 0;
	while (str[*i] && (str[*i] != 'C' && str[*i] != 'F'))
		(*i)++;
	if (str[*i + 1] && (str[*i + 1] == ' ' || str[*i + 1] == '\t'))
		(*i)++;
	while (str[*i] && (str[*i] == ' ' && str[*i] == '\t'))
		(*i)++;
	return (SUCCESS);
}
