/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:32:52 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 08:50:43 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/get_next_line.h"

#include "../../includes/fdf_rendering_value_struct.h"
#include "../../includes/fdf_parser_struct.h"
#include "../../includes/fdf_parser.h"
#include "../../includes/fdf_error.h"
#include "../../includes/fdf_parser_util.h"

#include <fcntl.h>
#include <unistd.h>

t_fdf_pnt	**ft_fdf_parse_file(char *filename,
		t_fdf_rend_val *rend_val)
{
	t_fdf_parse_data	parse;
	t_fdf_pnt			**pnt_2_arr;
	int					file_fd;

	ft_memset(&parse, 0, sizeof(t_fdf_parse_data));
	file_fd = open(filename, O_RDONLY);
	if (file_fd < 0)
		ft_fdf_exit("ft_fdf_parse_file", FAIL_OPEN_FILE);
	parse.prev_len = -1;
	while (1)
	{
		if (ft_fdf_gnl(rend_val, &parse, file_fd) == 0)
			break ;
	}
	close(file_fd);
	pnt_2_arr = ft_fdf_set_s_lst_to_ptr_lst(
			parse.tmp_ptr_lst, rend_val -> row);
	ft_lstclear(&(parse.tmp_ptr_lst), 0);
	return (pnt_2_arr);
}

int	ft_fdf_gnl(
		t_fdf_rend_val *rend_val, t_fdf_parse_data *parse, int file_fd)
{
	parse -> tmp_lst = 0;
	parse -> gotten_line = 0;
	parse -> gnl_ret = get_next_line(file_fd, &(parse -> gotten_line));
	if (parse -> gotten_line == 0 && parse -> gnl_ret < 0)
		ft_fdf_exit("ft_fdf_gnl", FAIL_GNL);
	else if (parse -> gotten_line == 0 && parse -> gnl_ret == 0)
		return (0);
	(rend_val -> row)++;
	if (rend_val -> row > 1000)
		ft_fdf_exit("ft_fdf_gnl", FAIL_INPUT_LEN);
	ft_fdf_parse_gl_to_lst(parse -> gotten_line, &(parse -> tmp_lst),
		rend_val);
	if (parse -> prev_len == -1)
		parse -> prev_len = rend_val -> col;
	if (parse -> prev_len != rend_val -> col)
		ft_fdf_exit("ft_fdf_gnl", FAIL_INPUT_LEN);
	parse -> pnt_arr = ft_fdf_set_val_to_s_lst(
			parse -> tmp_lst, rend_val -> col);
	ft_lstclear(&(parse -> tmp_lst), &(ft_fdf_del_value_ptr));
	parse -> tmp_lst = ft_lstnew(parse -> pnt_arr);
	ft_lstadd_back(&(parse -> tmp_ptr_lst), parse -> tmp_lst);
	free(parse -> gotten_line);
	return (1);
}

void	ft_fdf_parse_gl_to_lst(char *gl, t_list **val_list,
	t_fdf_rend_val *rend_val)
{
	char	*now;
	char	*str_start;

	now = gl;
	rend_val -> col = 0;
	while (*now != '\0' && *now != '\n')
	{
		if (ft_isdigit(*now) == 0 && ft_issign(*now) == 0
			&& ft_isspace(*now) == 0 && *now != ',')
			ft_fdf_exit("ft_fdf_parse_gl_to_lst", FAIL_INVAL_VALUE);
		if (ft_isspace(*now) == 0)
		{
			str_start = now;
			ft_fdf_set_gl_to_lst(str_start, &now,
				val_list, rend_val -> min_max_z);
			(rend_val -> col)++;
			if (rend_val -> col > 1000)
				ft_fdf_exit("ft_fdf_parse_gl_to_lst", FAIL_INPUT_LEN);
			if (*now == '\0' || *now == '\n')
				return ;
		}
		now++;
	}
	return ;
}

t_fdf_pnt	*ft_fdf_set_val_to_s_lst(t_list *val_list, int len)
{
	t_fdf_pnt	*struct_arr;
	int			i;

	struct_arr = (t_fdf_pnt *)malloc(sizeof(t_fdf_pnt) * len);
	if (struct_arr == 0)
		ft_fdf_exit("ft_fdf_set_val_to_s_lst", FAIL_MEMORY_ALLOC);
	ft_memset(struct_arr, 0, sizeof(t_fdf_pnt) * len);
	i = 0;
	while (i < len)
	{
		struct_arr[i].vertex[2] = (
				(t_parse_value_node *)(val_list -> content))-> val;
		struct_arr[i].vertex[3] = 1;
		struct_arr[i].color = (
				(t_parse_value_node *)(val_list -> content))-> color;
		val_list = val_list -> next;
		i++;
	}
	return (struct_arr);
}

t_fdf_pnt	**ft_fdf_set_s_lst_to_ptr_lst(t_list *ptr_arr, int size)
{
	t_fdf_pnt	**pnt_2_arr;
	int			i;

	pnt_2_arr = (t_fdf_pnt **)malloc(
			sizeof(t_fdf_pnt *) * size);
	if (pnt_2_arr == 0)
		ft_fdf_exit("ft_fdf_set_s_lst_to_ptr_lst", FAIL_MEMORY_ALLOC);
	i = 0;
	while (i < size)
	{
		pnt_2_arr[i] = (t_fdf_pnt *)(ptr_arr -> content);
		ptr_arr = ptr_arr -> next;
		i++;
	}
	return (pnt_2_arr);
}
