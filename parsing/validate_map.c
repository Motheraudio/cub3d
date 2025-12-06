/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:05:34 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 18:57:58 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

static t_sqare	**emap_alloc(char **arr)
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
	j = 0;
	while (emap[j])
	{
		emap[j] = ft_calloc(len_horizont + 2, sizeof(t_sqare));
		if (emap[j] == NULL)
			return (free_arr((void ***)& emap), NULL);
		j ++;
	}
	return (emap);
}

t_sqare	**convert_to_enum(char **arr, t_parse_data *data)
{
	
}

int		validate_map(int fd, t_parse_data *data)
{
	char	**arr;
	int		err;
	t_sqare	**emap;
	
	if (fd_to_str_arr(fd, &arr))
		return (get_next_line(-1, &err), -1);
	emap = convert_to_enum(arr, data);


	return (1);
}
