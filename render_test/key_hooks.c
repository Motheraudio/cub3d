#include "render.h"
int	noevent(void *mlx)
{
	(void) mlx;
	return (0);
}

int	handle_keypress(int keycode, void *param)
{
	t_player	*player;

	player = (t_player *) param;
	if(keycode == 119)
		player->ctrl->w = 1;
	if(keycode == 97)
		player->ctrl->a = 1;
	if(keycode == 115)
		player->ctrl->s = 1;
	if(keycode == 100)
		player->ctrl->d = 1;
	// if (player->ctrl->w == 1)
	// 	printf("%i\n", player->ctrl->w);
	return (0);
}
int	handle_keyrelease(int keycode, void *param)
{
	t_player	*player;

	player = (t_player *) param;
	if(keycode == 119)
		player->ctrl->w = 0;
	if(keycode == 97)
		player->ctrl->a = 0;
	if(keycode == 115)
		player->ctrl->s = 0;
	if(keycode == 100)
		player->ctrl->d = 0;
	if (keycode == XK_Escape)
		exit(1); // CLEAN!
	// if (player->ctrl->w == 0)
	// 	printf("%i\n", player->ctrl->w);
	return (0);
}

void	game_loop(t_2d *minimap, t_player *player, t_mlx *mlx) // add if you need;
{
	t_wasd	wasd;
	player->ctrl = &wasd;
	// mlx_loop_hook(mlx->mlx,1&noevent, &mlx);
	mlx_hook(mlx->mlx_win, 2, 1L << 0, &handle_keypress, (void *)player);
	mlx_hook(mlx->mlx_win, 3, 1L<< 1, &handle_keyrelease, (void *)player);
	mlx_loop(mlx->mlx);
}
