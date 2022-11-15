/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx_key_operation_struct_bonus.h               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:58:29 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:57:43 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MLX_KEY_OPERATION_STRUCT_BONUS_H
# define FDF_MLX_KEY_OPERATION_STRUCT_BONUS_H

typedef enum e_translate_direction{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	ASCEND,
	DESCEND
}			t_trans_dir;

typedef enum e_axis_to_transform{
	AXIS_X_PLUS,
	AXIS_X_MINUS,
	AXIS_Y_PLUS,
	AXIS_Y_MINUS,
	AXIS_Z_PLUS,
	AXIS_Z_MINUS
}			t_tf_axis;

#endif