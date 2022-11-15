/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rendering_value_struct.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:13:45 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:16:09 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_RENDERING_VALUE_STRUCT_H
# define FDF_RENDERING_VALUE_STRUCT_H

typedef struct s_point_datas{
	float	vertex[4];
	float	vertex_tfmed[4];
	int		color;
}		t_fdf_pnt;

typedef struct s_fdf_rendering_values{
	int		row;
	int		col;
	int		row_col_num;
	int		min_max_z[2];
	int		guide_row;
	int		guide_col;
	int		win_xy[2];
	float	btw_vertex;
	float	cvv_x_y_vec[4];
	float	cam_pivot[4];
	float	cam_vec_x[4];
	float	cam_vec_y[4];
	float	cam_vec_z[4];
	float	prev_vec_z[4];
	float	cam_vec_up[4];
	float	look_pnt[4];
	float	look_pnt_cam[4];
	int		display;
	int		guide_on;
}		t_fdf_rend_val;

typedef struct s_fdf_draw_variable{
	float		**z_buffer;
	int			mid;
	int			draw_vert[2];
	int			length;
	int			height;
	int			sign;
	int			low_high;
	int			baseline;
}		t_fdf_draw_var;
#endif
