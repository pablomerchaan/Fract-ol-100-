/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paperez- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:58:04 by paperez-          #+#    #+#             */
/*   Updated: 2024/04/28 17:53:33 by paperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpointer(void *p)
{
	unsigned long long	c;
	int					count;

	c = (unsigned long long) p;
	write (1, "0x", 2);
	count = ft_puthexaux(c, 'x', 2);
	return (count);
}
