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
static void	del_prev_textures(t_2d textures[4], t_mlx *mlx, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		mlx_destroy_image(mlx->mlx, textures[j].img_2d);
		j++;
	}
}
int	init_textures(t_2d textures[4], t_parse_data *data, t_mlx *mlx)
{
	int	i;
	int h;
	int w;

	i = 0;
	h = 64;
	w = 64;
	textures[0].texture_path = data->n_texture;
	textures[1].texture_path = data->w_texture;
	textures[2].texture_path = data->s_texture;
	textures[3].texture_path = data->e_texture;
	while (i < 4)
	{
		textures[i].img_2d = mlx_xpm_file_to_image(mlx->mlx,
											 textures[i].texture_path, &w, &h);
		if (!textures[i].img_2d)
			return(del_prev_textures(textures, mlx, i), 0);
		textures[i].addr = mlx_get_data_addr(textures[i].img_2d,
									   &textures[i].bits_per_pixel,
									   &textures[i].line_length,
									   &textures[i].endian);
		i++;
	}
	return (1);
}

