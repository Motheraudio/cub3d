/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:54:27 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/08 21:13:21 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H
# define RAY_LEN 20

#include "../render_test/render.h"

void	raycasting(t_raycast *arr, t_player *player, t_2d *minimap);

#endif
