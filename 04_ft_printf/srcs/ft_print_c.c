/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 14:34:23 by ltakahas          #+#    #+#             */
/*   Updated: 2020/04/23 18:41:35 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_c(t_infos *infos, va_list args)
{
	int	c;
	int width;

	c = va_arg(args, int);
	width = infos->width;
	if (infos->minus == 0)
	{
		while (width-- > 1)
			infos->len += ft_putchar(' ');
	}
	infos->len += ft_putchar(c);
	if (infos->minus == 1)
	{
		while (width-- > 1)
			infos->len += ft_putchar(' ');
	}
	ft_reset_flags(infos);
}
