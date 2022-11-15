/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:35:45 by kshim             #+#    #+#             */
/*   Updated: 2022/10/26 10:46:30 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PARSER_H
# define FDF_PARSER_H

t_fdf_pnt	**ft_fdf_parse_file(char *filename,
				t_fdf_rend_val *rend_val);
int			ft_fdf_gnl(
				t_fdf_rend_val *rend_val, t_fdf_parse_data *parse, int file_fd);
void		ft_fdf_parse_gl_to_lst(char *gl, t_list **val_list,
				t_fdf_rend_val *rend_val);
void		ft_fdf_set_gl_to_lst(char *str_start, char **str_end,
				t_list **val_list, int min_max_z[2]);
t_fdf_pnt	*ft_fdf_set_val_to_s_lst(t_list *val_list, int len);
t_fdf_pnt	**ft_fdf_set_s_lst_to_ptr_lst(t_list *ptr_arr, int size);

int			ft_atoi_fdf(char *str, char **end);
int			ft_hex_atoi_fdf(char *str, char **end);
int			ft_hex_c_to_val(char **str, int *ret);

#endif