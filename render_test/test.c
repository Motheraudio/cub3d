#include "render.h"
void	print_error(char *error, char type)
{
	if (type == 'n')
		return ((void)perror(error));
	errno = 0;
}


void	destroy_prev_images (t_img *img, t_mlx *mlx, ssize_t last)
{
	ssize_t	i;

	i = -1;
	while(++i <= last)
		mlx_destroy_image(mlx->mlx, img->img[i]);
}


int	create_board(t_mlx *mlx, t_img *img)
{
	ssize_t	i;

	i = -1;
	img->x_tilecount =  WIDTH / TILESIZE;
	img->y_tilecount = HEIGHT / TILESIZE;
	img->tileamount = img->x_tilecount * img->y_tilecount;
	img->img = malloc(img->tileamount * sizeof(void *));
	if (!img->img)
		return (0);
	while(++i < img->tileamount)
	{
		img->img[i] = mlx_xpm_file_to_image(mlx->mlx, "render_test/texture.xpm",
									  &img->img_width, &img->img_height);
		if (img->img[i] == NULL)
			return (destroy_prev_images(img, mlx, i), free(img->img), 0);
	}
	img->player_width = 16;
	img->player_height = 16;
	img->player = mlx_xpm_file_to_image(mlx->mlx, "render_test/player.xpm",&img->player_width, &img->player_height);
	if (!img->player)
		return(destroy_prev_images(img, mlx, i + 1), free(img->img), 0);
	return (1);
}


int	create_minimap(t_parse_data *data, t_mlx *mlx, t_2d *minimap)
{
	minimap->img_2d = mlx_new_image(mlx->mlx, data->wide * WALL_LEN, data->tall * WALL_LEN);
	if (!minimap->img_2d)
		return (0);
	minimap->addr = mlx_get_data_addr(minimap->img_2d, &minimap->bits_per_pixel,
							&minimap->line_length, &minimap->endian);
		return (1);
}

int main (int argc, char **argv)
{
	t_img	img;
	t_mlx	mlx;
	t_parse_data	*data;
	t_2d	minimap;
	t_line line;
	t_player player;
	t_2d	player_img;
	t_2d	textures[4];

	player.image = &player_img;
	// if (argc != 2)
		// return (1);
	// data = parse(argv[1]);
	data = parse("files/test1.cub");
	if (!data)
		return (1); // needs free;
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (print_error("mlx init", 'n'), 1);
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Cub3d");
	if (!mlx.mlx_win)
		return (print_error("mlx wimdow", 'n'), mlx_destroy_display(mlx.mlx),
		free(mlx.mlx), 1);
	img.img_height = 64;
	img.img_width = 64;
	if (create_minimap(data, &mlx, &minimap) == 0)
		return (print_error("mlx image", 'n'), mlx_destroy_display(mlx.mlx),
		free(mlx.mlx), 1);
	draw_minimap(&minimap, data);
	// init_textures(data, &mlx); <- this segfaults. Fix it!
	if (!create_2d_player(&player, &mlx, data))
		return (1); // meeds free
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, minimap.img_2d, 0, 0);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, player.image->img_2d, player.x, player.y);
	init_game(&minimap, &player, &mlx, data);
}
