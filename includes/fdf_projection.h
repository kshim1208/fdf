/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_projection.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:55:07 by kshim             #+#    #+#             */
/*   Updated: 2022/10/26 11:17:48 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_PROJECTION_H
# define FDF_PROJECTION_H

void	ft_isometric_projection(t_fdf_rend_val *rend_val,
			t_fdf_scene_obj *scene_obj, t_fdf_matrix_buf *matrix_buf,
			t_tf_matrix *cam_pos_tf);

#endif