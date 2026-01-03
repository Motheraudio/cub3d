/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:46:29 by alvcampo          #+#    #+#             */
/*   Updated: 2025/12/10 20:48:05 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render_test/render.h"
#include "../raycasting/raycasting.h"
#include "../parsing/parsing.h"

typedef struct s_draw
{
	int	linex;
	int	liney;
	int	starty;
	int	endy;
	int	tex;
	int	tey;
}	t_draw;
void	draw_3d(t_raycast rays[], t_bundle *bundle);
