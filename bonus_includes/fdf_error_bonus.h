/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshim <kshim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:27:51 by kshim             #+#    #+#             */
/*   Updated: 2022/11/03 11:57:10 by kshim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_ERROR_BONUS_H
# define FDF_ERROR_BONUS_H

typedef enum e_fdf_errors {
	FAIL_INPUT = 0,
	FAIL_OPEN_FILE,
	FAIL_MEMORY_ALLOC,
	FAIL_GNL,
	FAIL_INVAL_VALUE,
	FAIL_INPUT_LEN,
	FAIL_ATOI,
	FAIL_HEX_ATOI,
	FAIL_TO_LARGE_INPUT
}			t_fdf_errors;

void	ft_fdf_exit(char *func_name, int msg_index);
void	ft_px_set_error_message(char *message[]);

#endif