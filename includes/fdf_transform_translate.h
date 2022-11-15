/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform_translate.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:53:47 by kshim             #+#    #+#             */
/*   Updated: 2022/10/28 12:25:39 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TRANSFORM_TRANSLATE_H
# define FDF_TRANSFORM_TRANSLATE_H

void	ft_set_translate_matrix(float org[4], float translated[4][4]);
void	ft_set_translate_matrix_invert(float org[4], float inverted[4][4]);
void	ft_set_transpose_matrix(float org[4][4], float transposed[4][4]);

#endif 