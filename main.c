/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:31:32 by alikhtor          #+#    #+#             */
/*   Updated: 2018/01/03 21:46:21 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_all_is_bad(t_global *global, int *i)
{
	if (*i == 0)
	{
		global->map_size++;
		ft_make_map(global->map_size, global);
		global->tetr_ch = 'A';
		global->xx = 0;
		global->yy = 0;
	}
	else
	{
		(*i)--;
		global->tetr_ch--;
		ft_tetr_eraise(global);
		global->xx = global->allocate[*i].coords[0][1] + 1;
		global->yy = global->allocate[*i].coords[0][0];
		if (global->xx == global->map_size)
		{
			global->xx = 0;
			global->yy++;
			if (global->yy >= global->map_size)
				*i = 0;
		}
	}
}

void	ft_backtracking(t_global *global)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < global->tetr_amount)
	{
		if (ft_find_place_for_tetr(global, i))
		{
			ft_print_tetr(global);
			ft_coords(global, i);
			ft_sort_buf_coords(global, i);
			j++;
			i++;
			global->tetr_ch++;
			global->xx = 0;
			global->yy = 0;
		}
		else
			ft_all_is_bad(global, &i);
	}
}

int		main(int ac, char **av)
{
	t_global	global;
	int			i;

	i = 0;
	global.tetr_ch = 'A';
	if (ac == 2)
	{
		global.fd = open(av[1], O_RDONLY);
		ft_allocate_memmory(&global);
		i = 4 * global.tetr_amount;
		while (!ft_sqrt(i))
			i++;
		global.map_size = ft_sqrt(i);
		ft_make_map(global.map_size, &global);
		global.xx = 0;
		global.yy = 0;
		ft_backtracking(&global);
		ft_print_map(&global);
	}
	else
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	free(global.allocate);
		system("leaks fillit");
	return (0);
}
