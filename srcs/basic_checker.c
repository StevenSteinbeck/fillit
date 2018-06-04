/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 13:44:35 by stestein          #+#    #+#             */
/*   Updated: 2018/03/20 11:21:10 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		block_counter(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i == 20)
		return (1);
	if (i < 21)
		ft_error();
	return ((i / 21) + 1);
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
					return (0);
				i = i + 1;
				tmpcount--;
			}
		}
		if (str[i + 1] == '\0')
			break ;
		i++;
	}
	return (1);
}

int		char_checker(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (0);
		if (str[i + 1] == '\0')
			break ;
		i++;
	}
	return (1);
}
	
int		input_checker(char *str)
{
	int	hashes;
	int	blocks;
	int newline;
	int charcheck;

	charcheck = char_checker(str);
	blocks = block_counter(str);
	hashes = hash_counter(str);
	newline = newline_checker(str);

	if (newline != 1)
		return (0);
	if ((hashes / blocks) != 4)
		return (0);
	if (charcheck != 1)
		return (0);
	return (1);
}
