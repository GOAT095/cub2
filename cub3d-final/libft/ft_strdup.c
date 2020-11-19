/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anassif <anassif@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:51:16 by anassif           #+#    #+#             */
/*   Updated: 2020/11/08 20:02:00 by anassif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*ps;

	i = 0;
	while (s1[i])
		i++;
	if (!(ps = malloc(sizeof(*ps) * (i + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		ps[i] = s1[i];
		i++;
	}
	ps[i] = '\0';
	return (ps);
}
