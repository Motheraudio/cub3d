/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:29:38 by alvcampo          #+#    #+#             */
/*   Updated: 2025/12/11 19:46:50 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
static void	del_prev_textures(t_2d *textures[4], t_mlx *mlx, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		mlx_destroy_image(mlx->mlx, textures[j]->img_2d);
		j++;
	}
}
int	init_textures(t_parse_data *data, t_mlx *mlx)
{
	int	i;
	int h;
	int w;

	i = 0;
	h = 64;
	w = 64;
	data->textures[0] = malloc(sizeof(t_2d));
	if (!data->textures[0])
		return(0);
	data->textures[1] = malloc(sizeof(t_2d));
	if (!data->textures[1])
		return(free(data->textures[0]), 0);
	data->textures[2] = malloc(sizeof(t_2d));
	if (!data->textures[2])
		return(free(data->textures[0]), free(data->textures[1]), 0);
	data->textures[3] = malloc(sizeof(t_2d));
	if (!data->textures[3])
		return(free(data->textures[0]), free(data->textures[1]), free(data->textures[2]), 0);
	data->textures[0]->texture_path = data->n_texture;
	data->textures[1]->texture_path = data->w_texture;
	data->textures[2]->texture_path = data->s_texture;
	data->textures[3]->texture_path = data->e_texture;
	while (i < 4)
	{
		data->textures[i]->img_2d = mlx_xpm_file_to_image(mlx->mlx,
											 data->textures[i]->texture_path, &w, &h);
		if (!data->textures[i]->img_2d)
			return(del_prev_textures(data->textures, mlx, i), 0);
		data->textures[i]->addr = mlx_get_data_addr(data->textures[i]->img_2d,
									   &data->textures[i]->bits_per_pixel,
									   &data->textures[i]->line_length,
									   &data->textures[i]->endian);
		i++;
	}
	return (1);
}

