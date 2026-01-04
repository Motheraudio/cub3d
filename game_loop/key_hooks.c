/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 20:47:13 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/10 14:50:53 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../render_test/render.h"
#include "../cleanup/cleanup.h"

int	handle_keypress(int keycode, void *param)
{
	t_bundle	*bundle;

	bundle = (t_bundle *) param;
	if(keycode == 119)
		bundle->player->ctrl.w = 1;
	if(keycode == 97)
		bundle->player->ctrl.a = 1;
	if(keycode == 115)
		bundle->player->ctrl.s = 1;
	if(keycode == 100)
		bundle->player->ctrl.d = 1;
	if(keycode == 65361)
		bundle->player->ctrl.left = 1;
	if(keycode == 65363)
		bundle->player->ctrl.right = 1;
	if (keycode == XK_Escape)
	{
		cleanup_parse(bundle->data, bundle->mlx);
		mlx_destroy_image(bundle->mlx->mlx, bundle->player->image->img_2d);
		mlx_destroy_image(bundle->mlx->mlx, bundle->view->img_2d);
		mlx_destroy_image(bundle->mlx->mlx, bundle->minimap->img_2d);
		mlx_destroy_window(bundle->mlx->mlx, bundle->mlx->mlx_win);
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
		bundle->player->ctrl.w = 0;
	if(keycode == 97)
		bundle->player->ctrl.a = 0;
	if(keycode == 115)
		bundle->player->ctrl.s = 0;
	if(keycode == 100)
		bundle->player->ctrl.d = 0;
	if(keycode == 65361)
		bundle->player->ctrl.left = 0;
	if(keycode == 65363)
		bundle->player->ctrl.right = 0;
	// if (player->ctrl->w == 1)
	// 	printf("%i\n", player->ctrl->w);
	return (0);

}
