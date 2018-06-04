/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stestein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:07:52 by stestein          #+#    #+#             */
/*   Updated: 2018/04/10 12:42:19 by stestein         ###   ########.fr       */
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
char	*shape_detector(char *str, int i);
char	*store_input(char *str);
char	*shape_store(char *str);
char 	*copyer(char *str, char *s);
char	**store_pieces(char *str, int blocks, char *bank);
char	**mapgen(int size);
int		ft_sqrt(int n);
char	*convert(char *str, int a);
char	**map_starter(char **map, char **store, int blocks);
//map_converter converts 2d array to 1d string
//char	*map_converter(char **map);
int		best_tetri(char **str);
int		letter_change_detector(char **str, int row, int i, char letter);
int	nstrlen(char *str);
char	**map_placer(char **map_start, char **store, int blocks, char *str);
char	*advanced_placer(char **str, int row, int i, int skipper);
char 	**twod_store(char *str);
char	**twod_convert(char **str, int a);
int		first_piece_selector(char **store, int blocks, int best_case);
int		letter_detector(int i);

#endif
