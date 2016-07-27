/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sudoku.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 00:48:54 by satkins           #+#    #+#             */
/*   Updated: 2016/07/23 00:48:56 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CREATE_SUDOKU_H

# define FT_CREATE_SUDOKU_H

# include <unistd.h>

# include <stdlib.h>

int		ft_create_sud(char **tab, int x, int y);

int		ft_count_sud(char **tab, int x, int y);

int		ft_check_rowcol(char **tab, int x, int y);

void	ft_set_tab(char **tab, int x, int y);

extern int g_count;

#endif
