#include "render.h"
#include <sys/time.h>

int	nex_frame()
{
	static	struct timeval prev;
	struct timeval	now;

	gettimeofday(&now, NULL);
	if ((now.tv_sec * 100 + now.tv_usec / 10000) > (prev.tv_sec * 100 + prev.tv_usec / 10000) + 100 / 5)
	{
		prev = now;
		return (1);
	}
	return (-1);
}

int	player_move_axis(int *hasmoved, int *y, int *x, char type)
{
	*hasmoved += 1;
	if (type == 'w')
		return (*x = 0, *y = -1, 1);
	if (type == 's')
		return (*x = 0, *y = +1, 1);
	if (type == 'a')
		return (*x = -1, *y = 0, 1);
	if (type == 'd')
		return (*x = +1, *y = 0, 1);
	return (0);
}
int	move_player(void *param)
{
	t_bundle *bundle;
	int		hasmoved;
	int		yadd;
	int		xadd;

	if (nex_frame() == -1)
		return (0);
	hasmoved = 0;
	bundle = (t_bundle *)param;
	if (bundle->player->ctrl->w == 1)
		player_move_axis(&hasmoved, &yadd, &xadd, 'w');
	if (bundle->player->ctrl->a == 1)
		player_move_axis(&hasmoved, &yadd, &xadd, 'a');
	if (bundle->player->ctrl->s == 1)
		player_move_axis(&hasmoved, &yadd, &xadd, 's');
	if (bundle->player->ctrl->d == 1)
		player_move_axis(&hasmoved, &yadd, &xadd, 'd');
	if (hasmoved == 1)
	{
		mlx_destroy_image(bundle->mlx->mlx, bundle->player->image->img_2d);
		mlx_clear_window(bundle->mlx->mlx, bundle->mlx->mlx_win);
		if(!move_2d_player(bundle, xadd, yadd))
			return(0); //needs cleanup lol
		mlx_put_image_to_window(bundle->mlx->mlx, bundle->mlx->mlx_win, bundle->minimap->img_2d, 0, 0);
		mlx_put_image_to_window(bundle->mlx->mlx, bundle->mlx->mlx_win, bundle->player->image->img_2d, bundle->player->x, bundle->player->y + 1);
		hasmoved = 0;
	}
	return (0);
}

int	handle_keypress(int keycode, void *param)
{
	t_bundle	*bundle;

	bundle = (t_bundle *) param;
	if(keycode == 119)
		bundle->player->ctrl->w = 1;
	if(keycode == 97)
		bundle->player->ctrl->a = 1;
	if(keycode == 115)
		bundle->player->ctrl->s = 1;
	if(keycode == 100)
		bundle->player->ctrl->d = 1;
	if (keycode == XK_Escape)
	{
		mlx_destroy_display(bundle->mlx->mlx);
		free(bundle->mlx->mlx);
		exit(1);
	}
	return (0);
}
int	handle_keyrelease(int keycode, void *param)
{
	t_bundle	*bundle;

	// printf("keyrelease\n");
	bundle = (t_bundle *) param;
	if(keycode == 119)
		bundle->player->ctrl->w = 0;
	if(keycode == 97)
		bundle->player->ctrl->a = 0;
	if(keycode == 115)
		bundle->player->ctrl->s = 0;
	if(keycode == 100)
		bundle->player->ctrl->d = 0;
	// if (player->ctrl->w == 1)
	// 	printf("%i\n", player->ctrl->w);
	return (0);

}

void	game_loop(t_2d *minimap, t_player *player, t_mlx *mlx, t_parse_data *data) // add if you need;
{
	t_bundle bundle;
	t_wasd	wasd;

	// mlx_do_key_autorepeatoff(mlx->mlx);
	mlx_do_key_autorepeaton(mlx->mlx);
	player->ctrl = &wasd;
	player->ctrl->w = 0;
	player->ctrl->a = 0;
	player->ctrl->s = 0;
	player->ctrl->d = 0;
	bundle.player = player;
	bundle.minimap = minimap;
	bundle.data = data;
	bundle.mlx = mlx;
	mlx_hook(mlx->mlx_win, 2, 1L << 0, handle_keypress, (void *)&bundle);
	mlx_hook(mlx->mlx_win, 3, 1L<< 1, handle_keyrelease, (void *)&bundle);
	mlx_loop_hook(mlx->mlx,move_player, &bundle);
	mlx_loop(mlx->mlx);
}
