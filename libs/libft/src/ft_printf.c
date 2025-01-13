/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erico-ke <erico-ke@42malaga.student.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:45:33 by erico-ke          #+#    #+#             */
/*   Updated: 2025/01/09 17:03:40 by erico-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inputmanager(char input, va_list args)
{
	if (input == 'c')
		return (ft_putchar_p_fd(va_arg(args, int), 1));
	else if (input == 's')
		return (ft_putstr_p_fd(va_arg(args, char *), 1));
	else if (input == 'p')
		return (ft_voidptrwrite(va_arg(args, unsigned long long)));
	else if (input == 'd')
		return (ft_putnbr_p_fd(va_arg(args, int), 1));
	else if (input == 'i')
		return (ft_putnbr_p_fd(va_arg(args, int), 1));
	else if (input == 'u')
		return (ft_putnbrfforuinput_fd(va_arg(args, int), 1));
	else if (input == 'x')
		return (ft_hexaprint(va_arg(args, unsigned int), input));
	else if (input == 'X')
		return (ft_hexaprint(va_arg(args, unsigned int), input));
	else if (input == '%')
		return (ft_putchar_p_fd('%', 1));
	return (0);
}

int	ft_printf(char const *v_inputs, ...)
{
	int		i;
	int		res;
	va_list	args;

	va_start(args, v_inputs);
	i = 0;
	res = 0;
	while (v_inputs[i])
	{
		if (v_inputs[i] == '%')
		{
			i++;
			res += ft_inputmanager(v_inputs[i], args);
		}
		else
			res += ft_putchar_p_fd(v_inputs[i], 1);
		i++;
	}
	va_end(args);
	return (res);
}
