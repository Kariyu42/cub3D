/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:43:58 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/05 14:38:27 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "err_type_bonus.h"

static int	valid_filename(char *str, int len)
{
	if (str[len - 4] != '.' || str[len - 3] != 'c'
		|| str[len - 2] != 'u' || str[len - 1] != 'b')
		return (ft_putendl_fd(EXT_ERR, STDERR_FILENO));
	len -= 4;
	if (len <= 0)
		return (ft_putendl_fd(EXT_ERR, STDERR_FILENO));
	len--;
	if (str[len] && str[len] == '/')
		return (ft_putendl_fd(EXT_ERR, STDERR_FILENO));
	return (SUCCESS);
}

int	check_extension(char *str)
{
	int	len;
	int	fd;

	len = ft_strlen(str);
	if (!len)
		return (-1);
	fd = open(str, O_DIRECTORY);
	if (fd >= 0)
	{
		if (close(fd) == -1)
			return (ft_putendl_fd(CLOSE_ERR, STDERR_FILENO));
		return (ft_putendl_fd(DIR_ERR, STDERR_FILENO));
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd(OPEN_ERR, STDERR_FILENO));
	if (valid_filename(str, len) == -1)
		return (-1);
	if (close(fd) == -1)
		return (ft_putendl_fd(CLOSE_ERR, STDERR_FILENO));
	return (SUCCESS);
}

t_pos	find_pos(char letter, char **map)
{
	int		i;
	int		j;
	t_pos	pos;

	i = -1;
	pos.x = -1;
	pos.y = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == letter)
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
		}
	}
	return (pos);
}

char	*fill_map(char *map, char *tmp, int line_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * (line_len));
	if (!tmp)
		return (NULL);
	while (i < line_len - 1)
	{
		if (i == 0)
			tmp[i] = '/';
		else if ((map[j] && map[j] == ' ') || !map[j])
			tmp[i] = '/';
		else if (map[j])
			tmp[i] = map[j];
		if (map[j] && i != 0)
			j++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*fill_extremities(char *tmp, int line_len)
{
	int	i;

	i = -1;
	tmp = malloc(sizeof(char) * line_len);
	if (!tmp)
		return (NULL);
	while (++i < line_len - 1)
		tmp[i] = '/';
	tmp[i] = '\0';
	return (tmp);
}
