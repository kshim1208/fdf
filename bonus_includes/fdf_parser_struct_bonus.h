/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser_struct_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:35:45 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:58:00 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PARSER_STRUCT_BONUS_H
# define FDF_PARSER_STRUCT_BONUS_H

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