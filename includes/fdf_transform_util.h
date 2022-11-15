/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform_util.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:47:50 by kshim             #+#    #+#             */
/*   Updated: 2022/10/28 12:20:34 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TRANSFORM_UTIL_H
# define FDF_TRANSFORM_UTIL_H

void	ft_matrix_copy_44(float from_matrix[4][4], float to_matrix[4][4]);
void	ft_matrix_copy_14(float from_matrix[4], float to_matrix[4]);
void	ft_multiply_matrix_44_44(float matrix1[4][4], float matrix2[4][4],
			float tmp[4][4]);
void	ft_multiply_matrix_44_14(float matrix1[4][4], float matrix2[4],
			float tmp[4]);
void	ft_multiply_matrix_44_scalar(float matrix[4][4], float scalar);

#endif