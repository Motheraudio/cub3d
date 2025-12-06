/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:00:51 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 13:05:53 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int	file_sufix(char *file_name, char *sufix)
{
	size_t	i;
	size_t	j;
	
	i = ft_strlen(file_name);
	j = ft_strlen(sufix);

	while (j >= 0 && i >= 0)
	{
		if (!(file_name[i] == sufix[j]))
			return (-1);
		i --;
		j --;
	}
	return (1);
}
