/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection_bonus.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:55:07 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:58:08 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PROJECTION_BONUS_H
# define FDF_PROJECTION_BONUS_H

void	ft_isometric_projection(t_fdf_rend_val *rend_val,
			t_fdf_scene_obj *scene_obj, t_fdf_matrix_buf *matrix_buf,
			t_tf_matrix *cam_pos_tf);

#endif