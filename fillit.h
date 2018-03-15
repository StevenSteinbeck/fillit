/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:07:52 by stestein          #+#    #+#             */
/*   Updated: 2018/03/15 13:12:17 by stestein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"

void	ft_error(void);
char	*ft_reader(char *file);
int		input_checker(char *str); 
int		block_counter(char *str);
int		hash_counter(char *str);
int		newline_checker(char *str);
int		char_checker(char *str);
char	*shape_detector(char *str);
char	*store_input(char *str);

#endif
