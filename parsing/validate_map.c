/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:04:53 by mchoma            #+#    #+#             */
/*   Updated: 2026/01/08 15:32:36 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_sqare	**convert_to_enum(char **arr, t_parse_data *data);

/*
void	print_emap(t_parse_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < data->tall)
	{
		j = 0;
		while (j < data->wide)
		{
			if (data->emap[i][j] == EMPTY)
				printf(" ");
			else if (data->emap[i][j] == WALL)
				printf("1");
			else if (data->emap[i][j] == FLOOR)
				printf("0");
			else if (data->emap[i][j] == PLAYER)
			{
				if (data->orientation == WEST)
					printf("W");
				else if (data->orientation == EAST)
					printf("E");
				else if (data->orientation == NORTH)
					printf("N");
				else if (data->orientation == SOUTH)
					printf("S");
				else 
					printf("X");
			}
			j ++;
		}
		printf("\n");
		i ++;
	}

}
*/

int	is_a_valid_sqare(t_parse_data *d, size_t i, size_t j)
{
	if (d->emap[i][j] != EMPTY)
		return (1);
	if ((i != 0 && j != 0) && (d->emap[i - 1][j - 1] == PLAYER
		|| d->emap[i - 1][j - 1] == FLOOR))
		return (-1);
	if ((i != 0) && (d->emap[i - 1][j] == PLAYER || d->emap[i - 1][j] == FLOOR))
		return (-1);
	if ((j != 0) && (d->emap[i][j - 1] == PLAYER || d->emap[i][j - 1] == FLOOR))
		return (-1);
	if ((i < d->tall && j < d->wide)
		&& (d->emap[i + 1][j + 1] == PLAYER || d->emap[i + 1][j + 1] == FLOOR))
		return (-1);
	if ((i < d->tall) && (d->emap[i + 1][j] == PLAYER
		|| d->emap[i + 1][j] == FLOOR))
		return (-1);
	if ((j < d->wide) && (d->emap[i][j + 1] == PLAYER
		|| d->emap[i][j + 1] == FLOOR))
		return (-1);
	if ((i < d->tall && j != 0) && (d->emap[i + 1][j - 1] == PLAYER
		|| d->emap[i + 1][j - 1] == FLOOR))
		return (-1);
	if ((i < 0 && j < d->wide) && (d->emap[i - 1][j + 1] == PLAYER
		|| d->emap[i - 1][j + 1] == FLOOR))
		return (-1);
	return (1);
}

int	map_checker(t_parse_data *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->tall - 1)
	{
		j = 0;
		while (j < data->wide - 1)
		{
			if (is_a_valid_sqare(data, i, j) == -1)
				return (-1);
			j ++;
		}
		i ++;
	}
	return (1);
}

int	split_up_map(t_parse_data *data)
{
	size_t	i;

	i = 0;
	while (data->str_arr_map[i])
	{
		if (ft_strchr(data->str_arr_map[i], '1') != NULL)
			break ;
		i ++;
	}
	while (data->str_arr_map[i] && ft_strchr(data->str_arr_map[i], '1') != NULL)
		i ++;
	while (data->str_arr_map[i] && ft_strchr(data->str_arr_map[i], '1') == NULL)
		i ++;
	if (data->str_arr_map[i] == NULL)
		return (1);
	return (-1);
}

int	validate_map(int fd, t_parse_data *data)
{
	char	**arr;
	int		err;

	arr = NULL;
	if (fd_to_str_arr(fd, &arr) == NULL)
		return (get_next_line(-1, &err), free_arr((void ***) &arr), -1);
	data->str_arr_map = arr;
	if (split_up_map(data) == -1)
		return (get_next_line(-1, &err), -1);
	if (convert_to_enum(arr, data) == NULL)
		return (get_next_line(-1, &err), -1);
	if (map_checker(data) == -1)
		return (get_next_line(-1, &err), -1);
	return (1);
}
