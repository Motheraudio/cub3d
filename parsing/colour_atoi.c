/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 14:31:50 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 14:43:05 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "parsing.h"

int	colour_atoi(char *str, int *err)
{
	int		rt;
	size_t	i;

	i = 0;
	rt = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 0)
		{
			*err = -1;
			return (0);
		}
		rt = rt * 10 + str[i] - '0';
		if (rt > 255)
		{
			*err = -1;
			return (0);
		}
		i ++;
	}
	return (rt);
}
