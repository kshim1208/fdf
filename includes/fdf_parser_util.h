/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser_util.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:59:43 by kshim             #+#    #+#             */
/*   Updated: 2022/10/26 10:29:35 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PARSER_UTIL_H
# define FDF_PARSER_UTIL_H

void		ft_fdf_free_pnt_2_arr(t_fdf_rend_val *rend_val,
				t_fdf_pnt **pnt_2_arr);
void		ft_fdf_del_value_ptr(void *content);

#endif