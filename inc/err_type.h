/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_type.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:57:10 by kquetat-          #+#    #+#             */
/*   Updated: 2024/01/08 14:15:18 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_TYPE_H
# define ERR_TYPE_H

# include "../Lib/Libft/inc/libft.h"

/* Custom Return Values */
typedef enum e_value
{
	SUCCESS,
	MAP_ERR,
	DATA_ERR
}	t_value;

# define ERROR 2

/* List of Error Messages */
// map sketch collection error message
# define GET_SKETCH_ERR "Issue with the collection of the map sketch\n"
// data colletion error message
# define GET_DATA_ERR "Issue concerning the collection of the data\n"
// arguments errors message
# define ARG_ERR "Error\nPlease provide a valid [.cub] map."
// malloc error messages
# define MALLOC_ERR "Error\nFailed to malloc."
// extension .cub error message
# define EXT_ERR "Error\nProvide a valid {filename}.cub map."
// length error message
# define LEN_ERR "Error\nLength error."
// location error message
# define LOC_ERR "Error\nCan't find index loc of map."

/* OPEN FUNCTION ERROR */
// fd open error messages
# define OPEN_ERR "Error\nFailed to open the file."
// fd close error messages
# define CLOSE_ERR "Error\nFailed to close the file."
// opening a directory error messages
# define DIR_ERR "Error\nCan't open a directory."

/* PARSING ERROR */
// no map error message
# define EMPTY_ERR "Error\nNo Map was collected."
// player issue message
# define PLAYER_ERR "Error\nCannot have more than one player."
// player issue message
# define PLAYER_POS_ERR "Error\nCheck player position."
// invalid char message
# define CHAR_ERR "Error\nFound an invalid char in the map."
// xpm file error message
# define XPM_ERR "Error\nNot an .xpm or found an invalid char on the line."
// flood fill error message
# define FLOOD_ERR "Error\nMap is not closed."
// same color error message
# define COLOR_ERR "Error\nProvide different colors for the sky & the ground."
// number RGB error message
# define NB_COLOR_ERR "Error\nPlease give a number between 0 and 255."
// RGB format error message
# define FORMAT_ERR "Error\nPlease follow the RGB format."
// element error message
# define ELEMENT_ERR "Error\nProvide 6 elements or insert the right format."
// wrong path format message for textures
# define PATH_ERR "Error\nWrong path for the texture."

/* MLX ERROR */
# define INIT_ERR "Error\nFailed at mlx_init()"

/* FREE FUNCTION UTILITIES */
// Free in the case of error w/ return value + ft_close utils.
int		free_table_err(t_config **conf, char *message, int r_value);
// Free in the case of error with void * return value.
void	*free_void_err(t_config **conf, char *message);
// Free char ** variables.
void	free_double_p(char **table);
/* to rm before push */
void	print_map(char **map);

#endif
