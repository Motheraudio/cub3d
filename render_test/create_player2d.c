/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:31:41 by alvcampo          #+#    #+#             */
/*   Updated: 2025/12/08 15:32:54 by alvcampo         ###   ########.fr       */
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
int	create_2d_player(t_player *player, t_mlx *mlx, t_parse_data *data)
{
	player->image->img_2d = mlx_new_image(mlx->mlx, 1, 1);
	if(!player->image->img_2d)
		return(0);
	player->image->addr = mlx_get_data_addr(player->image->img_2d, &player->image->bits_per_pixel,
								  &player->image->line_length, &player->image->endian);
	where_player2d(player, data);
	my_mlx_pixel_put(player->image, 0,0, 0xFF00008B);
	return (1);
}

