/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:59:25 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 20:14:36 by mchoma           ###   ########.fr       */
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
	printf("after file suffix\n");
	fd = open(file_name, O_RDONLY);
	if(fd == -1)
		return(NULL); //error handle
	printf("after open\n");
	if (get_metadata(fd, &data) == -1)
		return (NULL);
	printf("after metadata\n");
	if (validate_map(fd, &data) == -1)
		return (NULL);
	printf("after valideate map\n");

	return ((void *)1);
}
