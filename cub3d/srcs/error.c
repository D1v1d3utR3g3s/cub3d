/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <rmorice@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 10:55:37 by roxane            #+#    #+#             */
/*   Updated: 2025/02/16 15:45:32 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c3DBasic.h"

/******************************************************************************/
/*                               display_error                                */
/* -------------------------------------------------------------------------- */
/* This function writes the char * given in input preceded by "Error\n" in    */
/* STDERR                                                                     */
/* Inputs :                                                                   */
/*  - const char *error_msg : a string that specify the error message         */
/* Return :                                                                   */
/*  - None                                                                    */
/******************************************************************************/
void	display_error(const char *error_msg)
{
	write(2, "Error\n", 6);
	if (error_msg)
		write(2, error_msg, ft_strlen(error_msg));
}

/******************************************************************************/
/*                               err_clear_exit                               */
/* -------------------------------------------------------------------------- */
/* This function writes the char * given  in input <str> in STDERR, clears    */
/* all datas that need to be free and exits the program                       */
/* Inputs :                                                                   */
/*  - char *str : a string that specify the error message                     */
/*  - t_c3d_data *c3d : pointer to struct that contained datas about c3d      */
/* Return :                                                                   */
/*  - None                                                                    */
/******************************************************************************/
void	err_clear_exit(char *str, t_c3d_data *c3d)
{
	write(2, str, ft_strlen(str));
	clear_data(c3d);
	exit (1);
}
