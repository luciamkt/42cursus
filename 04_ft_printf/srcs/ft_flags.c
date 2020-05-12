/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/23 15:04:14 by ltakahas          #+#    #+#             */
/*   Updated: 2020/05/09 15:40:25 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_flag_digit(char *str, int i, t_infos *infos)
{
	while (ft_isdigit(str[i]) && str[i + 1])
	{
		infos->width = (infos->width * 10) + (str[i] - '0');
		i++;
	}
	if (str[i + 1] == '\0')
		return (i);
	if (!ft_strchr(SPECIFIERS, str[i]))
		return (--i);
	return (i);
}

void	ft_flag_minus(t_infos *infos)
{
	infos->minus = 1;
	infos->zero = 0;
}

int		ft_flag_precision(char *str, int i, t_infos *infos, va_list args)
{
	int	j;

	j = i;
	j++;
	infos->dot = 1;
	if (str[j] == '*')
	{
		infos->precision = va_arg(args, int);
		j++;
	}
	while (ft_isdigit(str[j]))
	{
		infos->precision = (infos->precision * 10) + (str[j] - '0');
		j++;
	}
	if (infos->precision < 0)
		infos->dot = 0;
	return (j);
}

void	ft_flag_width(t_infos *infos, va_list args)
{
	infos->width = va_arg(args, int);
	if (infos->width < 0)
	{
		infos->minus = 1;
		infos->width *= -1;
		infos->zero = 0;
	}
}

void	ft_reset_flags(t_infos *infos)
{
	infos->specifier = 0;
	infos->minus = 0;
	infos->zero = 0;
	infos->width = 0;
	infos->dot = 0;
	infos->precision = 0;
	infos->signal = 0;
}
