/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_str_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:43:52 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 18:37:10 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char **ft_append_arr_str(char ***arr, char *str)
{
	size_t	i;
	char	**new;
	
	i = 0;
	while (arr && *arr && (*arr)[i])
		i++;
	new = ft_calloc(i + 2, sizeof(char*));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (arr && *arr && (*arr)[i])
	{
		new[i] = (*arr)[i];
		i ++;
	}
	new[i] = str;
	free(*arr);
	*arr = new;
	return (new);
}
