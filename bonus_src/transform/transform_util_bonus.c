/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_util_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:57:52 by kshim             #+#    #+#             */
/*   Updated: 2022/11/24 10:55:02 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_matrix_copy_44(float from_matrix[4][4], float to_matrix[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			to_matrix[i][j] = from_matrix[i][j];
			j++;
		}
		i++;
	}
	return ;
}

void	ft_matrix_copy_14(float from_matrix[4], float to_matrix[4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		to_matrix[i] = from_matrix[i];
		i++;
	}
	return ;
}

void	ft_multiply_matrix_44_44(float matrix1[4][4], float matrix2[4][4],
			float tmp[4][4])
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tmp[i][j] = 0;
			k = 0;
			while (k < 4)
			{
				tmp[i][j] += matrix1[i][k] * matrix2[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	ft_multiply_matrix_44_14(float matrix1[4][4], float matrix2[4],
			float tmp[4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		tmp[i] = 0;
		while (j < 4)
		{
			tmp[i] += matrix1[i][j] * matrix2[j];
			j++;
		}
		i++;
	}
	return ;
}

void	ft_multiply_matrix_44_scalar(float matrix[4][4], float scalar)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix[i][j] = matrix[i][j] * scalar;
			j++;
		}
		i++;
	}
	return ;
}
