/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_orientation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:50:26 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/10 21:33:26 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "render.h"

unsigned int	get_orientation(unsigned int colour)
{
	unsigned int	mask;

	mask = 0xFFFF00;
	colour = colour & mask;
	return (colour);
}

unsigned int	slice(unsigned int colour)
{
	unsigned int	mask;

	mask = 0xFFFF00;
	colour = colour & ~mask;
	return (colour);
}

int	get_texture_index(unsigned int orient)
{
	if (orient == NORTH_C)
		return (0);
	if (orient == WEST_C)
		return (1);
	if (orient == SOUTH_C)
		return (2);
	if (orient == EAST_C)
		return (3);
	return (0);
}
