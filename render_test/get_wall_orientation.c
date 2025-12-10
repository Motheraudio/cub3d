/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_orientation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:50:26 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/10 21:00:09 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	get_orientation(unsigned int colour)
{
	unsigned int	mask;

	mask = 0xFFFF00;
	colour = colour & mask;
	return (colour);
}
