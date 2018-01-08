/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_part1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:43:44 by alikhtor          #+#    #+#             */
/*   Updated: 2017/11/30 14:25:39 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_allocate_memmory(t_global *global)
{
	if (!(global->buf = (char*)malloc(sizeof(char) * (MAX_BUFF_SIZE))))
		return ;
	ft_bzero(global->buf, (MAX_BUFF_SIZE));
	global->read_bytes = (int)read(global->fd, global->buf, (MAX_BUFF_SIZE));
	if (global->read_bytes >= MAX_BUFF_SIZE)
		ft_iserror();
	if ((global->read_bytes + 1) % 21 != 0)
		ft_iserror();
	global->tetr_amount = (global->read_bytes + 1) / 21;
	if (ft_check_buf(global) == 0)
		ft_iserror();
	global->allocate = (t_tetriminos*)malloc(sizeof(t_tetriminos)
		* global->tetr_amount);
	ft_allocate_memmory_for_coords(global);
}

void	ft_allocate_memmory_for_coords(t_global *global)
{
	int i;

	i = 0;
	while (i < global->tetr_amount)
	{
		if (!(global->allocate[i].pass = (t_coordinates*)
			malloc(sizeof(t_coordinates) * 4)))
			return ;
		ft_tetriminos_record(global, i);
		i++;
		if (*(global->buf + 1) == '\0')
			return ;
		*global->buf == '\n' ? global->buf++ : ft_iserror();
	}
}

int		ft_check_buf(t_global *global)
{
	int	i;

	global->buf_hash = 0;
	global->buf_dot = 0;
	global->buf_new_l = 0;
	i = 0;
	while (global->buf[i] != '\0')
	{
		if (global->buf[i] == '#')
			global->buf_hash++;
		if (global->buf[i] == '.')
			global->buf_dot++;
		if (global->buf[i] == '\n')
			global->buf_new_l++;
		i++;
	}
	if ((global->buf_hash == (4 * global->tetr_amount)) &&
		(global->buf_dot == (12 * global->tetr_amount)) &&
		(global->buf_new_l == ((5 * global->tetr_amount) - 1)))
		return (1);
	return (0);
}

void	ft_tetriminos_record(t_global *global, int struct_num)
{
	int	i;

	i = 0;
	global->tmp = global->buf;
	if (ft_is_valid(global) == 0)
		ft_iserror();
	global->buf = global->tmp;
	ft_torec(global, &i, struct_num);
}

void	ft_torec(t_global *global, int *i, int struct_num)
{
	global->yy = 0;
	while (*global->buf != '\n' && *(global->buf + 1) != '\n' &&
		*global->buf != '\0')
	{
		global->xx = 0;
		while (*global->buf != '\n')
		{
			if (*global->buf == '#')
			{
				global->allocate[struct_num].pass[*i].x = global->xx;
				global->allocate[struct_num].pass[*i].y = global->yy;
				(*i)++;
			}
			global->xx++;
			global->buf++;
		}
		global->buf++;
		global->yy++;
	}
}
