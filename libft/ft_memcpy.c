/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvcampo <alvcampo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:04:19 by alvcampo          #+#    #+#             */
/*   Updated: 2025/12/08 18:37:14 by alvcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	while (n > 0)
	{
		*tmp_dst = *tmp_src;
		tmp_dst++;
		tmp_src++;
		n--;
	}
	return (dst);
}
