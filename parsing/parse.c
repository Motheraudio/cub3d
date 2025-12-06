/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:59:25 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 15:20:17 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parsing.h"
#include <fcntl.h>

void *parse(char *file_name)
{
	t_parse_data	data;
	int				fd;
	
	init_parse_data(&data);
	if (file_sufix(file_name, ".cub") == -1)
		return (NULL); // error handle
	fd = open(file_name, O_RDONLY);
	if(fd == -1)
		return(NULL); //error handle
	if (get_metadata(fd, &data) == -1)
		return (NULL);

	return ((void *)1);
}





