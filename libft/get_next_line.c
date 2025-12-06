/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:53:44 by mchoma            #+#    #+#             */
/*   Updated: 2025/05/20 13:53:51 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
// strjoin but frees the second argument
// ssize_t ft_read(int fd, void *buf, size_t nbyte);
char	*strjoinf2(char *buff, char *str)
{
	ssize_t	i[2];
	char	*fin;

	i[0] = 0;
	i[1] = 0;
	while (str && str[i[0]])
		i[0]++;
	while (buff && buff[i[1]])
		i[1]++;
	fin = malloc((i[1] + i[0] + 1) * sizeof(char));
	if (fin == NULL)
		return (free(str), NULL);
	i[1] = 0;
	while (buff && buff [i[1]++])
		fin[i[0] + i[1] - 1] = buff[i[1] - 1];
	i[0] = 0;
	while (str && str[i[0]++])
		fin[i[0] - 1] = str[i[0] - 1];
	fin[i[0] + i[1] - 2 + (str == NULL) + (buff == NULL)] = 0;
	free(str);
	return (fin);
}

int	initialize(t_data *data)
{
	data->tmp = NULL;
	data->rt = NULL;
	data->buff = malloc(BUFFER_SIZE + 1);
	if (data->buff == NULL)
		return (-1);
	data->readcounter = BUFFER_SIZE;
	data->i1 = 0;
	return (1);
}

void	freeall(t_data *data, char **str)
{
	free(data->tmp);
	data->tmp = NULL;
	free(data->rt);
	data->rt = NULL;
	free(*str);
	*str = NULL;
	free(data->buff);
	data->buff = NULL;
}

char	*nfound(t_data *data, char **str)
{
	data->i1 --;
	data->rt = ft_substr(*str, 0, data->i1 + 1);
	if (data->rt == NULL)
		return (freeall(data, str), NULL);
	data->tmp = ft_substr(*str, data->i1 + 1, BUFFER_SIZE + 1);
	if (data->tmp == NULL)
		return (freeall(data, str), NULL);
	free(*str);
	*str = data->tmp;
	return (free(data->buff), data->rt);
}

char	*get_next_line(int fd, int *err)
{
	static char	*str = NULL;
	t_data		data[1];

	if (-1 == initialize(data))
		return (freeall(data, &str), *err = -1,NULL);
	if (fd == -1)
		return (*err = 0, freeall(data, &str), NULL);
	while (1)
	{
		while (str && str[data->i1])
			if (str[data->i1 ++] == '\n')
				return (*err = 0, nfound(data, &str));
		data->readcounter = read(fd, data->buff, BUFFER_SIZE);
		if (data->readcounter == -1)
			return (freeall(data, &str), NULL);
		if (data->readcounter == 0)
			return (data->rt = str, str = NULL, free(data->buff), *err = 0, data->rt);
		data->buff[data->readcounter] = 0;
		str = strjoinf2(data->buff, str);
		if (str == NULL)
			return (freeall(data, &str), *err = -1, NULL);
	}
}
