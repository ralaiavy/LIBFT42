/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fralaiav <fralaiav@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 02:12:26 by fralaiav          #+#    #+#             */
/*   Updated: 2026/02/13 00:01:51 by fralaiav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t	size)
{
	size_t	i;
	size_t	j;
	size_t	dest;

	dest = ft_strlen(dst);
	if (size <= dest)
		return (size + ft_strlen(src));
	i = dest;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i ++;
		j ++;
	}
	dst[i] = '\0';
	return (dest + ft_strlen(src));
}
