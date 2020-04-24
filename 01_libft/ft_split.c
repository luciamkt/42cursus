/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:20:29 by ltakahas          #+#    #+#             */
/*   Updated: 2020/02/09 14:51:00 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_nb(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static int	str_len(char const *s, char c, int i)
{
	int	j;

	j = i;
	while (s[j] && s[j] != c)
		j++;
	return (j - i);
}

static int	copy_str(char *copy, char const *s, char c, int i)
{
	int k;
	int end;

	k = 0;
	end = i + str_len(s, c, i);
	while (i < end)
	{
		copy[k] = s[i];
		i++;
		k++;
	}
	copy[k] = '\0';
	return (end);
}

char		**ft_split(char const *s, char c)
{
	char	**res;
	int		strs;
	int		i;
	int		j;

	if (!s)
		return (0);
	strs = str_nb(s, c);
	if (!(res = (char**)malloc((strs + 1) * sizeof(char*))))
		return (0);
	i = 0;
	j = 0;
	while (j < strs)
	{
		while (s[i] == c && s[i])
			i++;
		if (!(res[j] = (char*)malloc((str_len(s, c, i) + 1) * sizeof(char))))
			return (0);
		i = copy_str(res[j], s, c, i);
		j++;
	}
	res[j] = 0;
	return (res);
}
