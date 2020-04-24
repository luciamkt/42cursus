/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:38:53 by ltakahas          #+#    #+#             */
/*   Updated: 2020/02/09 14:49:41 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	if (ft_strlen(s) >= start)
	{
		if (!(res = (char*)malloc((len + 1) * sizeof(char))))
			return (0);
		while (i < len && s[start])
			res[i++] = s[start++];
		res[i] = '\0';
	}
	else
	{
		if (!(res = (char*)malloc(1 * sizeof(char))))
			return (0);
		res[0] = '\0';
	}
	return (res);
}
