/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:00:33 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 12:15:15 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_DRAW_H
# define FDF_DRAW_H

typedef enum e_draw_line_gradient_type{
	low,
	high
}	t_line_gradinet;

void	ft_put_object_to_mlx_img(t_fdf_univ *univ,
			int row, int col, void ft_put_func(t_fdf_univ *, int, int));
void	ft_put_world_guide(
			t_fdf_univ *univ, int row, int col);
void	ft_put_scene_object(t_fdf_univ *univ, int row, int col);
void	ft_set_world_guide_transformed(
			t_fdf_univ *univ, t_fdf_pnt *pnt);
void	ft_set_scene_object_transformed(
			t_fdf_univ *univ, t_fdf_pnt *pnt);

void	ft_draw_line(t_fdf_pnt *pnt1, t_fdf_pnt *pnt2,
			t_fdf_univ *univ);
void	ft_draw_line_low(t_fdf_pnt *pnt1, t_fdf_pnt *pnt2,
			t_fdf_univ *univ, t_fdf_draw_var *draw_var);
void	ft_draw_line_high(t_fdf_pnt *pnt1, t_fdf_pnt *pnt2,
			t_fdf_univ *univ, t_fdf_draw_var *draw_var);

void	ft_set_draw_line_variable(t_fdf_draw_var *draw_var,
			t_fdf_pnt *pnt1, t_fdf_pnt *pnt2);
void	ft_set_pixel_data_with_z_buffer(t_fdf_univ *univ,
			t_fdf_pnt *pnt1, t_fdf_pnt *pnt2, t_fdf_draw_var *draw_var);
int		ft_set_draw_line_color(int col1, int col2, float ratio);
void	ft_set_fdf_z_buffer_initial_value(
			float **z_buffer, int window_x, int window_y);
#endif