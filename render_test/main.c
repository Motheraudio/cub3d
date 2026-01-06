/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:00:44 by alvcampo          #+#    #+#             */
/*   Updated: 2026/01/06 11:11:30 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "../cleanup/cleanup.h"

void	print_error(char *error, char type)
{
	if (type == 'a')
		errno = EINVAL;
	if (type == '\0')
		return ((void)printf("%s\n", error));
	perror(error);
}

void	destroy_prev_images(t_img *img, t_mlx *mlx, ssize_t last)
{
	ssize_t	i;

	i = -1;
	while (++i <= last)
		mlx_destroy_image(mlx->mlx, img->img[i]);
}

int	create_minimap(t_parse_data *data, t_mlx *mlx, t_2d *minimap)
{
	minimap->img_2d = mlx_new_image(mlx->mlx, data->wide * WALL_LEN,
			data->tall * WALL_LEN);
	if (!minimap->img_2d)
		return (0);
	minimap->addr = mlx_get_data_addr(minimap->img_2d, &minimap->bits_per_pixel,
			&minimap->line_length, &minimap->endian);
	return (1);
}

int	init_graphics(t_mlx *mlx, t_parse_data *data)
{
	t_2d		minimap;
	t_player	player;
	t_2d		player_img;

	player.image = &player_img;
	if (create_minimap(data, mlx, &minimap) == 0)
		return (print_error("Error\nmlx image", 'n'), cleanup_parse(data, NULL),
			mlx_destroy_window(mlx->mlx, mlx->mlx_win),
			mlx_destroy_display(mlx->mlx), free(mlx->mlx), 0);
	draw_minimap(&minimap, data);
	if (!init_textures(data, mlx))
		return (print_error("Error\ntextures", 'n'),
			mlx_destroy_image(mlx->mlx, minimap.img_2d),
			cleanup_parse(data, NULL),
			mlx_destroy_window(mlx->mlx, mlx->mlx_win),
			mlx_destroy_display(mlx->mlx), free(mlx->mlx), 0);
	if (!create_2d_player(&player, mlx, data))
		return (print_error("Error\ntextures", 'n'),
			mlx_destroy_image(mlx->mlx, minimap.img_2d),
			cleanup_parse(data, mlx),
			mlx_destroy_window(mlx->mlx, mlx->mlx_win),
			mlx_destroy_display(mlx->mlx), free(mlx->mlx), 0);
	init_game(&minimap, &player, mlx, data);
	return (1);
}
// clean inside parse needed

int	main(int argc, char **argv)
{
	t_img			img;
	t_mlx			mlx;
	t_parse_data	*data;

	if (argc != 2)
		return (print_error("Error\nargc", 'a'), 1);
	data = parse(argv[1]);
	if (!data)
		return (print_error("Error\nParsing", '\0'), 1);
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (print_error("Error\nmlx init", '\0'),
			cleanup_parse(data, NULL), 1);
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Cub3d");
	if (!mlx.mlx_win)
		return (print_error("Error\nmlx window", 'n'),
			mlx_destroy_display(mlx.mlx), cleanup_parse(data, NULL),
			free(mlx.mlx), 1);
	if (!init_graphics(&mlx, data))
		return (1);
}
