/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:35:45 by kshim             #+#    #+#             */
/*   Updated: 2022/10/26 10:10:58 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PARSER_STRUCT_H
# define FDF_PARSER_STRUCT_H

typedef struct s_fdf_parse_data{
	t_fdf_pnt			*pnt_arr;
	t_list				*tmp_lst;
	t_list				*tmp_ptr_lst;
	char				*gotten_line;
	int					gnl_ret;
	int					prev_len;
}			t_fdf_parse_data;

typedef struct s_fdf_parse_value_lst
{
	int	val;
	int	color;
}			t_parse_value_node;

#endif