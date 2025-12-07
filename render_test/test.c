#include "render.h"
void	print_error(char *error, char type)
{
	if (type == 'n')
		return ((void)perror(error));
	errno = 0;
}

void	draw_line_horizontal(t_mlx *mlx, t_img *img, int y)
{
	ssize_t	i;
	int	pos_x;
	int	pos_y;

	i = -1;
	pos_x = 0;
	pos_y = y * TILESIZE;
	while(++i < img->x_tilecount)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img[i], pos_x, pos_y);
		pos_x += TILESIZE;
	}
}

void	draw_lines(t_mlx *mlx, t_img *img)
{
	ssize_t	i;

	i = -1;
	while(++i < img->y_tilecount)
		draw_line_horizontal(mlx, img, i);
	img->player_posx = WIDTH / 2;
	img->player_posy = HEIGHT / 2;
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->player, img->player_posx, img->player_posy);

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
		img->img[i] = mlx_xpm_file_to_image(mlx->mlx, "./texture.xpm",
									  &img->img_width, &img->img_height);
		if (img->img[i] == NULL)
			return (destroy_prev_images(img, mlx, i), free(img->img), 0);
	}
	img->player_width = 16;
	img->player_height = 16;
	img->player = mlx_xpm_file_to_image(mlx->mlx, "./player.xpm",&img->player_width, &img->player_height);
	if (!img->player)
		return(destroy_prev_images(img, mlx, i + 1), free(img->img), 0);
	return (1);
}

void	draw_horizon_mm(t_2d *minimap, int y, int x, unsigned int color)
{
	ssize_t	i;

	i = -1;
	while(++i < minimap->blockx)
	{
		my_mlx_pixel_put(minimap, x + i, y, color);
	}
}

void	draw_square_in_image(t_2d *minimap, unsigned int color, int x, int y)
{
	ssize_t	i;

	i = -1;
	x *= minimap->blockx;
	y *=minimap->blocky;
	while (++i < minimap->blocky)
		draw_horizon_mm(minimap, x, y + i, color);
}

void	draw_wall_when (size_t i, size_t j, t_2d *minimap, t_parse_data *data)
{
	if (i == 1)
		draw_square_in_image(minimap, WHITE, i, j);
	else if (i == data->tall - 1)
		draw_square_in_image(minimap, RED, i, j);
	else if (j == 1)
		draw_square_in_image(minimap, BLUE, i, j);
	else 
		draw_square_in_image(minimap, GREEN, i, j);

}


void	draw_cols(t_2d *minimap, t_parse_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	minimap->x1 = 0;
	minimap->y1 = 0;
	minimap->x2 = 0;
	minimap->y2 = TILESIZE;
	while (j < data->tall - 1)
	{
		while (i < data->wide - 1)
		{
			algo(minimap, data);
			minimap->y1 = minimap->y2;
			minimap->y2 += TILESIZE;
			i++;
		}
		minimap->x1 = minimap->x2;
		minimap->x2 += TILESIZE;
		j++;
	}
}
int	create_minimap(t_parse_data *data, t_mlx *mlx, t_2d *minimap)
{
	// ssize_t	i;
	// ssize_t	j;
	//
	// i = 1;
	// j = 1;
	minimap->sizex = data->wide * WALL_LEN; //* 10;
	minimap->sizey = data->tall * WALL_LEN; //* 10;
	minimap->blockx = TILESIZE;
	minimap->blocky = TILESIZE;
	minimap->x1 = 0;
	minimap->y1 = 0;
	minimap->x2 = TILESIZE;
	minimap->y2 = TILESIZE;
	minimap->img_2d = mlx_new_image(mlx->mlx, minimap->sizex, minimap->sizey);
	if (!minimap->img_2d)
		return (0);
	minimap->addr = mlx_get_data_addr(minimap->img_2d, &minimap->bits_per_pixel,
							&minimap->line_length, &minimap->endian);
	// draw_cols(minimap, data);
		return (1);
}


int main (int argc, char **argv)
{
	t_img	img;
	t_mlx	mlx;
	t_parse_data	*data;
	t_2d	minimap;

	if (argc != 2)
		return (1);
	data = parse(argv[1]);
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
	// if (!create_board(&mlx, &img))
	// 	return (print_error("board creation", 'n'), mlx_destroy_display(mlx.mlx),
	// 		free(mlx.mlx), 1);
	// draw_minimap(data, &mlx, &minimap);
	create_minimap(data, &mlx, &minimap);
	draw_minimap(&minimap, data);

	t_line line;
	// line.x1 = 0;
	// line.y1 = 0;
	// line.x2 = 200;
	// line.y2 = 100;
	// line.colour = WHITE;
	// draw_line(&minimap, &line);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, minimap.img_2d, 0, 0);
	mlx_loop(mlx.mlx);
}
