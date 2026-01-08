/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:54:01 by mchoma            #+#    #+#             */
/*   Updated: 2026/01/08 15:27:57 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
typedef struct s_2d t_2d;

typedef enum s_map_sqare
{
	EMPTY,
	WALL,
	FLOOR,
	PLAYER,
}	t_sqare;

typedef enum s_compas
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	UNI,
} e_compas;

typedef struct s_colour{
	unsigned int r;
	unsigned int g;
	unsigned int b;
}	t_colour;

typedef struct s_parse_data{
	char		*n_texture;
	char		*s_texture;
	char		*w_texture;
	char		*e_texture;
	t_2d		*textures[4];
	t_colour	celing;
	int			celing_set;
	t_colour	floor;
	int			floor_set;
	char		**str_arr_map;
	t_sqare		**emap;
	size_t		wide;
	size_t		tall;
	e_compas	orientation;
}	t_parse_data;

//takes null terminated filename and ending
//check if sufix is the one given
//return -1 on no 1 on yes
int	file_sufix(char *file_name, char *sufix);

int		get_metadata(int fd, t_parse_data *data);


//sets char *ptr to NULL and celing set and floor set to 0
void	init_parse_data(t_parse_data *data);


void *parse(char *str);


int	floor_line(char *line, t_parse_data *data);
int	celing_line(char *line, t_parse_data *data);
int	west_line(char *line, t_parse_data *data);
int	east_line(char *line, t_parse_data *data);
int	north_line(char *line, t_parse_data *data);
int	south_line(char *line, t_parse_data *data);

unsigned int	colour_atoi(char *str, int *err);

int		validate_map(int fd, t_parse_data *data);
void	print_parse_data(t_parse_data *data);
int		validate_map(int fd, t_parse_data *data);
void	print_emap(t_parse_data *data);
#endif
