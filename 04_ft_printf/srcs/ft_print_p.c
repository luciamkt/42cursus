/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/27 19:01:44 by ltakahas          #+#    #+#             */
/*   Updated: 2020/05/09 21:57:05 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_p(t_infos *infos, va_list args)
{
	size_t	p;
	int		width;
	int		precision;
	int		digits;

	p = va_arg(args, size_t);
	width = infos->width;
	precision = infos->precision;
	if (width >= precision)
		digits = ft_count_digit_p(p, 16) + 2;
	else
		digits = ft_count_digit_p(p, 16);
	if (infos->dot == 1 && precision == 0)
		ft_print_pattern_p1(infos);
	else if (infos->dot == 1 && width >= precision && infos->minus == 0)
		ft_print_pattern_p2(p, digits, infos);
	else if (infos->dot == 1 && width >= precision && infos->minus == 1)
		ft_print_pattern_p3(p, digits, infos);
	else if (infos->dot == 1 || infos->zero == 1)
		ft_print_pattern_p4(p, digits, infos);
	else
		ft_print_pattern_p5(p, digits, infos);
	ft_reset_flags(infos);
}
