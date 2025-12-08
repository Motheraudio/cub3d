/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:31:41 by alvcampo          #+#    #+#             */
/*   Updated: 2025/12/08 20:22:32 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void where_player2d(t_player *player, t_parse_data *data)
{
	ssize_t	i;
	ssize_t	j;

	i = 1;
	j = 1;
	while (i < data->tall - 1)
	{
		j = 1;
		while (j < data->wide - 1)
		{
			if (data->emap[i][j] == PLAYER)
			{
				player->x = (j- 1) * WALL_LEN + (WALL_LEN / 2);
				player->y = (i - 1) * WALL_LEN + (WALL_LEN / 2);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	set_radian(t_player *player, t_parse_data *data)
{
	if (data->orientation == NORTH)
		player->radian = 0;
	else if (data->orientation == SOUTH)
		player->radian = M_PI;
	else if (data->orientation == EAST)
		player->radian = M_PI / 2;
	else if (data->orientation == WEST)
		player->radian = M_PI + M_PI / 2;
}

int	create_2d_player(t_player *player, t_mlx *mlx, t_parse_data *data)
{
	set_radian(player, data);
	player->image->img_2d = mlx_new_image(mlx->mlx, 1, 1);
	if(!player->image->img_2d)
		return(0);
	player->image->addr = mlx_get_data_addr(player->image->img_2d, &player->image->bits_per_pixel,
								  &player->image->line_length, &player->image->endian);
	where_player2d(player, data);
	my_mlx_pixel_put(player->image, 0,0, 0xFF00008B);
	return (1);
}

int	move_2d_player(t_bundle *bundle, int addx, int addy)
{
	bundle->player->image->img_2d = mlx_new_image(bundle->mlx->mlx, 1, 1);
	if(!bundle->player->image->img_2d)
		return(0);
	bundle->player->image->addr = mlx_get_data_addr(bundle->player->image->img_2d, &bundle->player->image->bits_per_pixel,
								  &bundle->player->image->line_length, &bundle->player->image->endian);
	my_mlx_pixel_put(bundle->player->image, 0,0, 0xFF00008B);
	
	bundle->player->x += addx;
	bundle->player->y += addy;
	return(1);
}
