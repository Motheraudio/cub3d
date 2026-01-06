/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:47:45 by mchoma            #+#    #+#             */
/*   Updated: 2026/01/06 17:37:21 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LOOP_H
# define GAME_LOOP_H
# define FPS 50
# define TURNING_RATE 0.26179
# define MOVEMENT_SPEED 10
# include "../render_test/render.h"
# include "../projection/projection.h"

int		player_move_axis(int *hasmoved, int *y, int *x, char type);
int		handle_keyrelease(int keycode, void *param);
int		handle_keypress(int keycode, void *param);
int		handle_xclick(t_bundle *bundle);
void	init_player(t_player *player);
int		check_move(t_bundle *bundle);
int		check_turn(t_bundle *bundle);
#endif
