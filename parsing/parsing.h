/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:54:01 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 13:06:09 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"

typedef enum e_map_sqare
{
	EMPTY,
	WALL,
	FLOOR,
	PLAYER,
}	t_sqare;

//takes null terminated filename and ending
//check if sufix is the one given
//return -1 on no 1 on yes
int	file_sufix(char *file_name, char *sufix);

#endif
