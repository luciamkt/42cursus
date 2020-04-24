/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:58:49 by ltakahas          #+#    #+#             */
/*   Updated: 2020/02/02 13:44:02 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ret;
	size_t	dstlen;

	i = 0;
	j = 0;
	ret = 0;
	while (dst[i] != '\0' && i < dstsize)
		i++;
	dstlen = i;
	while (src[j] != '\0' && i < dstsize - 1 && dstsize > 0)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (dstsize > i)
		dst[i] = '\0';
	while (src[ret] != '\0')
		ret++;
	return (ret + dstlen);
}
