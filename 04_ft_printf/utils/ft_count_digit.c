/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 17:52:38 by ltakahas          #+#    #+#             */
/*   Updated: 2020/05/09 21:34:48 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_count_digit(unsigned int nb, unsigned int base)
{
	int len;

	len = 1;
	while (nb >= base)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}

int	ft_count_digit_p(size_t p, unsigned int base)
{
	int len;

	len = 1;
	while (p >= base)
	{
		p = p / base;
		len++;
	}
	return (len);
}
