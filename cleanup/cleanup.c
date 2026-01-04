/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:08:03 by alvcampo          #+#    #+#             */
/*   Updated: 2026/01/03 17:45:01 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleanup.h"
#include "../libft/libft.h"
void	destroy_textures(t_2d *textures[4], t_mlx *mlx)
{
	printf("%p\n", textures[0]->img_2d);
	if (textures[0] != NULL)
		mlx_destroy_image(mlx->mlx, textures[0]->img_2d);
	if (textures[1] != NULL)
		mlx_destroy_image(mlx->mlx, textures[1]->img_2d);
	if (textures[2] != NULL)
		mlx_destroy_image(mlx->mlx, textures[2]->img_2d);
	if (textures[3] != NULL)
		mlx_destroy_image(mlx->mlx, textures[3]->img_2d);
	free(textures[0]);
	free(textures[1]);
	free(textures[2]);
	free(textures[3]);
}

// void	destroy_emap_alloc(t_parse_data *data)
// {
// 	ssize_t	i;
//
// 	i = -1;
// 	while (++i < data->tall)
// 		free(data->emap[i]);
//
// }
void	cleanup_parse(t_parse_data *data, t_mlx *mlx)
{
	free(data->n_texture);
	free(data->s_texture);
	free(data->w_texture);
	free(data->e_texture);
	if (mlx != NULL)
		destroy_textures(data->textures, mlx);
	free_arr((void***)&data->str_arr_map);
	free_arr((void***) &data->emap);
	free(data);
}
