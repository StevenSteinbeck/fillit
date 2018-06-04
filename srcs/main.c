/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:06:23 by stestein          #+#    #+#             */
/*   Updated: 2018/04/09 13:37:18 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	write(1, "error\n", 6);
	exit (0);
}

char	*ft_reader(char *file)
{
	int		fd;
	int		read_stat;
	int		i;
	char	tmp[545];
	char	buffer[1];

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error();
	while ((read_stat = read(fd, buffer, 1)))
	{
		tmp[i++] = buffer[0];
		if (i > 545)
			ft_error();
	}
	tmp[i] = '\0';
	if (close(fd) == -1)
		ft_error();
	return (ft_strdup(tmp));
}

int		main(int argc, char **argv)
{
	char	*str;
	int		basic_check;
	char	*bank = NULL;
	int		blocks;
	int		i;
	char 	**store = NULL;
	int		pos;
	char	**map;
	int		length;
	int		perfect_size;
	char 	**map_start;
	char	**map_fitter = NULL;

	pos = 0;
	i = 0;
	if (argc != 2)
		ft_error();
	str = ft_reader(argv[1]);
	blocks = block_counter(str);
	basic_check = input_checker(str);
	if (basic_check != 1)
		ft_error();
	store = store_pieces(str, blocks, bank);
	length = hash_counter(str);
	perfect_size = ft_sqrt(length);
	map = mapgen(perfect_size);
	printf("\n%s\n\n", "---- map ----");
	printf("perfect_size is: %i\n\n", perfect_size);
	while (map[pos])
	{
		printf("%s\n",	map[pos]);
		pos++;
	}
	pos = 0;
	map_start = map_starter(map, store, blocks);
	
//	placed_1 = placer(updated_map);
	printf("\n%s\n\n", "---- store ----");
	while (store[pos])
	{
		printf("%s", store[pos]);
		pos++;
	}
	pos = 0;
	printf("\n%s\n\n", "---- map_start ----");
	while (map_start[pos])
	{
		printf("%s\n", map_start[pos]);
		pos++;
	}
	printf("\n%s\n\n", "----map_updated----");
	map_fitter = map_placer(map_start, store, blocks, str);
	return (0);
}
