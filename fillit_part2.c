/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_part2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:11:40 by alikhtor          #+#    #+#             */
/*   Updated: 2018/01/03 18:27:16 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_make_map(int i, t_global *global)
{
	int j;

	if (!(global->map = (char**)malloc(sizeof(char*) * (i + 1))))
		return ;
	global->map[i] = NULL;
	j = 0;
	while (j < i)
	{
		if (!(global->map[j] = (char*)malloc(sizeof(char) * (i + 1))))
			return ;
		global->map[j][i] = '\0';
		j++;
	}
	j = 0;
	while (global->map[j] != NULL)
	{
		ft_memset(global->map[j], '.', (size_t)i);
		j++;
	}
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	unsigned char	ch;

	ch = (unsigned char)c;
	temp = (unsigned char*)b;
	while (len > 0)
	{
		*temp = ch;
		temp++;
		len--;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char*)s;
	i = 0;
	while (n > 0)
	{
		temp[i++] = '\0';
		n--;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
