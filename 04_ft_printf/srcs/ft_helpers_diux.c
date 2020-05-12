/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers_diux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 15:17:29 by ltakahas          #+#    #+#             */
/*   Updated: 2020/05/09 21:46:56 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**	fill with spaces and do not print '0'
*/

void	ft_print_pattern1(int digits, int width, t_infos *infos)
{
	while (width-- >= digits)
		infos->len += ft_putchar(' ');
}

/*
**	space:signal:0:nbr
**	' ' = (width - precision) or (width - digits)
**	'0' = precision - digits
*/

void	ft_print_pattern2(unsigned int nb, int digits, int width,
		t_infos *infos)
{
	int precision;
	int	tmp;

	precision = infos->precision;
	tmp = (precision >= digits) ? precision : digits;
	while (width-- > tmp)
		infos->len += ft_putchar(' ');
	if (infos->signal == -1)
		infos->len += ft_putchar('-');
	while (precision-- > digits)
		infos->len += ft_putchar('0');
	if (infos->specifier == 'x')
		infos->len += ft_putnbr(nb, HEX_LOWER);
	else if (infos->specifier == 'X')
		infos->len += ft_putnbr(nb, HEX_UPPER);
	else
		infos->len += ft_putnbr(nb, DEC);
}

/*
**	signal:0:nbr:space
**	'0' = precision - digits
**	' ' = (width - precision) or (width - digits)
*/

void	ft_print_pattern3(unsigned int nb, int digits, int width,
		t_infos *infos)
{
	int precision;
	int	tmp;

	precision = infos->precision;
	tmp = (precision >= digits) ? precision : digits;
	if (infos->signal == -1)
		infos->len += ft_putchar('-');
	while (precision-- > digits)
		infos->len += ft_putchar('0');
	if (infos->specifier == 'x')
		infos->len += ft_putnbr(nb, HEX_LOWER);
	else if (infos->specifier == 'X')
		infos->len += ft_putnbr(nb, HEX_UPPER);
	else
		infos->len += ft_putnbr(nb, DEC);
	while (width-- > tmp)
		infos->len += ft_putchar(' ');
}

/*
**	signal:0:nbr
**	'0' = width - digits
*/

void	ft_print_pattern4(unsigned int nb, int digits, int width,
		t_infos *infos)
{
	if (infos->signal == -1)
		infos->len += ft_putchar('-');
	while (width-- > digits)
		infos->len += ft_putchar('0');
	if (infos->specifier == 'x')
		infos->len += ft_putnbr(nb, HEX_LOWER);
	else if (infos->specifier == 'X')
		infos->len += ft_putnbr(nb, HEX_UPPER);
	else
		infos->len += ft_putnbr(nb, DEC);
}

/*
**	minus == 0 >>> space:signal:nbr
**	minus == 1 >>> signal:nbr:space
*/

void	ft_print_pattern5(unsigned int nb, int digits, int width,
		t_infos *infos)
{
	if (infos->minus == 0)
	{
		while (width-- > digits)
			infos->len += ft_putchar(' ');
	}
	if (infos->signal == -1)
		infos->len += ft_putchar('-');
	if (infos->specifier == 'x')
		infos->len += ft_putnbr(nb, HEX_LOWER);
	else if (infos->specifier == 'X')
		infos->len += ft_putnbr(nb, HEX_UPPER);
	else
		infos->len += ft_putnbr(nb, DEC);
	if (infos->minus == 1)
	{
		while (width-- > digits)
			infos->len += ft_putchar(' ');
	}
}
