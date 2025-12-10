/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 14:44:06 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/10 14:48:00 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"
#include "../render_test/render.h"

void init_player(t_player *player)
{
	player->ctrl.a = 0;
	player->ctrl.w = 0;
	player->ctrl.s = 0;
	player->ctrl.d = 0;
	player->ctrl.left = 0;
	player->ctrl.right = 0;
}
