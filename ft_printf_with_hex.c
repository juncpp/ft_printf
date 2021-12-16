/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_with_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeredit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:21:30 by mmeredit          #+#    #+#             */
/*   Updated: 2021/11/21 18:27:43 by mmeredit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	ft_toX(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while (i != -1)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 32;
			write (1, &s[i], 1);
		}
		else
			write (1, &s[i], 1);
		i--;
	}
}

void	ft_tox(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while (i != -1)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] + 32;
			write (1, &s[i], 1);
		}
		else
			write (1, &s[i], 1);
		i--;
	}
}

int	checkHex(int x)
{
	if (x > 9)
	{
		if (x == 10)
			return (65);
		if (x == 11)
			return (66);
		if (x == 12)
			return (67);
		if (x == 13)
			return (68);
		if (x == 14)
			return (69);
		if (x == 15)
			return (70);
	}
	return (x + '0');
}

int	ft_putHexa(unsigned long num, char c)
{
	int		i;
	char	x[22];

	i = 0;
	x[0] = '\0';
	while (num >= 16)
	{
		x[i] = checkHex(num % 16);
		num = num / 16;
		i++;
	}
	x[i++] = checkHex(num);
	x[i] = '\0';
	if (c == 'p' || c == 'x')
	{
		if (c == 'p')
		{
			write (1, "0x", 2);
			i += 2;
		}
		ft_tox(x);
	}
	if (c == 'X')
		ft_toX(x);
	return (i);
}
