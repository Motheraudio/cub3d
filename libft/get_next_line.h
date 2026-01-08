/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 01:19:37 by mchoma            #+#    #+#             */
/*   Updated: 2025/05/14 01:19:37 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4230
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_data
{
	char	*buff;
	char	*tmp;
	char	*rt;
	ssize_t	readcounter;
	ssize_t	i1;
}	t_data;

char	*ft_substr(char const *s, unsigned int start, size_t len);
//takes file descriptor and adress of int
//will return malloced string that is one line from the file
//in err it gives errror if err is set to -1 it is error 
//if err = 0 no error ecountered
//if fd = -1 
char	*get_next_line(int fd, int *err);

#endif
