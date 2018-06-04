/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 12:34:44 by stestein          #+#    #+#             */
/*   Updated: 2018/03/23 10:04:52 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**store_pieces(char *str, int blocks, char *bank)
{
	char	**store;
	char	*shapes;
	int		pos;
	int		i;
	int		blockcpy;
	int		a = 65;

	i = -21;
	pos = 0;
	blockcpy = blocks;
	if (!str || (!(store = (char **)malloc(sizeof(char *) * (blocks) + 1))))
		ft_error();
	while (blocks > 0)
	{
		i = i + 21;
		shapes = shape_detector(str, i);
		bank = store_input(shapes);
		bank = convert(bank, a++);
		store[pos] = bank;
		blocks--;
		pos++;
	}
	store[blockcpy] = NULL;
	return (store);
}
