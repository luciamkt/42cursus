/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 16:09:56 by ltakahas          #+#    #+#             */
/*   Updated: 2020/04/23 18:42:30 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_percent(t_infos *infos)
{
	int		width;
	char	c;

	width = infos->width;
	c = (infos->zero == 1) ? '0' : ' ';
	if (infos->minus == 0 || infos->zero == 1)
	{
		while (width-- > 1)
			infos->len += ft_putchar(c);
	}
	infos->len += ft_putchar('%');
	if (infos->minus == 1)
	{
		while (width-- > 1)
			infos->len += ft_putchar(' ');
	}
	ft_reset_flags(infos);
}
