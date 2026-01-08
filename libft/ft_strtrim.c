/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchoma <mchoma@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:49:53 by mchoma            #+#    #+#             */
/*   Updated: 2025/12/06 15:11:38 by mchoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	is_in(char c, const char *set)
{
	int	counter;

	counter = -1;
	while (set[++ counter])
	{
		if (set[counter] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s1[i] && (is_in(s1[i], set) == 1))
		i++;
	while (s1[j])
		j++;
	j --;
	while (j < 1000000000 && is_in(s1[j], set) == 1)
		j --;
	str = ft_substr(s1, i, j - i + 1);
	return (str);
}
