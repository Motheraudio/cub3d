/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */ /*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:05:34 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 20:32:49 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

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

static t_sqare	**emap_alloc(char **arr, t_parse_data  *data)
{
	size_t	j;
	size_t	len_horizont;
	size_t	tmp;
	t_sqare	**emap;

	len_horizont = 0;
	j = 0;
	while (arr[j])
	{
		tmp = ft_strlen(arr[j]);
		if (len_horizont < tmp)
			len_horizont = tmp;
		j++;
	}
	emap = ft_calloc(j + 3, sizeof(t_sqare *));
	if (emap == NULL)
		return (NULL);
	data->wide = len_horizont + 2;
	data->tall = j + 1;
	j = 0;
	while (j <  data->tall)
	{
		emap[j] = ft_calloc(len_horizont + 2, sizeof(t_sqare));
		if (emap[j] == NULL)
			return (free_arr((void ***)& emap), NULL);
		j++;
	}
	return (emap);
}

t_sqare	**convert_to_enum(char **arr, t_parse_data *data)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	data->emap = emap_alloc(arr, data);
	if (data->emap == NULL)
		return (NULL);
	while(arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '1')
				data->emap[i + 1][j + 1] = WALL;
			else if (arr[i][j] == '0')
				data->emap[i + 1][j + 1] = FLOOR;
			else if (arr[i][j] == ' ')
				data->emap[i + 1][j + 1] = EMPTY;
			else if (arr[i][j] == 'W')
			{
				data->emap[i + 1][j + 1] = PLAYER;
				if (data->orientation != UNI)
					return (NULL);
				data->orientation = WEST;
			}
			else if (arr[i][j] == 'E')
			{
				data->emap[i + 1][j + 1] = PLAYER;
				if (data->orientation != UNI)
					return (NULL);
				data->orientation = EAST;
			}
			else if (arr[i][j] == 'N')
			{
				data->emap[i + 1][j + 1] = PLAYER;
				if (data->orientation != UNI)
					return (NULL);
				data->orientation = NORTH;
			}
			else if (arr[i][j] == 'S')
			{
				data->emap[i + 1][j + 1] = PLAYER;
				if (data->orientation != UNI)
					return (NULL);
				data->orientation = SOUTH;
			}
			else if (arr[i][j] != '\n')
				return (NULL);
			j ++;
		}
		i ++;
	}
	return (data->emap);
}

int	is_a_valid_sqare(t_parse_data *data, size_t i, size_t j)
{
	if (data->emap[i][j] != EMPTY)
		return (1);
	if ((i != 0 && j != 0) && (data->emap[i - 1][j - 1] == PLAYER || data->emap[i - 1][j - 1] == FLOOR))
			return (-1);
	if ((i != 0) && (data->emap[i - 1][j] == PLAYER || data->emap[i - 1][j] == FLOOR))
			return (-1);
	if ((j != 0) && (data->emap[i][j - 1] == PLAYER || data->emap[i][j - 1] == FLOOR))
			return (-1);
	if ((i < data->tall && j < data->wide) && (data->emap[i + 1][j + 1] == PLAYER || data->emap[i + 1][j + 1] == FLOOR))
			return (-1);
	if ((i < data->tall) && (data->emap[i + 1][j] == PLAYER || data->emap[i + 1][j] == FLOOR))
			return (-1);
	if ((j < data->wide) && (data->emap[i][j + 1] == PLAYER || data->emap[i][j + 1] == FLOOR))
			return (-1);
	if ((i < data->tall && j != 0) && (data->emap[i + 1][j - 1] == PLAYER || data->emap[i + 1][j - 1] == FLOOR))
			return (-1);
	if ((i < 0 && j < data->wide) && (data->emap[i - 1][j + 1] == PLAYER || data->emap[i - 1][j + 1] == FLOOR))
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


int		validate_map(int fd, t_parse_data *data)
{
	char	**arr;
	int		err;
	
	arr = NULL;
	if (fd_to_str_arr(fd, &arr) == NULL)
		return (get_next_line(-1, &err), -1);
	if (convert_to_enum(arr, data) == NULL)
		return (-1); //manage error and allocations
	if (map_checker(data) == -1)
		return (-1);
	print_emap(data);
	return (1);
}
