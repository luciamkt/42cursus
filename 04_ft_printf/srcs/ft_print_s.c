/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:11:11 by ltakahas          #+#    #+#             */
/*   Updated: 2020/05/09 16:01:53 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_s(t_infos *infos, va_list args)
{
	char	*str;
	char	c;
	size_t	size;
	size_t	width;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	size = ft_strlen(str);
	width = (size_t)infos->width;
	c = (infos->zero == 1) ? '0' : ' ';
	if (infos->dot == 1 && (size_t)infos->precision < size)
		size = infos->precision;
	if (infos->minus == 0)
	{
		while (width-- > size)
			infos->len += ft_putchar(c);
	}
	infos->len += ft_putstr(str, size);
	if (infos->minus == 1)
	{
		while (width-- > size)
			infos->len += ft_putchar(' ');
	}
	ft_reset_flags(infos);
}
