/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_part3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:19:58 by alikhtor          #+#    #+#             */
/*   Updated: 2018/01/03 17:15:28 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_iserror(void)
{
	char *str;

	str = "error\n";
	ft_putstr(str);
	exit(0);
}

void	ft_print_map(t_global *global)
{
	int i;

	i = 0;
	while (global->map[i] != NULL)
	{
		ft_putstr(global->map[i]);
		ft_putchar('\n');
		i++;
	}
}

int		ft_find_place_for_tetr(t_global *global, int i)
{
	int	j;

	j = 0;
	ft_find_valid_tetr_coords(global, i, &j);
	if (!ft_move_through_map(global))
		return (0);
	while (ft_compare(global))
	{
		global->xx++;
		if (global->xx >= global->map_size)
		{
			global->xx = 0;
			global->yy++;
			if (global->map[global->yy] == NULL)
				return (0);
		}
		if (!(ft_move_through_map(global)))
			return (0);
	}
	return (1);
}

int		ft_move_through_map(t_global *global)
{
	while (global->map[global->yy] != NULL)
	{
		while (global->map[global->yy][global->xx] != '\0')
		{
			if (global->map[global->yy][global->xx] != '.')
				global->xx++;
			if (global->map[global->yy][global->xx] == '.')
				return (1);
		}
		global->xx = 0;
		global->yy++;
	}
	return (0);
}

int		ft_find_valid_tetr_coords(t_global *global, int i, int *j)
{
	int arr_x[4];
	int arr_y[4];
	int k;

	k = 0;
	while (k < 4)
	{
		arr_y[k] = global->allocate[i].pass[k].y;
		arr_x[k] = global->allocate[i].pass[k].x;
		k++;
	}
	ft_sort_grow(arr_y, 4);
	ft_sort_grow(arr_x, 4);
	while ((*j) < 4)
	{
		global->valid_coords[*j][0] = global->allocate[i].pass[*j].x - arr_x[0];
		global->valid_coords[*j][1] = global->allocate[i].pass[*j].y - arr_y[0];
		(*j)++;
	}
	return (0);
}
