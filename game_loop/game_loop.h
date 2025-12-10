/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:47:45 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/10 15:02:38 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LOOP_H
# define GAME_LOOP_H
# define FPS 50 
# define TURNING_RATE 0.26179
# include "../render_test/render.h"

int	player_move_axis(int *hasmoved, int *y, int *x, char type);
int	handle_keyrelease(int keycode, void *param);
int	handle_keypress(int keycode, void *param);
void init_player(t_player *player);
#endif
