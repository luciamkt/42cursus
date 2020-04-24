/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:43:55 by ltakahas          #+#    #+#             */
/*   Updated: 2020/02/09 12:21:09 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	unsigned int	nb;
	int				count;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	count = 1;
	while (nb >= 10)
	{
		count++;
		nb = nb / 10;
	}
	if (n < 0)
		count++;
	return (count);
}

char		*ft_itoa(int n)
{
	unsigned int	nb;
	int				count;
	char			*res;

	count = ft_len(n);
	if (!(res = (char*)malloc((count + 1) * sizeof(char))))
		return (0);
	if (n < 0)
		nb = -n;
	else
		nb = n;
	res[count] = '\0';
	while (count)
	{
		res[count - 1] = nb % 10 + '0';
		nb = nb / 10;
		count--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
