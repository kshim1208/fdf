/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_transform_rotate.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:53:47 by kshim             #+#    #+#             */
/*   Updated: 2022/10/28 12:25:50 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_TRANSFORM_ROTATE_H
# define FDF_TRANSFORM_ROTATE_H

void	ft_rotate_axis_x(float rotate_x[4][4], float degree);
void	ft_rotate_axis_y(float rotate_y[4][4], float degree);
void	ft_rotate_axis_z(float rotate_z[4][4], float degree);

#endif 