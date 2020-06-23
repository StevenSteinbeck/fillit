/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 09:48:04 by stestein          #+#    #+#             */
/*   Updated: 2018/04/11 13:48:22 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_fill_empty(char **tab, int max)
{
	int y;
	int x;

	y = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (max + 1))))
		return (NULL);
	while (y < max)
	{
		tab[y] = ft_strnew(max);
		x = 0;
		while (x < max)
		{
			tab[y][x] = '.';
			x++;
		}
		y++;
	}
	tab[y] = NULL;
	return (tab);
}

int			ft_max_size(t_blk *block)
{
	int		i;
	int		max;

	i = 0;
	max = 2;
	while (block->next && i++)
		block = block->next;
	while (max * max < i * 4)
		max++;
	return (max);
}
