#include "render.h"
#include "../cleanup/cleanup.h"
void	print_error(char *error, char type)
{
	if (type == 'a')
		errno = EINVAL;
	if (type == '\0')
		return((void)printf("%s\n", error));
	perror(error);
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

// void init_main

int	init_graphics(t_mlx *mlx, t_parse_data *data)
{
	t_2d	minimap;
	t_player player;
	t_2d	player_img;

	player.image = &player_img;
	if (create_minimap(data, mlx, &minimap) == 0)
		return (print_error("Error\nmlx image", 'n'), 
		cleanup_parse(data, NULL), mlx_destroy_window(mlx->mlx, mlx->mlx_win), 
		mlx_destroy_display(mlx->mlx), free(mlx->mlx), 0);
	draw_minimap(&minimap, data);
	if (!init_textures(data, mlx))
		return (print_error("Error\ntextures", 'n'),
		mlx_destroy_image(mlx->mlx, minimap.img_2d),
		cleanup_parse(data, NULL), mlx_destroy_window(mlx->mlx, mlx->mlx_win), 
		mlx_destroy_display(mlx->mlx), free(mlx->mlx), 0);
	if (!create_2d_player(&player, mlx, data))
		return (print_error("Error\ntextures", 'n'),
		mlx_destroy_image(mlx->mlx, minimap.img_2d), cleanup_parse(data, mlx), 
		mlx_destroy_window(mlx->mlx, mlx->mlx_win), 
		mlx_destroy_display(mlx->mlx), free(mlx->mlx), 0);
	mlx_string_put(mlx->mlx, mlx->mlx_win, WIDTH/2, HEIGHT/2, WHITE, 
				"Press any wasd key to start");
	init_game(&minimap, &player, mlx, data);
	return (1);
}
int main (int argc, char **argv)
{
	t_img	img;
	t_mlx	mlx;
	t_parse_data	*data;

	if (argc != 2)
		return (print_error("Error\nargc", 'a'), 1);
	data = parse(argv[1]);
	if (!data)
		return (print_error("Error\nParsing", '\0'), 1); // clean inside parse
	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (print_error("Error\nmlx init", '\0'),
		cleanup_parse(data, NULL), 1);
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Cub3d");
	if (!mlx.mlx_win)
		return (print_error("Error\nmlx window", 'n'),
		mlx_destroy_display(mlx.mlx), cleanup_parse(data, NULL),
		free(mlx.mlx), 1);
	// img.img_height = 64;
	// img.img_width = 64;
	if (!init_graphics(&mlx,data))
		return (1);
}
