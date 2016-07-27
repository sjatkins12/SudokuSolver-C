/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_solutions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 14:18:51 by satkins           #+#    #+#             */
/*   Updated: 2016/07/24 14:18:52 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_create_sudoku.h"

int		ft_recc(char **t, int x, int y)
{
	if (x < 10 && y < 8)
	{
		while (t[x][y] > '0' && t[x][y] <= '9' && !ft_count_sud(t, x, y + 1))
		{
			t[x][y] = t[x][y] + 1;
			ft_set_tab(t, x, y);
		}
	}
	else if (x < 9)
	{
		while (t[x][y] > '0' && t[x][y] <= '9' && !ft_count_sud(t, x + 1, 0))
		{
			t[x][y] = t[x][y] + 1;
			ft_set_tab(t, x, y);
		}
	}
	return (t[x][y] <= '9');
}

int		ft_check_dots(char **tab, int x, int y)
{
	if (tab[x][y] > '9' || !ft_check_rowcol(tab, x, y) || !ft_recc(tab, x, y))
	{
		tab[x][y] = '.';
		return (0);
	}
	g_count++;
	return (g_count == 2);
}

int		ft_count_sud(char **tab, int x, int y)
{
	if (tab[x][y] == '.')
	{
		tab[x][y] = '1';
		ft_set_tab(tab, x, y);
	}
	else if (x < 10 && y < 8)
	{
		if (ft_check_rowcol(tab, x, y))
			return (ft_count_sud(tab, x, y + 1));
		return (0);
	}
	else if (x < 9)
	{
		if (ft_check_rowcol(tab, x, y))
			return (ft_count_sud(tab, x + 1, 0));
		return (0);
	}
	else
	{
		if (ft_check_rowcol(tab, x, y))
			g_count++;
		return (g_count == 2);
	}
	return (ft_check_dots(tab, x, y));
}
