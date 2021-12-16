/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_with_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:22:59 by mmeredit          #+#    #+#             */
/*   Updated: 2021/11/21 18:28:28 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_putCount(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putCountNbr(int n, int j)
{
	char	x[10];
	int		i;

	i = 0;
	x[0] = '\0';
	if (n < 0)
	{
		j += ft_putCount('-');
		x[i++] = (-((n) % 10) + '0');
		n = -(n / 10);
	}
	while (n != 0)
	{
		x[i] = ((n % 10) + '0');
		n = n / 10;
		i++;
	}
	if (i == 0)
		return (j += ft_putCount('0'));
	while (i > 0)
		j += ft_putCount(x[--i]);
	return (j);
}

int	ft_putCountUnbr(unsigned int n)
{
	char	x[10];
	int		i;
	int		j;

	j = 0;
	i = 0;
	x[0] = '\0';
	while (n != 0)
	{
		x[i] = ((n % 10) + '0');
		n = n / 10;
		i++;
	}
	if (i == 0)
		return (j += ft_putCount('0'));
	while (i > 0)
		j += ft_putCount(x[--i]);
	return (j);
}

int	ft_putCountStr(char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		return (i);
	}
	else
		write(1, "(null)", 6);
	return (6);
}

int	ft_putS(va_list ptr, char *inp)
{
	int	i;

	i = 0;
	while (*inp)
	{
		inp = ft_skip(inp, &i);
		if (*inp == '%')
		{
			inp++;
			inp = ft_percent(ptr, inp, &i);
		}
	}
	return (i);
}
