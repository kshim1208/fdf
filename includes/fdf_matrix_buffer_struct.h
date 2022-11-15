/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_matrix_buffer_struct.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:39:33 by kshim             #+#    #+#             */
/*   Updated: 2022/10/30 10:37:38 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MATRIX_BUFFER_STRUCT_H
# define FDF_MATRIX_BUFFER_STRUCT_H

typedef struct s_fdf_matrix_buffers{
	float	matrix_buf_4x4[4][4];
	float	matrix_buf_1x4[4];
}		t_fdf_matrix_buf;

#endif