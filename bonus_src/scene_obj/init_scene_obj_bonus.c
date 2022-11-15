/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_obj_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 08:30:04 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:09:38 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

#include "../../bonus_includes/fdf_rendering_value_struct_bonus.h"
#include "../../bonus_includes/fdf_scene_object_struct_bonus.h"
#include "../../bonus_includes/fdf_scene_object_bonus.h"
#include "../../bonus_includes/fdf_error_bonus.h"

#include <stdlib.h>

void	ft_init_scene_obj_data(
		t_fdf_rend_val *rend_val, t_fdf_scene_obj **scene_obj)
{
	*scene_obj = (t_fdf_scene_obj *)malloc(sizeof(t_fdf_scene_obj));
	if (*scene_obj == 0)
		ft_fdf_exit("ft_init_scene_obj_data", FAIL_MEMORY_ALLOC);
	ft_memset(*scene_obj, 0, sizeof(t_fdf_scene_obj));
	(*scene_obj)-> scene_obj_scale[0] = 1;
	(*scene_obj)-> scene_obj_scale[1] = 1;
	(*scene_obj)-> scene_obj_scale[2] = 1;
	(*scene_obj)-> scene_obj_scale[3] = 1;
	(*scene_obj)-> scene_obj_translate[0] = 0;
	(*scene_obj)-> scene_obj_translate[1] = 0;
	(*scene_obj)-> scene_obj_translate[2] = 0;
	(*scene_obj)-> scene_obj_translate[3] = 1;
	(*scene_obj)-> scene_obj_pivot[0] = 0;
	(*scene_obj)-> scene_obj_pivot[1] = 0;
	(*scene_obj)-> scene_obj_pivot[2] = (
			rend_val -> min_max_z[1] - rend_val -> min_max_z[0]) / 2;
	(*scene_obj)-> scene_obj_pivot[3] = 1;
	ft_init_scene_obj_vec(*scene_obj);
	return ;
}

void	ft_init_scene_obj_vec(t_fdf_scene_obj *scene_obj)
{
	scene_obj -> scene_obj_vec_x[0] = 1;
	scene_obj -> scene_obj_vec_x[1] = 0;
	scene_obj -> scene_obj_vec_x[2] = 0;
	scene_obj -> scene_obj_vec_x[3] = 0;
	scene_obj -> scene_obj_vec_y[0] = 0;
	scene_obj -> scene_obj_vec_y[1] = 1;
	scene_obj -> scene_obj_vec_y[2] = 0;
	scene_obj -> scene_obj_vec_y[3] = 0;
	scene_obj -> scene_obj_vec_z[0] = 0;
	scene_obj -> scene_obj_vec_z[1] = 0;
	scene_obj -> scene_obj_vec_z[2] = 1;
	scene_obj -> scene_obj_vec_z[3] = 0;
	return ;
}
