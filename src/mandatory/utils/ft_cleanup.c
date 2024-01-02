#include "cub3d.h"
#include "err_type.h"

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
	if ((*conf)->map->file)
		free_double_p((*conf)->map->file);
	if ((*conf)->map->sketch)
		free((*conf)->map->sketch);
	if ((*conf)->data->c_color)
		free_double_p((*conf)->data->c_color);
	if ((*conf)->data->f_color)
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
	if ((*conf)->map->file)
		free_double_p((*conf)->map->file);
	if ((*conf)->map->sketch)
		free((*conf)->map->sketch);
	if ((*conf)->data->c_color)
		free_double_p((*conf)->data->c_color);
	if ((*conf)->data->f_color)
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
	if ((*conf)->mlx->win)
		mlx_destroy_window((*conf)->mlx->mlx, (*conf)->mlx->win);
	if ((*conf)->mlx->img)
		mlx_destroy_image((*conf)->mlx->mlx, (*conf)->mlx->img);
	if ((*conf)->mlx)
		free((*conf)->mlx);
	free_table_err(conf, NULL, 0);
	exit(EXIT_SUCCESS);
	return (SUCCESS);
}
