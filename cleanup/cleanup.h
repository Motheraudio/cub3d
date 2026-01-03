/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:50:36 by alvcampo          #+#    #+#             */
/*   Updated: 2026/01/03 16:52:26 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H
# include "../parsing/parsing.h"
# include "../render_test/render.h"


void	destroy_extures(t_2d *textures[4], t_mlx *mlx);
// cleans up all parsing struct members, and the parsing itself. If the mlx
// struct pointer is set to NULL, it does not free the 4 texture images.
void	cleanup_parse(t_parse_data *data, t_mlx *mlx);
#endif
