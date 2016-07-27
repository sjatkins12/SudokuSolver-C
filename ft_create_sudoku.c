/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_sudoku.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 22:40:21 by satkins           #+#    #+#             */
/*   Updated: 2016/07/22 22:40:23 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_create_sudoku.h"

int		ft_check_box(char **t, int x, int y)
{
	int x1;
	int y1;
	int i;
	int j;

	x1 = (x - 1) % 3;
	y1 = y % 3;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if ((i != y1 && j != x1) && t[x + j - x1][y + i - y1] == t[x][y])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_check_rowcol(char **tab, int x, int y)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < 10 && j < 9)
	{
		if (tab[x][j] == tab[x][y] && y != j)
			return (0);
		j++;
		if (tab[i][y] == tab[x][y] && x != i)
			return (0);
		i++;
	}
	return (ft_check_box(tab, x, y));
}

void	ft_set_tab(char **tab, int x, int y)
{
	int flag;

	flag = 0;
	while (tab[x][y] <= '9' && flag == 0)
	{
		if (!ft_check_rowcol(tab, x, y))
			tab[x][y] = tab[x][y] + 1;
		else
			flag = 1;
	}
}

int		ft_rec(char **t, int x, int y)
{
	if (x < 10 && y < 8)
	{
		while (t[x][y] > '0' && t[x][y] <= '9' && !ft_create_sud(t, x, y + 1))
		{
			t[x][y] = t[x][y] + 1;
			ft_set_tab(t, x, y);
		}
	}
	else if (x < 9)
	{
		while (t[x][y] > '0' && t[x][y] <= '9' && !ft_create_sud(t, x + 1, 0))
		{
			t[x][y] = t[x][y] + 1;
			ft_set_tab(t, x, y);
		}
	}
	return (t[x][y] <= '9');
}

int		ft_create_sud(char **tab, int x, int y)
{
	if (tab[x][y] == '.')
	{
		tab[x][y] = '1';
		ft_set_tab(tab, x, y);
	}
	else if (x < 10 && y < 8)
	{
		if (ft_check_rowcol(tab, x, y))
			return (ft_create_sud(tab, x, y + 1));
		return (0);
	}
	else if (x < 9)
	{
		if (ft_check_rowcol(tab, x, y))
			return (ft_create_sud(tab, x + 1, 0));
		return (0);
	}
	else
		return (ft_check_rowcol(tab, x, y));
	if (tab[x][y] > '9' || !ft_check_rowcol(tab, x, y) || !ft_rec(tab, x, y))
	{
		tab[x][y] = '.';
		return (0);
	}
	return (1);
}
