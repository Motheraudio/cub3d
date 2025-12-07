/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_to_str_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <your@mail.com>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:33:54 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 18:42:27 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char **fd_to_str_arr(int fd, char ***arr)
{
	int		err;
	char	*str;

	err = 0;
	while (1)
	{
		str = get_next_line(fd, &err);
		if (err == -1)
			return (get_next_line(-1, &err), free_arr((void***) arr), NULL);
		if (str && str[0] == '\n')
		{
			free(str);
			continue;
		}
		ft_append_arr_str(arr, str);
		if (err == 1)
			break;
	}
	return (*arr);
}
