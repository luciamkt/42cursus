/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/30 14:18:08 by ltakahas          #+#    #+#             */
/*   Updated: 2020/03/30 15:12:35 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putstr(char *str, size_t len)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] && i < len)
	{
		count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
