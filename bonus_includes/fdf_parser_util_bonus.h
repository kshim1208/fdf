/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser_util_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:59:43 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:58:03 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PARSER_UTIL_BONUS_H
# define FDF_PARSER_UTIL_BONUS_H

void		ft_fdf_free_pnt_2_arr(t_fdf_rend_val *rend_val,
				t_fdf_pnt **pnt_2_arr);
void		ft_fdf_del_value_ptr(void *content);

#endif