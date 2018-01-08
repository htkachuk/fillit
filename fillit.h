/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 19:29:51 by alikhtor          #+#    #+#             */
/*   Updated: 2018/01/03 21:42:51 by htkachuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAX_BUFF_SIZE 546

# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <string.h>

typedef	struct		s_coordinates
{
	int				x;
	int				y;
}					t_coordinates;

typedef struct		s_tetriminos
{
	int				hash;
	int				dot;
	int				new_l;
	int				coords[4][2];
	t_coordinates	*pass;
}					t_tetriminos;

typedef struct		s_global
{
	int				fd;
	int				read_bytes;
	int				xx;
	int				yy;
	int				tetr_amount;
	int				map_size;
	int				buf_hash;
	int				buf_dot;
	int				buf_new_l;
	int				valid_coords[4][2];
	int				buf_coords[4][2];
	char			*buf;
	char			*tmp;
	char			**map;
	t_tetriminos	*allocate;
	char			tetr_ch;
}					t_global;

void				ft_check_for_valid_symbols(t_global *global);
void				ft_allocate_memmory(t_global *global);
void				ft_allocate_memmory_for_coords(t_global *global);
int					ft_check_buf(t_global *global);
int					ft_is_valid(t_global *global);
void				ft_tetriminos_record(t_global *global, int struct_num);
int					ft_check_contact(t_global *global);
void				ft_make_map(int i, t_global *global);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				ft_iserror();
void				ft_putstr(char *str);
int					ft_find_valid_tetr_coords(t_global *global, int i, int *j);
int					ft_find_place_for_tetr(t_global *global, int i);
void				ft_putchar(char c);
void				ft_tetr_eraise(t_global *global);
int					ft_move_through_map(t_global *global);
int					ft_compare(t_global *global);
void				ft_print_tetr(t_global *global);
void				ft_coords(t_global *global, int k);
void				ft_sort_buf_coords(t_global *global, int k);
int					ft_sqrt(int nb);
int					ft_kost(int nb);
int					*ft_sort_grow(int *arr, int len);
void				ft_torec(t_global *global, int *i, int struct_num);
void				ft_check_for_val_coords(t_global *global, int i, int *m);
int					ft_get_coords(t_global *global, int i, int j, int m);
void				ft_make_buf_coords(t_global *global, int k, int *j);
void				ft_print_map(t_global *global);

#endif
