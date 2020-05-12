/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 20:00:01 by ltakahas          #+#    #+#             */
/*   Updated: 2020/05/09 21:33:18 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

int	ft_putnbr_p(size_t nb, char *base)
{
	int		mod;
	int		len;

	len = ft_count_digit_p(nb, 16);
	if (nb >= 16)
		ft_putnbr_p(nb / 16, base);
	mod = base[nb % 16];
	ft_putchar(mod);
	return (len);
}
