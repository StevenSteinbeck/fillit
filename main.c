/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:06:23 by stestein          #+#    #+#             */
/*   Updated: 2018/03/15 16:41:10 by stestein         ###   ########.fr       */
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
	char 	*shapes;
	char	*bank;

	if (argc != 2)
		ft_error();
	str = ft_reader(argv[1]);
	basic_check = input_checker(str);
	if (basic_check != 1)
		ft_error();
	shapes = shape_detector(str);
	if (!(bank = store_input(shapes)))
		ft_error();


	printf("%s\n", bank);
	return (0);
}
