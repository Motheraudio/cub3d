/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:46:19 by mchoma            #+#    #+#             */
/*   Updated: 2026/01/06 17:42:08 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"

int	check_turn(t_bundle *bundle)
{
	int	ret;

	ret = 0;
	if (bundle->player->ctrl.right == 1)
	{
		bundle->player->radian += TURNING_RATE;
		ret = 1;
	}
	if (bundle->player->ctrl.left == 1)
	{
		bundle->player->radian -= TURNING_RATE;
		ret = 1;
	}
	return (ret);
}

int	check_move(t_bundle *bundle)
{
	int	ret;

	ret = 0;
	bundle->player->direction = 0;
	if (bundle->player->ctrl.a == 1)
		ret ++;
	if (bundle->player->ctrl.s == 1)
	{
		ret ++;
		bundle->player->direction += M_PI + M_PI_2;
	}
	if (bundle->player->ctrl.w == 1)
	{
		ret ++;
		bundle->player->direction += M_PI_2;
	}
	if (bundle->player->ctrl.d == 1)
	{
		ret ++;
		bundle->player->direction += M_PI;
	}
	return (ret);
}
