/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:46:19 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/08 20:48:27 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render_test/render.h"

int	player_move_axis(int *hasmoved, int *y, int *x, char type)
{
	*hasmoved += 1;
	if (type == 'w')
		return (*x = 0, *y = -1, 1);
	if (type == 's')
		return (*x = 0, *y = +1, 1);
	if (type == 'a')
		return (*x = -1, *y = 0, 1);
	if (type == 'd')
		return (*x = +1, *y = 0, 1);
	return (0);
}

