/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 14:57:08 by ltakahas          #+#    #+#             */
/*   Updated: 2020/05/09 21:54:02 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putnbr(unsigned int nb, char *base)
{
	int				mod;
	int				len;
	unsigned int	len_base;

	len_base = (unsigned int)ft_strlen(base);
	len = ft_count_digit(nb, len_base);
	if (nb >= len_base)
		ft_putnbr(nb / len_base, base);
	mod = base[nb % len_base];
	ft_putchar(mod);
	return (len);
}
