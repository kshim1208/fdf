/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_scene_object_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:08:20 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:58:14 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_SCENE_OBJECT_BONUS_H
# define FDF_SCENE_OBJECT_BONUS_H

void				ft_init_scene_obj_data(
						t_fdf_rend_val *rend_val, t_fdf_scene_obj **scene_obj);
void				ft_init_scene_obj_vec(t_fdf_scene_obj *scene_obj);

void				ft_set_scene_obj_pnt(
						t_fdf_rend_val *rend_val, t_fdf_pnt **pnt_2_arr);
void				ft_calc_base_xy_for_scene_object(t_fdf_rend_val *rend_val,
						int *base_x, int *base_y);
void				ft_init_world_guide(t_fdf_pnt ***world_guide,
						t_fdf_rend_val *rend_val);
void				ft_set_world_guide_pnt(t_fdf_pnt **world_guide,
						t_fdf_rend_val *rend_val);

#endif