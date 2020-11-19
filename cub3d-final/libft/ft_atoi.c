/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:51:16 by anassif           #+#    #+#             */
/*   Updated: 2020/11/05 00:21:00 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhitespace(int c)
{
	if (c == '\t' || c == '\r' || c == '\n' ||
		c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char const *s)
{
	long			nbr;
	long			sign;
	int				i;
	unsigned long	lon;

	lon = 9223372036854775807;
	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_iswhitespace((int)s[i]) && s[i])
		i++;
	if (s[i] == '-' || s[i] == '+')
		if (s[i++] == '-')
		{
			sign = -1;
			nbr = -nbr;
		}
	while (ft_isdigit(s[i]) && s[i])
	{
		if ((unsigned long)nbr > lon / 10 ||
			((unsigned long)nbr == lon / 10 && ((unsigned long)nbr % 10) > 7))
			return (sign > 0 ? -1 : 0);
		nbr = nbr * 10 + (s[i++] - 48);
	}
	return (nbr * sign);
}
