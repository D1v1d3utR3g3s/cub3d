/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmorice <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:48:00 by rmorice           #+#    #+#             */
/*   Updated: 2023/05/10 13:26:48 by rmorice          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                 ft_striteri                                */
/* -------------------------------------------------------------------------- */
/* This function applied f to every char of the string s                      */
/* Inputs :                                                                   */
/*  - char *s : the string to which we will applied f                         */
/*  - void *f : a pointer to the function applied to every char de s          */
/* Return :                                                                   */
/*  - NONE                                                                    */
/* ************************************************************************** */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if ((!s) || (!f))
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
