/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_updater.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:13:59 by stestein          #+#    #+#             */
/*   Updated: 2018/04/10 13:01:07 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"				
 
int	first_piece_selector(char **store, int blocks, int best_case)
{	
	int	tetri = 0;
	int	i = 0;
	int	newline_count = 0;
	
	while (store[tetri] != 0)
	{	
		newline_count = 0;
		i = 0;
		while (store[tetri][i])
		{
			if (store[tetri][i] == '\n')
				newline_count++;
			i++;
		}
		if (newline_count == best_case)
			return (tetri);
		tetri++;
	}
	if (blocks - 1 == tetri)
		first_piece_selector(store, blocks, best_case - 1);
	return (0);
}

char	**map_starter(char **map, char **store, int blocks)
{
	int 	row = 0;
	int 	i = 0;
	int 	j = 0;
	int	best_case = 4;
	int	best_tetri = first_piece_selector(store, blocks, best_case);

	printf("\nFirst piece & piece to be skipped later: %i\n", best_tetri);
	while (store[best_tetri][j] != '\0')
	{
		i = 0;
		while (store[best_tetri][j] == '.')
		{
			j++;
			i++;
		}
		while ((store[best_tetri][j] != map[row][i]) && store[best_tetri][j] != '\n')
		{
			map[row][i] = store[best_tetri][j];
			i++;
			j++;
		}
		j++;
		row++;
	}
	return (map);
}

char	**map_placer(char **map_start, char **store, int blocks, char *str)
{
	int row = 0;
	int	rowSTART = 0;
	int i = 0;
	int x = 0;
	int best_case = 4;
	int skip_this_tetri = first_piece_selector(store, blocks, best_case);
	char *placed_tetris = NULL;
//	char **new_map = NULL;
	char *tetri_value = NULL;
	int	icpy = 0;
	char **new_piece = NULL;
	int letter_tracker = 0;
//	int	skipper = 0;
	int z = 0;
	int skipper = 0;
	
	placed_tetris = (char *)malloc(sizeof(char) * 27);
	placed_tetris[x] = skip_this_tetri + '0';
	while (nstrlen(placed_tetris) != blocks - 1)
	{
		x++;
		while (map_start[row][i] >= 'A' && map_start[row][i] <= 'Z')
		{
			i++;
			if (map_start[row][i] == '\0')
			{
				row++;
				i = 0;
			}
		}
		if (map_start[row][i] == '.')
		{
			icpy = i;
			tetri_value = advanced_placer(map_start, row, i, skipper);
			if (tetri_value != 0)
			{
				i = 0;
				while (tetri_value != shape_detector(str, i))
				{
					i = i + 21;
					if (i > 546)
					{
						i = 0;
						skipper++;
						tetri_value = advanced_placer(map_start, row, i, skipper);
					}
				}
				letter_tracker = letter_detector(i);
				placed_tetris[x] = letter_tracker + 1;
				if (tetri_value == shape_detector(str, i))
				{
					new_piece = twod_store(tetri_value);
					new_piece = twod_convert(new_piece, ('A' + letter_tracker + 1));
					while (new_piece[rowSTART] != 0)
					{
						i = 0;
						z = icpy;
						while (new_piece[rowSTART][i] != '\0')
						{
							map_start[row][z] = new_piece[rowSTART][i];
							i++;
							z++;
						}
						row++;
						rowSTART++;
					}
				}
			}
			if (tetri_value == 0)
				i++;
		}
		i = 0;
		row = 0;
		while (map_start[row])
		{
			printf("%s\n", map_start[row]);
			row++;
		}
		i = 0;
		row = 0;
	}
	return (map_start);
}
			

int	letter_detector(int i)
{
	int c = 0;

	c = i / 21;
	c = c - 1;
	return (c);
}


int	nstrlen(char *str)
{
	int l = 0;

	while (str[l] != '\n' && str[l] != '\0')
		l++;
	return (l);
}	
