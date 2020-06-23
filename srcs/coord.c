/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 13:43:35 by stestein          #+#    #+#             */
/*   Updated: 2018/04/11 13:44:59 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_blk			*ft_update_xy(t_blk *block, int x, int y)
{
	int		xmin;
	int		ymin;
	int		i;

	xmin = 4242;
	ymin = 4242;
	i = 0;
	while (i != 4)
	{
		if (block->x[i] < xmin)
			xmin = block->x[i];
		if (block->y[i] < ymin)
			ymin = block->y[i];
		i++;
	}
	i = 0;
	while (i != 4)
	{
		block->x[i] = block->x[i] - xmin + x;
		block->y[i] = block->y[i] - ymin + y;
		i++;
	}
	return (block);
}

static t_blk	*ft_block_xy(t_blk *block, char **s)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	while (s[y])
	{
		x = 0;
		while (s[y][x])
		{
			if (s[y][x] == '#')
			{
				block->x[i] = x;
				block->y[i] = y;
				i++;
			}
			x++;
		}
		y++;
	}
	return (block);
}

t_blk			*ft_default_xy(t_blk *block)
{
	t_blk	*tmp;

	tmp = block;
	while (block->next)
	{
		block = ft_block_xy(block, ft_strsplit(block->str, '\n'));
		free(block->str);
		block = block->next;
	}
	return (tmp);
}
