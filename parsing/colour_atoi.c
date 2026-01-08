/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 14:31:50 by mchoma            #+#    #+#             */
/*   Updated: 2026/01/08 15:43:29 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

unsigned int	colour_atoi(char *str, int *err)
{
	unsigned int	rt;
	size_t			i;
	char			*tmp;

	i = 0;
	rt = 0;
	tmp = ft_strtrim(str, " \n");
	if (tmp == NULL)
		return (*err = -1, 0);
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			break ;
		if (ft_isdigit(tmp[i]) == 0)
			return (*err = -1, free(tmp), 0);
		rt = rt * 10 + tmp[i] - '0';
		if (rt > 255)
			return (*err = -1, free(tmp), 0);
		i ++;
	}
	return (free(tmp), rt);
}
