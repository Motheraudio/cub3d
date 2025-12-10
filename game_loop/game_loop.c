/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:46:04 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/10 17:22:23 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render_test/render.h"
#include <sys/time.h>
#include "game_loop.h"
#include "../raycasting/raycasting.h"

int	nex_frame()
{
	static	struct timeval prev;
	struct timeval	now;

	gettimeofday(&now, NULL);
	if ((now.tv_sec * 1000 + now.tv_usec / 1000) > (prev.tv_sec * 1000 + prev.tv_usec / 1000) + FPS)
	{
		prev = now;
		return (1);
	}
	return (-1);
}

int		player_movement(t_bundle *bundle)
{
	int	hasmoved;
	int	hasturned;
	int	xadd;
	int	yadd;

	hasmoved = check_move(bundle);
	hasturned = check_turn(bundle);
	if (hasmoved != 0)
	{
		xadd = MOVEMENT_SPEED * cos(bundle->player->radian + bundle->player->direction);
		yadd = MOVEMENT_SPEED * sin(bundle->player->radian + bundle->player->direction);
		move_2d_player(bundle, xadd, yadd);
		return (1);
	}
	if (hasturned == 1)
		return (1);
	return (0);
}

int	game_loop(void *param)
{
	t_bundle	*bundle;
	int			has_moved;
	t_raycast	arr[RAYCAST_ARR];

	if (nex_frame() == -1)
		return (0);
	bundle = (t_bundle *)param;
	has_moved = player_movement(bundle);
	if (has_moved == 1)
	{
		// mlx_clear_window(bundle->mlx->mlx, bundle->mlx->mlx_win);
		draw_minimap(bundle->minimap, bundle->data);
		raycasting(arr, bundle->player, bundle->minimap);
		mlx_put_image_to_window(bundle->mlx->mlx, bundle->mlx->mlx_win, bundle->minimap->img_2d, 0, 0);
		mlx_put_image_to_window(bundle->mlx->mlx, bundle->mlx->mlx_win, bundle->player->image->img_2d, bundle->player->x, bundle->player->y + 1);
	}
	return (0);
}




void	init_game(t_2d *minimap, t_player *player, t_mlx *mlx, t_parse_data *data) // add if you need;
{
	t_bundle bundle;

	// mlx_do_key_autorepeatoff(mlx->mlx);
	init_player(player);
	bundle.player = player;
	bundle.minimap = minimap;
	bundle.data = data;
	bundle.mlx = mlx;
	mlx_hook(mlx->mlx_win, 2, 1L << 0, handle_keypress, (void *)&bundle);
	mlx_hook(mlx->mlx_win, 3, 1L<< 1, handle_keyrelease, (void *)&bundle);
	mlx_loop_hook(mlx->mlx, game_loop, &bundle);
	mlx_loop(mlx->mlx);
}
