/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scene_object_struct_bonus.h                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:28:20 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:58:17 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_SCENE_OBJECT_STRUCT_BONUS_H
# define FDF_SCENE_OBJECT_STRUCT_BONUS_H

typedef struct s_scene_object_datas{
	float		scene_obj_pivot[4];
	float		scene_obj_scale[4];
	float		scene_obj_translate[4];
	float		scene_obj_vec_x[4];
	float		scene_obj_vec_y[4];
	float		scene_obj_vec_z[4];
}			t_fdf_scene_obj;

#endif