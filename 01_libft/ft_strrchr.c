/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:03:11 by ltakahas          #+#    #+#             */
/*   Updated: 2020/02/01 14:13:59 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen((char*)s);
	if (c == '\0')
		return ((char*)(s + len));
	while (len)
	{
		if (*(s + len - 1) == c)
			return ((char*)(s + len - 1));
		len--;
	}
	return (0);
}
