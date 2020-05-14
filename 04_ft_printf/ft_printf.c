/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltakahas <ltakahas@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/23 15:13:33 by ltakahas          #+#    #+#             */
/*   Updated: 2020/05/14 14:16:33 by ltakahas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init(t_infos *infos)
{
	infos->specifier = 0;
	infos->minus = 0;
	infos->zero = 0;
	infos->width = 0;
	infos->dot = 0;
	infos->precision = 0;
	infos->signal = 0;
	infos->len = 0;
}

static void	ft_print_specifier(t_infos *infos, va_list args)
{
	if (infos->specifier == 'c')
		ft_print_c(infos, args);
	if (infos->specifier == 's')
		ft_print_s(infos, args);
	if (infos->specifier == 'p')
		ft_print_p(infos, args);
	if (infos->specifier == 'd' || infos->specifier == 'i')
		ft_print_di(infos, args);
	if (infos->specifier == 'u')
		ft_print_u(infos, args);
	if (infos->specifier == 'x' || infos->specifier == 'X')
		ft_print_x(infos, args);
	if (infos->specifier == '%')
		ft_print_percent(infos);
}

static int	ft_check_flags(char *str, int i, t_infos *infos, va_list args)
{
	while (str[i])
	{
		if (!ft_strchr(ALL, str[i]) && !ft_isdigit(str[i]))
			break ;
		if (str[i] == '0' && infos->minus == 0)
			infos->zero = 1;
		if (str[i] == '*')
			ft_flag_width(infos, args);
		if (str[i] == '.')
			i = ft_flag_precision(str, i, infos, args);
		if (str[i] == '-')
			ft_flag_minus(infos);
		if (ft_isdigit(str[i]))
			i = ft_flag_digit(str, i, infos);
		if (ft_strchr(SPECIFIERS, str[i]))
		{
			infos->specifier = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

static void	ft_check_input(char *str, va_list args, t_infos *infos)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			infos->len += ft_putchar(str[i]);
		else if (str[i] == '%' && str[i + 1])
		{
			i++;
			i = ft_check_flags(str, i, infos, args);
			if (str[i] == '\0')
				return ;
			if (ft_strchr(SPECIFIERS, str[i]))
				ft_print_specifier(infos, args);
			else if (str[i])
				infos->len += ft_putchar(str[i]);
		}
		i++;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_infos		*infos;
	char		*str;
	int			len;

	len = 0;
	infos = (t_infos*)malloc(sizeof(t_infos));
	ft_init(infos);
	str = (char *)format;
	va_start(args, format);
	ft_check_input(str, args, infos);
	len = infos->len;
	va_end(args);
	free(infos);
	return (len);
}
