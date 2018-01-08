/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_part4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:22:37 by alikhtor          #+#    #+#             */
/*   Updated: 2018/01/03 18:22:27 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_compare(t_global *global)
{
	int i;
	int j;
	int m;

	m = 0;
	i = 0;
	j = 0;
	while (i < 4)
	{
		global->buf_coords[i][1] = global->valid_coords[i][1];
		global->buf_coords[i][0] = global->valid_coords[i][0];
		ft_check_for_val_coords(global, i, &m);
		global->valid_coords[i][0] = global->valid_coords[i][0] + global->xx;
		global->valid_coords[i][1] = global->valid_coords[i][1] + global->yy;
		if (global->valid_coords[i][1] >= global->map_size ||
				global->valid_coords[i][0] >= global->map_size)
			return (ft_get_coords(global, i, j, m));
		if (global->map[global->valid_coords[i][1]]
				[global->valid_coords[i][0]] == '.')
			i++;
		else
			return (ft_get_coords(global, i, j, m));
	}
	return (0);
}

void	ft_check_for_val_coords(t_global *global, int i, int *m)
{
	if (global->valid_coords[0][0] > 1 && i == 0 && global->xx > 1)
	{
		global->xx = global->xx - 2;
		*m = 2;
	}
	if (global->valid_coords[0][0] > 0 && i == 0 && global->xx > 0 && *m != 2)
	{
		global->xx--;
		*m = 1;
	}
}

int		ft_get_coords(t_global *global, int i, int j, int m)
{
	while (j <= i)
	{
		global->valid_coords[j][1] = global->buf_coords[j][1];
		global->valid_coords[j][0] = global->buf_coords[j][0];
		j++;
	}
	if (m == 1)
		global->xx++;
	if (m == 2)
		global->xx = global->xx + 2;
	return (1);
}

void	ft_print_tetr(t_global *global)
{
	int i;

	i = 0;
	while (i < 4)
	{
		global->map[global->valid_coords[i][1]]
			[global->valid_coords[i][0]] = global->tetr_ch;
		i++;
	}
}

void	ft_coords(t_global *global, int k)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (global->map[y] != NULL)
	{
		x = 0;
		while (global->map[y][x] != '\0')
		{
			if (global->map[y][x] == global->tetr_ch)
			{
				global->allocate[k].coords[i][0] = y;
				global->allocate[k].coords[i][1] = x;
				i++;
			}
			x++;
		}
		y++;
	}
}
