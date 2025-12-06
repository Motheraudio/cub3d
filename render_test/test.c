#include "render.h"

// int	initmlx(t_parrays *parrays, t_mlx *mlx, t_img *img)
// {
// 	if (!mlx->mlx)
// 		return (freeparrays(parrays), 0);
// 	mlx->mlx_win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "FdF");
// 	if (!mlx->mlx_win)
// 		return (freeparrays(parrays), mlx_destroy_display(mlx->mlx),
// 			free(mlx->mlx), 0);
// 	img->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
// 	if (!img->img)
// 		return (freeparrays(parrays),
// 			mlx_destroy_window(mlx->mlx, mlx->mlx_win),
// 			mlx_destroy_display(mlx->mlx), free(mlx->mlx), 0);
// 	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
// 			&img->line_length, &img->endian);
// 	return (1);
// }

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
}

// int		draw_with_offset(t_mlx *mlx, t_img *img)
// {
//
// 	int		x;
// 	int		y;
// 	size_t	i;
// 	size_t	j;
//
// 	i = -1;
// 	x = 0;
// 	y = 0;
// 	while(++i < img->tileamount)
// 	{
// 		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img[i], x, y);
// 		while (j < HEIGHT / 64)
// 		{
// 			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img[i + j], x, y);
// 			y += 64;
// 			j++;
// 		}
// 		j = 0;
// 		x += 64;
// 	}
// 	return (1);
// }

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
	return (1);
}

int main ()
{
	t_img	img;
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		return (print_error("mlx init", 'n'), 1); // Needs a correspondng perror print through function
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Cub3d");
	if (!mlx.mlx_win)
		return (print_error("mlx wimdow", 'n'), mlx_destroy_display(mlx.mlx),
		free(mlx.mlx), 1);
	img.img_height = 64;
	img.img_width = 64;
	if (!create_board(&mlx, &img))
		return (print_error("board creation", 'n'), mlx_destroy_display(mlx.mlx), 
			free(mlx.mlx), 1);
	draw_lines(&mlx, &img);
	mlx_loop(mlx.mlx);



}
