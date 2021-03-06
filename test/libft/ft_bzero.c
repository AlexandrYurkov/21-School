/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:17:10 by lfallon           #+#    #+#             */
/*   Updated: 2021/05/05 12:25:09 by lfallon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero (void *str, size_t i)
{
	unsigned char	*st;

	st = (unsigned char *) str;
	while (i != 0)
	{
		*st++ = 0;
		i--;
	}
}
