/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satkins <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 22:19:11 by satkins           #+#    #+#             */
/*   Updated: 2016/07/26 16:52:32 by satkins          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_create_sudoku.h"

int		g_count = 0;

void	ft_putstr(char *c, int i, int length)
{
	char	space;
	int		n;

	space = ' ';
	n = 0;
	while (n < length)
	{
		write(1, &c[n], 1);
		if (i)
			write(1, &space, 1);
		n++;
	}
	space = '\n';
	write(1, &space, 1);
}

void	ft_create_solutions(char **temp, char **argv)
{
	int i;

	ft_count_sud(temp, 1, 0);
	if (g_count > 1 || !ft_create_sud(argv, 1, 0))
	{
		ft_putstr("Error", 0, 5);
	}
	else
	{
		i = 1;
		while (i < 10)
		{
			ft_putstr(argv[i], 1, 9);
			i++;
		}
	}
}

void	ft_print_sudoku(char **argv)
{
	int		i;
	int		j;
	char	**temp;

	i = 1;
	temp = (char **)malloc(sizeof(char **) * 11);
	while (i < 10)
	{
		j = 0;
		temp[i] = (char *)malloc(sizeof(argv[i]));
		while (argv[i][j])
		{
			temp[i][j] = argv[i][j];
			j++;
		}
		i++;
	}
	temp[i] = 0;
	ft_create_solutions(temp, argv);
	i = 0;
	while (temp[++i])
		free(temp[i]);
	free(temp);
}

int		main(int argc, char **argv)
{
	int i;
	int j;
	int flag;
	int setnumcounter;

	i = 0;
	flag = 0;
	setnumcounter = 0;
	if (argc != 10)
		flag = 1;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if ((argv[i][j] < '1' || argv[i][j] > '9') && argv[i][j] != '.')
				flag = 1;
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				setnumcounter++;
		}
		if (j != 9)
			flag = 1;
	}
	if (flag != 1 && setnumcounter > 16)
		ft_print_sudoku(argv);
	else
		ft_putstr("Error", 0, 5);
	return (0);
}
