/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:44:35 by stestein          #+#    #+#             */
/*   Updated: 2018/03/14 20:07:41 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		block_counter(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i / 20);
}

int		hash_counter(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#')
			count++;
		i++;
	}
	return (count);
}


int		newline_checker(char *str)
{
	int i;
	int count;
	int	tmpcount;

	count = block_counter(str);
	tmpcount = count;
	i = 0; 
	while (str[i])
	{
		if (count == 1)
		{
			if (str[20] != '\0')
				return (0);
		}
		if (count > 1)
		{
			i = i + 19;
			if (str[i] != '\n')
				return (0);
			if (tmpcount > 1)
			{
				if (str[i + 1] != '\n')
				{
					return (0);
				}

				i = i + 2;
				tmpcount--;
			}
		}
		if (str[i + 1] == '\0')
			break ;
	}
	return (1);
}

int		input_checker(char *str)
{
	int	hashes;
	int	blocks;
	int temp;

	blocks = block_counter(str);
	hashes = hash_counter(str);
	temp = newline_checker(str);

	if ((newline_checker(str)) != 1)
		return (0);
	if (!temp)
		return(0);
	if ((hashes / blocks) != 4)
		return (0);
	else 
		ft_putstr("GOOD FILE\n");
	return (1);
}
