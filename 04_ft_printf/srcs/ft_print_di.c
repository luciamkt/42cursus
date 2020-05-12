/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 15:40:53 by ltakahas          #+#    #+#             */
/*   Updated: 2020/05/03 14:23:25 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_di(t_infos *infos, va_list args)
{
	int				i;
	int				digits;
	int				width;
	int				precision;
	unsigned int	nb;

	i = va_arg(args, int);
	nb = (i < 0) ? -i : i;
	infos->signal = (i < 0) ? -1 : 1;
	digits = ft_count_digit(nb, 10);
	width = (i >= 0) ? infos->width : infos->width - 1;
	precision = infos->precision;
	if (infos->dot == 1 && precision == 0 && i == 0)
		ft_print_pattern1(digits, width, infos);
	else if (infos->dot == 1 && infos->minus == 0)
		ft_print_pattern2(nb, digits, width, infos);
	else if (infos->dot == 1 && infos->minus == 1 && width < precision)
		ft_print_pattern2(nb, digits, width, infos);
	else if (infos->dot == 1 && infos->minus == 1 && width >= precision)
		ft_print_pattern3(nb, digits, width, infos);
	else if (infos->zero == 1)
		ft_print_pattern4(nb, digits, width, infos);
	else
		ft_print_pattern5(nb, digits, width, infos);
	ft_reset_flags(infos);
}
