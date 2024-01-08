/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:24:45 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/08 15:27:54 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "err_type.h"

void	ft_destroy_img(t_config **conf, t_mlx *table)
{
	int		i;
	t_mlx	*mlx;

	i = -1;
	mlx = (*conf)->mlx;
	while (++i < 4)
		mlx_destroy_image(mlx->mlx, table[i].img);
	if ((*conf)->mlx->win)
		mlx_destroy_window((*conf)->mlx->mlx, (*conf)->mlx->win);
	if ((*conf)->mlx->img)
		mlx_destroy_image((*conf)->mlx->mlx, (*conf)->mlx->img);
}

void	free_double_p(char **table)
{
	int	i;

	i = -1;
	if (!table)
		return ;
	while (table[++i])
		free(table[i]);
	free(table);
	table = NULL;
}

int	free_table_err(t_config **conf, char *message, int r_value)
{
	if (!*conf || !conf)
		return (0);
	if ((*conf)->map && (*conf)->map->file)
		free_double_p((*conf)->map->file);
	if ((*conf)->map && (*conf)->map->sketch)
		free((*conf)->map->sketch);
	if ((*conf)->map)
		free((*conf)->map);
	if ((*conf)->data && (*conf)->data->c_color)
		free_double_p((*conf)->data->c_color);
	if ((*conf)->data && (*conf)->data->f_color)
		free_double_p((*conf)->data->f_color);
	if ((*conf)->data)
		free((*conf)->data);
	if ((*conf)->usr)
		free((*conf)->usr);
	if ((*conf)->ray)
		free((*conf)->ray);
	if (*conf)
		free(*conf);
	if (message)
		ft_putendl_fd(message, STDERR_FILENO);
	return (r_value);
}

void	*free_void_err(t_config **conf, char *message)
{
	if (!*conf || !conf)
		return (0);
	if ((*conf)->map && (*conf)->map->file)
		free_double_p((*conf)->map->file);
	if ((*conf)->map && (*conf)->map->sketch)
		free((*conf)->map->sketch);
	if ((*conf)->data && (*conf)->data->c_color)
		free_double_p((*conf)->data->c_color);
	if ((*conf)->data && (*conf)->data->f_color)
		free_double_p((*conf)->data->f_color);
	if ((*conf)->data)
		free((*conf)->data);
	if ((*conf)->usr)
		free((*conf)->usr);
	if ((*conf)->ray)
		free((*conf)->ray);
	if (*conf)
		free(*conf);
	if (message)
		ft_putendl_fd(message, STDERR_FILENO);
	return (NULL);
}

int	ft_close(t_config **conf)
{
	if (!*conf || !conf)
		return (0);
	ft_destroy_img(conf, (*conf)->text);
	if ((*conf)->mlx)
		free((*conf)->mlx);
	free_table_err(conf, NULL, 0);
	exit(EXIT_SUCCESS);
	return (SUCCESS);
}
