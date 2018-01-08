/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_part6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 18:33:12 by alikhtor          #+#    #+#             */
/*   Updated: 2018/01/03 18:33:27 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_is_valid(t_global *global)
{
	char	*temp;

	global->allocate->hash = 0;
	global->allocate->dot = 0;
	global->allocate->new_l = 0;
	temp = global->buf;
	ft_check_for_valid_symbols(global);
	if (!(global->allocate->hash == 4 && global->allocate->dot == 12 &&
		global->allocate->new_l == 4))
		return (0);
	global->buf = temp;
	if (ft_check_contact(global) != 1)
		return (0);
	return (1);
}

void	ft_check_for_valid_symbols(t_global *global)
{
	int i;

	i = 0;
	while ((*global->buf == '#' || *global->buf == '.' ||
		*global->buf == '\n') && i != 20)
	{
		if (*global->buf == '#')
			global->allocate->hash++;
		if (*global->buf == '.')
			global->allocate->dot++;
		if (*global->buf == '\n')
			global->allocate->new_l++;
		global->buf++;
		i++;
	}
}

int		ft_check_contact(t_global *global)
{
	int	contacts;
	int i;

	i = 0;
	contacts = 0;
	while ((*global->buf == '#' || *global->buf == '.' ||
		*global->buf == '\n') && i != 20)
	{
		if (*global->buf == '#')
		{
			if (*(global->buf + 1) == '#' && i < 20)
				contacts++;
			if (*(global->buf - 1) == '#' && i > 0)
				contacts++;
			if (*(global->buf + 5) == '#' && i < 15)
				contacts++;
			if (*(global->buf - 5) == '#' && i > 4)
				contacts++;
		}
		global->buf++;
		i++;
	}
	if (contacts == 6 || contacts == 8)
		return (1);
	return (0);
}

void	ft_tetr_eraise(t_global *global)
{
	int i;
	int j;

	i = 0;
	while (global->map[i] != NULL)
	{
		j = 0;
		while (global->map[i][j] != '\0')
		{
			if (global->map[i][j] == global->tetr_ch)
				global->map[i][j] = '.';
			j++;
		}
		i++;
	}
}
