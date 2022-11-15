/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:35:33 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:08:38 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../mlx/mlx.h"
#include "../../libft/libft.h"

#include "../../bonus_includes/fdf_rendering_value_struct_bonus.h"
#include "../../bonus_includes/fdf_matrix_buffer_struct_bonus.h"
#include "../../bonus_includes/fdf_transform_struct_bonus.h"
#include "../../bonus_includes/fdf_scene_object_struct_bonus.h"
#include "../../bonus_includes/fdf_mlx_struct_bonus.h"
#include "../../bonus_includes/fdf_parser_struct_bonus.h"
#include "../../bonus_includes/fdf_univ_struct_bonus.h"

#include "../../bonus_includes/fdf_scene_object_bonus.h"
#include "../../bonus_includes/fdf_mlx_key_bonus.h"
#include "../../bonus_includes/fdf_mlx_bonus.h"
#include "../../bonus_includes/fdf_univ_bonus.h"
#include "../../bonus_includes/fdf_parser_bonus.h"
#include "../../bonus_includes/fdf_transform_bonus.h"
#include "../../bonus_includes/fdf_projection_bonus.h"
#include "../../bonus_includes/fdf_draw_bonus.h"
#include "../../bonus_includes/fdf_error_bonus.h"

#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_fdf_univ		*fdf_univ;
	t_fdf_mlx		mlx_data;

	if (argc < 2)
		ft_fdf_exit("main", FAIL_OPEN_FILE);
	fdf_univ = ft_init_fdf_univ();
	fdf_univ -> pnt_2_arr = ft_fdf_parse_file(argv[1], fdf_univ -> rend_val);
	ft_set_rend_val(fdf_univ -> rend_val);
	ft_mlx_set(&mlx_data,
		fdf_univ -> rend_val -> win_xy[0], fdf_univ -> rend_val -> win_xy[1]);
	ft_set_univ(fdf_univ, &mlx_data);
	ft_init_scene_obj_data(fdf_univ -> rend_val, &(fdf_univ -> scene_obj));
	ft_set_scene_obj_pnt(fdf_univ -> rend_val, fdf_univ -> pnt_2_arr);
	ft_init_world_guide(&(fdf_univ -> world_guide), fdf_univ -> rend_val);
	ft_set_world_guide_pnt(fdf_univ -> world_guide, fdf_univ -> rend_val);
	ft_init_transform_matrices_group(fdf_univ);
	ft_isometric_projection(fdf_univ -> rend_val, fdf_univ -> scene_obj,
		fdf_univ -> matrix_buf, fdf_univ -> cam_pos_tf);
	ft_set_tf_matrix(fdf_univ);
	ft_join_tranform_matrices(fdf_univ);
	ft_put_object_to_mlx_img(fdf_univ,
		fdf_univ -> rend_val -> row, fdf_univ -> rend_val -> col,
		ft_put_scene_object);
	ft_mlx_loop(fdf_univ);
	return (0);
}

t_fdf_univ	*ft_init_fdf_univ(void)
{
	t_fdf_univ	*tmp;

	tmp = (t_fdf_univ *)malloc(sizeof(t_fdf_univ));
	if (tmp == 0)
		ft_fdf_exit("ft_init_fdf_univ", FAIL_MEMORY_ALLOC);
	ft_memset(tmp, 0, sizeof(t_fdf_univ));
	tmp -> rend_val = (t_fdf_rend_val *)malloc(sizeof(t_fdf_rend_val));
	if (tmp -> rend_val == 0)
		ft_fdf_exit("ft_init_fdf_univ", FAIL_MEMORY_ALLOC);
	ft_memset(tmp -> rend_val, 0, sizeof(t_fdf_rend_val));
	return (tmp);
}

void	ft_set_univ(t_fdf_univ *fdf_univ,
		t_fdf_mlx *mlx_data)
{
	int	i;

	fdf_univ -> mlx_data = mlx_data;
	fdf_univ -> draw_var = (t_fdf_draw_var *)malloc(sizeof(t_fdf_draw_var));
	if (fdf_univ -> draw_var == 0)
		ft_fdf_exit("ft_init_fdf_univ", FAIL_MEMORY_ALLOC);
	fdf_univ -> draw_var -> z_buffer
		= (float **)malloc(sizeof(float *) * (1600 + 1));
	if (fdf_univ -> draw_var -> z_buffer == 0)
		ft_fdf_exit("ft_init_fdf_univ", FAIL_MEMORY_ALLOC);
	i = 0;
	while (i < fdf_univ -> rend_val -> win_xy[0] + 1)
	{
		fdf_univ -> draw_var -> z_buffer[i]
			= (float *)malloc(sizeof(float)
				* (fdf_univ -> rend_val -> win_xy[1] + 1));
		if (fdf_univ -> draw_var -> z_buffer[i] == 0)
			ft_fdf_exit("ft_init_fdf_univ", FAIL_MEMORY_ALLOC);
		i++;
	}
	ft_set_fdf_z_buffer_initial_value(fdf_univ -> draw_var -> z_buffer,
		fdf_univ -> rend_val -> win_xy[0], fdf_univ -> rend_val -> win_xy[1]);
	return ;
}

void	ft_set_rend_val(t_fdf_rend_val *rend_val)
{
	int	tmp;

	rend_val -> win_xy[0] = 1600;
	rend_val -> win_xy[1] = 900;
	rend_val -> btw_vertex = 10;
	if (rend_val -> row > rend_val -> col)
		tmp = rend_val -> row;
	else
		tmp = rend_val -> col;
	rend_val -> cvv_x_y_vec[0]
		= (tmp * rend_val -> btw_vertex) * rend_val -> win_xy[0] / 2000.0;
	rend_val -> cvv_x_y_vec[1]
		= (tmp * rend_val -> btw_vertex) * rend_val -> win_xy[1] / 2000.0;
	rend_val -> cvv_x_y_vec[2]
		= (tmp * rend_val -> btw_vertex) * rend_val -> win_xy[0] / 2000.0;
	rend_val -> cvv_x_y_vec[3] = 0;
	rend_val -> guide_col = (rend_val -> col * 2) + 1;
	rend_val -> guide_row = (rend_val -> row * 2) + 1;
	return ;
}
