/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:54:27 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/10 21:50:10 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# define RAY_LEN 1920
# define RAYCAST_ARR 960

#include "../render_test/render.h"

void	raycasting(t_raycast *arr, t_player *player, t_2d *minimap);

#endif
