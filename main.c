/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:06:23 by stestein          #+#    #+#             */
/*   Updated: 2018/03/14 19:23:59 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*char	*getdata(void)
{
	char *buffer = 0;
	long length;
	char *str;
	char *name;
	int i;
	FILE * f = fopen ("tetriminos.txt", "r");

	if (f)
	{
  		fseek (f, 0, SEEK_END);
  		length = ftell (f);
  		fseek (f, 0, SEEK_SET);
  		buffer = malloc (length);
  		if (buffer)
    			fread (buffer, 1, length, f);
  		fclose (f);
	}
	return (buffer);
}*/

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
	int		result;

	if (argc != 2)
		ft_error();
	result = 0;
	str = ft_reader(argv[1]);
	result = input_checker(str);
	
	printf("%i\n", result);
	return (0);
}
