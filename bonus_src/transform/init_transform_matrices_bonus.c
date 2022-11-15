/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_transform_matrices_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:40:17 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:09:22 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

#include "../../bonus_includes/fdf_transform_struct_bonus.h"
#include "../../bonus_includes/fdf_matrix_buffer_struct_bonus.h"
#include "../../bonus_includes/fdf_scene_object_struct_bonus.h"
#include "../../bonus_includes/fdf_mlx_struct_bonus.h"
#include "../../bonus_includes/fdf_rendering_value_struct_bonus.h"
#include "../../bonus_includes/fdf_univ_struct_bonus.h"

#include "../../bonus_includes/fdf_transform_bonus.h"
#include "../../bonus_includes/fdf_error_bonus.h"

#include <stdlib.h>

void	ft_init_transform_matrices_group(t_fdf_univ *univ)
{
	univ -> tf_all_matrices = (t_tf_all_group *)malloc(sizeof(t_tf_all_group));
	univ -> tf_matrices = (t_tf_data_group *)malloc(sizeof(t_tf_data_group));
	if (univ -> tf_all_matrices == 0 || univ -> tf_matrices == 0)
		ft_fdf_exit("ft_init_transform_matrices_group", FAIL_MEMORY_ALLOC);
	ft_memset(univ -> tf_all_matrices, 0, sizeof(t_tf_all_group));
	ft_memset(univ -> tf_matrices, 0, sizeof(t_tf_data_group));
	univ -> cam_pos_tf = ft_allocate_transform_matrix();
	univ -> tf_matrices -> obj_tf = ft_allocate_transform_matrix();
	univ -> tf_matrices -> cam_tf = ft_allocate_transform_matrix();
	univ -> tf_matrices -> prj_tf_data = ft_init_projection_transform_matrix();
	univ -> matrix_buf = ft_allocate_matrix_buffer();
	return ;
}

t_tf_matrix	*ft_allocate_transform_matrix(void)
{
	t_tf_matrix	*tmp;

	tmp = (t_tf_matrix *)malloc(sizeof(t_tf_matrix));
	if (tmp == 0)
		ft_fdf_exit("ft_allocate_transform_matrix", FAIL_MEMORY_ALLOC);
	ft_memset(tmp, 0, sizeof(t_tf_matrix));
	tmp -> scale[0][0] = 1;
	tmp -> scale[1][1] = 1;
	tmp -> scale[2][2] = 1;
	tmp -> scale[3][3] = 1;
	tmp -> rotate[0][0] = 1;
	tmp -> rotate[1][1] = 1;
	tmp -> rotate[2][2] = 1;
	tmp -> rotate[3][3] = 1;
	tmp -> translate[0][0] = 1;
	tmp -> translate[1][1] = 1;
	tmp -> translate[2][2] = 1;
	tmp -> translate[3][3] = 1;
	tmp -> translate[0][3] = 1;
	tmp -> translate[1][3] = 1;
	tmp -> translate[2][3] = 1;
	tmp -> translate[3][3] = 1;
	return (tmp);
}

t_fdf_matrix_buf	*ft_allocate_matrix_buffer(void)
{
	t_fdf_matrix_buf	*tmp;

	tmp = (t_fdf_matrix_buf *)malloc(sizeof(t_fdf_matrix_buf));
	if (tmp == 0)
		ft_fdf_exit("ft_allocate_matrix_buffer", FAIL_MEMORY_ALLOC);
	ft_memset(tmp, 0, sizeof(t_fdf_matrix_buf));
	return (tmp);
}

t_project_tf_data	*ft_init_projection_transform_matrix(void)
{
	t_project_tf_data	*tmp;

	tmp = (t_project_tf_data *)malloc(sizeof(t_project_tf_data));
	if (tmp == 0)
		ft_fdf_exit("ft_init_projection_transform_matrix", FAIL_MEMORY_ALLOC);
	ft_memset(tmp, 0, sizeof(t_project_tf_data));
	tmp -> orth_scale = 1.0;
	tmp -> pers_scale = 1.0;
	return (tmp);
}
