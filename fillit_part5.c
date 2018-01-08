/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_part5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:28:39 by alikhtor          #+#    #+#             */
/*   Updated: 2018/01/03 17:44:35 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_sort_buf_coords(t_global *global, int k)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3 - i)
		{
			if (global->allocate[k].coords[j][0] >
					global->allocate[k].coords[j + 1][0])
				ft_make_buf_coords(global, k, &j);
			j++;
		}
		i++;
	}
}

void	ft_make_buf_coords(t_global *global, int k, int *j)
{
	int temp_x;
	int temp_y;

	temp_x = global->allocate[k].coords[*j][1];
	temp_y = global->allocate[k].coords[*j][0];
	global->allocate[k].coords[*j][1] =
		global->allocate[k].coords[*j + 1][1];
	global->allocate[k].coords[*j][0] =
		global->allocate[k].coords[*j + 1][0];
	global->allocate[k].coords[*j + 1][0] = temp_y;
	global->allocate[k].coords[*j + 1][1] = temp_x;
}

int		*ft_sort_grow(int *arr, int len)
{
	int		i;
	int		j;
	int		temp;

	if (!arr)
		return (0);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int		ft_kost(int nb)
{
	int	a;
	int	b;

	a = nb;
	b = a;
	while (b > 0)
	{
		a = a / b;
		if (a == b)
			return (a);
		a = nb;
		b--;
	}
	return (0);
}

int		ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 17)
		return (ft_kost(nb));
	while (i <= nb / 4 && i <= 46340)
	{
		if (i * i == nb)
			return (i);
		else
			i++;
	}
	return (0);
}
