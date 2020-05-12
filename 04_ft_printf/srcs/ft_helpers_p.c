/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 15:17:29 by ltakahas          #+#    #+#             */
/*   Updated: 2020/05/09 21:37:38 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**	fill with spaces, print '0x' and do not print p
*/

void	ft_print_pattern_p1(t_infos *infos)
{
	int	width;

	width = infos->width;
	while (width-- > 2)
		infos->len += ft_putchar(' ');
	infos->len += ft_putstr("0x", 2);
}

/*
**	space:0:0x:p
**	' ' = (width - precision) or (width - digits)
**	'0' = precision - digits
*/

void	ft_print_pattern_p2(size_t p, int digits, t_infos *infos)
{
	int	width;
	int precision;
	int	tmp;

	width = infos->width;
	precision = infos->precision;
	tmp = (precision >= digits) ? precision : digits;
	while (width-- > tmp)
		infos->len += ft_putchar(' ');
	while (precision-- > digits)
		infos->len += ft_putchar('0');
	infos->len += ft_putstr("0x", 2);
	infos->len += ft_putnbr_p(p, HEX_LOWER);
}

/*
**	0:0x:p:space
**	'0' = precision - digits
**	' ' = (width - precision) or (width - digits)
*/

void	ft_print_pattern_p3(size_t p, int digits, t_infos *infos)
{
	int	width;
	int precision;
	int	tmp;

	width = infos->width;
	precision = infos->precision;
	tmp = (precision >= digits) ? precision : digits;
	while (precision-- > digits)
		infos->len += ft_putchar('0');
	infos->len += ft_putstr("0x", 2);
	infos->len += ft_putnbr_p(p, HEX_LOWER);
	while (width-- > tmp)
		infos->len += ft_putchar(' ');
}

/*
**	if dot == 1
**	0x:0:p
**	'0' = precision - digits
**
**	if zero == 1
**	0:0x:p
**	'0' = width - digits
*/

void	ft_print_pattern_p4(size_t p, int digits, t_infos *infos)
{
	int width;
	int	precision;

	width = infos->width;
	precision = infos->precision;
	if (infos->dot == 1)
	{
		infos->len += ft_putstr("0x", 2);
		while (precision-- > digits)
			infos->len += ft_putchar('0');
		infos->len += ft_putnbr_p(p, HEX_LOWER);
	}
	else if (infos->zero == 1)
	{
		while (width-- > digits)
			infos->len += ft_putchar('0');
		infos->len += ft_putstr("0x", 2);
		infos->len += ft_putnbr_p(p, HEX_LOWER);
	}
}

/*
**	minus == 0 >>> space:0x:p
**	minus == 1 >>> 0x:p:space
*/

void	ft_print_pattern_p5(size_t p, int digits, t_infos *infos)
{
	int	width;

	width = infos->width;
	if (infos->minus == 0)
	{
		while (width-- > digits)
			infos->len += ft_putchar(' ');
	}
	infos->len += ft_putstr("0x", 2);
	infos->len += ft_putnbr_p(p, HEX_LOWER);
	if (infos->minus == 1)
	{
		while (width-- > digits)
			infos->len += ft_putchar(' ');
	}
}
