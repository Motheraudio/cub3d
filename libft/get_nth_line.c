/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nth_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:27:39 by alvcampo          #+#    #+#             */
/*   Updated: 2025/12/11 20:34:24 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *get_nth_line(int fd, int line_num)
{
	ssize_t	i;
	char	*line;
	int		err;
	
	i = -1;
	while(++i < line_num)
	{
		line = get_next_line(fd, &err);
		if (!line)
			return (NULL);
		if (i == line_num - 1)
			break ;
		free(line);
	}
	return (line);
}
