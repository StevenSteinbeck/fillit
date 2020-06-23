/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 08:17:32 by stestein          #+#    #+#             */
/*   Updated: 2018/04/11 16:57:07 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static char		*ft_infest(int i, char *s)
{
	if (s[i + 1] == '#')
	{
		s[i + 1] = 'x';
		s = ft_infest(i + 1, s);
	}
	if (s[i - 1] >= 0 && s[i - 1] == '#')
	{
		s[i - 1] = 'x';
		s = ft_infest(i - 1, s);
	}
	if (i + 5 <= 20 && s[i + 5] == '#')
	{
		s[i + 5] = 'x';
		s = ft_infest(i + 5, s);
	}
	if (i - 5 >= 0 && s[i - 5] == '#')
	{
		s[i - 5] = 'x';
		s = ft_infest(i - 5, s);
	}
	if (s[i] == '#')
		s[i] = 'x';
	return (s);
}

static int		ft_count_x(char *s)
{
	int res;
	int i;
	int count_dots;

	count_dots = 0;
	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == '.')
			count_dots++;
		if (s[i] == '\n' && s[i + 1] == '\n')
		{
			if (count_dots != 12)
				ft_error();
		}
		i++;
	}
	i = -1;
	while (s[++i])
		if (s[i] == 'x')
			res++;
	return (res);
}

void			ft_supercheck(char *s)
{
	int	i;
	int c;

	c = 0;
	i = 0;
	while (s[i] && s[i] != '#')
		i++;
	s[i] = 'x';
	s = ft_infest(i, s);
	if (ft_count_x(s) != 4)
		ft_error();
	while (s[c])
	{
		if (s[c] == 'x')
			s[c] = '#';
		c++;
	}
}

int				ft_basic_check(char *reading)
{
	int dot;
	int hash;
	int endl;

	dot = 0;
	hash = 0;
	endl = 0;
	while (*reading)
	{
		if (*reading == '.')
			dot++;
		else if (*reading == '#')
			hash++;
		else if (*reading == '\n')
			endl++;
		else
			ft_error();
		reading++;
	}
	if (hash < 4)
		ft_error();
	if (hash % 4 || dot % 4 || (endl + 1) % 5)
		ft_error();
	return (hash / 4);
}
