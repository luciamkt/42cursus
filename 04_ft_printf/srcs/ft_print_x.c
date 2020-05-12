/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 14:55:07 by ltakahas          #+#    #+#             */
/*   Updated: 2020/05/03 14:24:21 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_x(t_infos *infos, va_list args)
{
	unsigned int	ui;
	int				digits;
	int				width;
	int				precision;

	ui = va_arg(args, unsigned int);
	digits = ft_count_digit(ui, 16);
	width = infos->width;
	precision = infos->precision;
	if (infos->dot == 1 && precision == 0 && ui == 0)
		ft_print_pattern1(digits, width, infos);
	else if (infos->dot == 1 && infos->minus == 0)
		ft_print_pattern2(ui, digits, width, infos);
	else if (infos->dot == 1 && infos->minus == 1 && width < precision)
		ft_print_pattern2(ui, digits, width, infos);
	else if (infos->dot == 1 && infos->minus == 1 && width >= precision)
		ft_print_pattern3(ui, digits, width, infos);
	else if (infos->zero == 1)
		ft_print_pattern4(ui, digits, width, infos);
	else
		ft_print_pattern5(ui, digits, width, infos);
	ft_reset_flags(infos);
}
