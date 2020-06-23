/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:25:20 by stestein          #+#    #+#             */
/*   Updated: 2018/04/23 14:48:30 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_reset(char **tab, t_blk *block, int max)
{
	int		x;
	int		y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (tab[y][x] == block->c)
				tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (tab);
}

static char		**ft_saved(char **tab, t_blk *block, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (block->x[i] == x && block->y[i] == y)
			{
				tab[y][x] = block->c;
				i++;
			}
			x++;
		}
		tab[y][x] = '\0';
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

static int		ft_check(char **tab, t_blk *block, int max)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			if (block->x[i] == x && block->y[i] == y && tab[y][x] != '.')
				return (0);
			else if (block->x[i] == x && block->y[i] == y)
				i++;
			x++;
		}
		y++;
	}
	if (i < 4)
		return (0);
	return (1);
}

static char		**ft_solve(char **tab, t_blk *block, int max)
{
	int		x;
	int		y;
	char	**tmp;

	if (!block->next)
		return (tab);
	tmp = NULL;
	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			block = ft_update_xy(block, x, y);
			if (ft_check(tab, block, max))
				tmp = ft_solve(ft_saved(tab, block, max), block->next, max);
			if (tmp)
				return (tmp);
			tab = ft_reset(tab, block, max);
			++x;
		}
		++y;
	}
	return (NULL);
}

char			**ft_result(t_blk *block, int max)
{
	char	**tab;

	tab = NULL;
	while (!tab)
	{
		tab = ft_fill_empty(tab, max);
		tab = ft_solve(tab, block, max);
		max++;
	}
	return (tab);
}
